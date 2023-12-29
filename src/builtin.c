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

/* 작업을 백그라운드에서 실행한다. */
static void builtin_bg(char *argv[]);

/* 현재 디렉토리 (working directory)를 변경한다. */
static void builtin_cd(char *argv[]);

/* 셸 프로세스를 종료한다. */
static void builtin_exit(char *argv[]);

/* 작업을 포그라운드에서 실행한다. */
static void builtin_fg(char *argv[]);

/* 빌트인 명령어 목록을 출력한다. */
static void builtin_help(char *argv[]);

/* 작업 목록을 출력한다. */
static void builtin_jobs(char *argv[]);

/* 작업에 시그널을 보낸다. */
static void builtin_kill(char *argv[]);

/* 현재 디렉토리 (working directory)를 출력한다. */
static void builtin_pwd(char *argv[]);

/* 작업 또는 프로세스가 종료될 때까지 기다린다. */
static void builtin_wait(char *argv[]);

/* Constants =============================================================== */

/* 빌트인 명령어의 실행 정보가 저장되어 있는 배열. */
static const struct builtin_command builtin_commands[] = {
    { "bg",   builtin_bg   },
    { "cd",   builtin_cd   },
    { "exit", builtin_exit },
    { "fg",   builtin_fg   },
    { "help", builtin_help },
    { "jobs", builtin_jobs },
    { "kill", builtin_kill },
    { "pwd",  builtin_pwd  },
    { "wait", builtin_wait },
    { NULL,   NULL         }
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
static void builtin_bg(char *argv[]) {
    // TODO: ...
}

/* 현재 디렉토리 (working directory)를 변경한다. */
static void builtin_cd(char *argv[]) {
    // TODO: ...
}

/* 셸 프로세스를 종료한다. */
static void builtin_exit(char *argv[]) {
    int exit_code = 0;

    if (argv[1] != NULL) exit_code = strtol(argv[1], NULL, 10);

    YS_PRINTF("Goodbye!\n");
    
    exit(exit_code);
}

/* 작업을 포그라운드에서 실행한다. */
static void builtin_fg(char *argv[]) {
    // TODO: ...
}

/* 빌트인 명령어 목록을 출력한다. */
static void builtin_help(char *argv[]) {
    // TODO: ...
}

/* 작업 목록을 출력한다. */
static void builtin_jobs(char *argv[]) {
    // TODO: ...
}

/* 작업에 시그널을 보낸다. */
static void builtin_kill(char *argv[]) {
    // TODO: ...
}

/* 현재 디렉토리 (working directory)를 출력한다. */
static void builtin_pwd(char *argv[]) {
    // TODO: ...
}

/* 작업 또는 프로세스가 종료될 때까지 기다린다. */
static void builtin_wait(char *argv[]) {
    // TODO: ...
}