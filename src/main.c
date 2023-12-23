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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>

#include "yeotsh.h"

/* Private Function Prototypes ============================================= */

/* 셸을 초기화한다. */
static void init_shell(void);

/* 명령어를 읽고, 공백 문자를 기준으로 명령어를 한 단어씩 자른다. */
static char **read_and_parse(void);

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
        YS_PRINTF(prompt);

        char **argv = read_and_parse();

        // TODO: ...
    }

    return 0;
}

/* Private Functions ======================================================= */

/* 셸을 초기화한다. */
static void init_shell(void) {
    // 사용자가 루트 권한을 가지고 있는지 확인한다.
    if (!geteuid()) prompt = YS_ROOT_PROMPT;
}

/* 명령어를 읽고, 공백 문자를 기준으로 명령어를 한 단어씩 자른다. */
static char **read_and_parse(void) {
    char line[YS_MAX_LINE_LENGTH];

    if (fgets(line, sizeof line, stdin) == NULL) {
        // "Ctrl + D" (`EOF`) 입력을 처리한다.
        if (feof(stdin)) putchar('\n'), exit(EXIT_SUCCESS);

        YS_PANIC("fgets() failed");
    }

    // 명령 줄의 마지막 개행 문자를 제거한다.
    line[strcspn(line, "\n")] = '\0';

    // TODO: ...
    return NULL;
}