/*
    Copyright (c) 2023 The '6PM' Crew <https://github.com/6pm-crew>

    Permission is hereby granted, free of charge, to any person obtaining a 
    copyof this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation 
    the rights to use, copy, modify, merge, publish, distribute, sublicense, 
    and/or sell copies of the Software, and to permit persons to whom the 
    Software is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included 
    in all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
    DEALINGS IN THE SOFTWARE.
*/

/* Includes ================================================================ */

#include "yeotsh.h"

/* Private Function Prototypes ============================================= */

/* 셸을 초기화한다. */
static void init_shell(void);

/* 명령 줄에서 명령 인수 (argument)를 읽고, 작업을 생성한다. */
static void parse_and_execute(char *buffer);

/* Public Variables ======================================================== */

/* POSIX 운영 체제에서 제공하는 환경 변수 목록. */
extern char **environ;

/* Private Variables ======================================================= */

/* 셸의 프롬프트 메시지 (prompt message)를 나타내는 문자열. */
static char *prompt = YS_NON_ROOT_PROMPT;

/* Public Functions ======================================================== */

int main(void) {
    init_shell();

    for (;;) {
        YS_PRINTF("%s", prompt);

        char line[YS_MAX_LINE_LENGTH];

        if (fgets(line, sizeof line, stdin) == NULL) {
            // "Ctrl + D" (`EOF`) 입력을 처리한다.
            if (feof(stdin)) putchar('\n'), exit(EXIT_SUCCESS);

            YS_PANIC("fgets() failed");
        }

        char *buffer = line;

        // 명령 줄의 맨 앞에 위치한 공백 문자들과 맨 뒤의 개행 문자를 제거한다.
        for (buffer[strcspn(buffer, "\n")] = '\0';
             (buffer != NULL) && (*buffer == ' ');
             buffer++)
            ;

        parse_and_execute(buffer);
    }

    return 0;
}

/* Private Functions ======================================================= */

/* 셸을 초기화한다. */
static void init_shell(void) {
    // 사용자가 루트 권한을 가지고 있는지 확인한다.
    if (!geteuid()) prompt = YS_ROOT_PROMPT;
}

/* 명령 줄에서 명령 인수 (argument)를 읽고, 작업을 생성한다. */
static void parse_and_execute(char *buffer) {
    if (buffer == NULL || *buffer == '\0') return;

    char *argv[(YS_MAX_LINE_LENGTH >> 1) + 1];

    int argc = 0;

    // 공백 문자를 기준으로 명령 줄을 한 단어씩 자른다.
    for (;;) {
        argv[argc++] = buffer;

        // 더 이상 공백 문자를 찾을 수 없을 때까지 반복한다.
        if ((buffer = strchr(buffer, ' ')) == NULL) break;

        for (*buffer = '\0', ++buffer; (buffer != NULL) && (*buffer == ' ');
             buffer++)
            ;
    }

    // 명령 줄의 마지막 문자가 '&'일 경우, 작업을 백그라운드로 실행한다.
    bool run_in_bg = (*argv[argc - 1] == '&');

    /*
        "The `argv` and `environ` arrays are each terminated by a null pointer."
        - https://pubs.opengroup.org/onlinepubs/9699919799/functions/exec.html
    */

    argv[(argc -= run_in_bg)] = NULL;

    struct builtin_command bc = { .func = NULL };

    // 빌트인 명령어를 실행한다.
    if (is_builtin_command((const char **) argv, &bc)) {
        if (bc.func != NULL) bc.func(argc, argv);

        return;
    }

    pid_t pid;

    // 자식 프로세스를 생성한다.
    if ((pid = fork()) < 0) {
        YS_PANIC("fork() failed");
    } else if (pid == 0) {
        // 자식 프로세스를 새로운 프로세스 그룹에 추가한다.
        setpgid(0, 0);

        // TODO: 시그널 핸들러 구현하기
        if (execvp(argv[0], argv) < 0)
            YS_PRINTF("%s: command not found\n", argv[0]), exit(0);
    }

    /*
        자식 프로세스의 그룹이 생성되기 전에 셸 프로세스가 먼저 실행되는
        "경쟁 상태" (race condition)가 발생하지 않도록 한다.
    */
    setpgid(0, 0);

    if (!run_in_bg) {
        // TODO: ...
    } else {
        // TODO: ...
    }

    // TODO: ...
    usleep(100000);
}
