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

#include <errno.h>
#include <signal.h>

#include <sys/types.h>
#include <unistd.h>

#include "yeotsh.h"

/* Private Function Prototypes ============================================= */

/* 작업을 백그라운드에서 실행한다. */
static void builtin_bg(int argc, char *argv[]);

/* 현재 디렉토리 (working directory)를 변경한다. */
static void builtin_cd(int argc, char *argv[]);

/* 셸 프로세스를 종료한다. */
static void builtin_exit(int argc, char *argv[]);

/* 작업을 포그라운드에서 실행한다. */
static void builtin_fg(int argc, char *argv[]);

/* 빌트인 명령어 목록을 출력한다. */
static void builtin_help(int argc, char *argv[]);

/* 작업 목록을 출력한다. */
static void builtin_jobs(int argc, char *argv[]);

/* 작업에 시그널을 보낸다. */
static void builtin_kill(int argc, char *argv[]);

/* 현재 디렉토리 (working directory)를 출력한다. */
static void builtin_pwd(int argc, char *argv[]);

/* 작업 또는 프로세스가 종료될 때까지 기다린다. */
static void builtin_wait(int argc, char *argv[]);

/* Constants =============================================================== */

/* 빌트인 명령어의 실행 정보가 저장되어 있는 배열. */
static const struct builtin_command builtin_commands[] = {
    { "bg", builtin_bg },     { "cd", builtin_cd },
    { "exit", builtin_exit }, { "fg", builtin_fg },
    { "help", builtin_help }, { "jobs", builtin_jobs },
    { "kill", builtin_kill }, { "pwd", builtin_pwd },
    { "wait", builtin_wait }, { NULL, NULL }
};

/* Public Functions ======================================================== */

/* `argv[0]`이 빌트인 명령어인지 확인한다. */
bool is_builtin_command(const char *argv[], struct builtin_command *bc) {
    if (argv == NULL) return false;

    // TODO: 빌트인 명령어의 개수가 많다면 `bsearch()` 함수를 이용해도 좋을 듯!
    for (int i = 0; builtin_commands[i].name != NULL; i++)
        if (strcmp(argv[0], builtin_commands[i].name) == 0) {
            if (bc != NULL) *bc = builtin_commands[i];

            return true;
        }

    return false;
}

/* Private Functions ======================================================= */

/* 작업을 백그라운드에서 실행한다. */
static void builtin_bg(int argc, char *argv[]) {
    // TODO: ...
}

/* 현재 디렉토리 (working directory)를 변경한다. */
static void builtin_cd(int argc, char *argv[]) {
    char *path = NULL;

    if (argc <= 1) {
        // `HOME` 환경 변수가 정의되어 있지 않다면, 아무 것도 하지 않는다.
        if ((path = getenv("HOME")) == NULL) return;
    }

    path = argv[1];

    if (chdir(path) < 0) {
        switch (errno) {
            case EACCES:
                YS_PRINTF("%s: permission denied\n", argv[0]);

                break;

            case ENOENT:
                YS_PRINTF("%s: no such directory\n", argv[0]);

                break;

            case ENOTDIR:
                YS_PRINTF("%s: not a directory\n", argv[0]);

                break;

            default:
                YS_PRINTF("%s: unknown error\n", argv[0]);

                break;
        }
    }
}

/* 셸 프로세스를 종료한다. */
static void builtin_exit(int argc, char *argv[]) {
    int exit_code = 0;

    if (argv[1] != NULL) exit_code = strtol(argv[1], NULL, 10);

    YS_PRINTF("Goodbye!\n");

    exit(exit_code);
}

/* 작업을 포그라운드에서 실행한다. */
static void builtin_fg(int argc, char *argv[]) {
    // TODO: ...
}

/* 빌트인 명령어 목록을 출력한다. */
static void builtin_help(int argc, char *argv[]) {
    // TODO: ...
}

/* 작업 목록을 출력한다. */
static void builtin_jobs(int argc, char *argv[]) {
    // TODO: ...
}

/* 작업에 시그널을 보낸다. */
static void builtin_kill(int argc, char *argv[]) {
    if (argc < 3) {
        YS_PRINTF("Usage: %s [-signal_number] [pid]\n", argv[0]);

        return;
    }

    int signal_number = 9, start_pos = 1;

    // `signal_number`의 값을 변경한다.
    if (argv[1][0] == '-') {
        // 시그널 번호에 해당하는 문자열이 숫자로 변환 가능한지 확인한다.
        if (!is_number(argv[1] + 1)) {
            YS_PRINTF("%s: invalid signal number\n", argv[0]);

            return;
        }

        signal_number = atoi(argv[1] + 1);

        start_pos++;
    }

    for (; start_pos < argc; start_pos++) {
        // 각 인자가 숫자로 변환 가능한지 확인한다.
        if (!is_number(argv[start_pos])) {
            YS_PRINTF("%s: illegal number\n", argv[0]);

            return;
        }

        pid_t pid = strtol(argv[start_pos], NULL, 10);

        if (kill(pid, signal_number) < 0) {
            switch (errno) {
                case ESRCH:
                    YS_PRINTF("%s: no such process\n", argv[0]);

                    break;

                default:
                    YS_PRINTF("%s: unknown error\n", argv[0]);

                    break;
            }
        }
    }
}

/* 현재 디렉토리 (working directory)를 출력한다. */
static void builtin_pwd(int argc, char *argv[]) {
    // 파일 경로의 최대 길이를 구한다.
    size_t size = pathconf(".", _PC_PATH_MAX);

    char *buffer = malloc(size);

    if (buffer == NULL) {
        YS_PRINTF("%s: unable to allocate %zu bytes\n", argv[0], size);

        return;
    }
    
    const char *path = getcwd(buffer, size);

    if (path != NULL) {
        YS_PRINTF("%s\n", path);
    } else {
        switch (errno) {
            case EACCES:
                YS_PRINTF("%s: permission denied\n", argv[0]);

                break;

            default:
                YS_PRINTF("%s: unknown error\n", argv[0]);

                break;
        }
    }

    free(buffer);
}

/* 작업 또는 프로세스가 종료될 때까지 기다린다. */
static void builtin_wait(int argc, char *argv[]) {
    // TODO: ...
}
