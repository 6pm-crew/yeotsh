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

#ifndef YEOTSH_H
#define YEOTSH_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ================================================================ */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>

/* User-Defined Macros ===================================================== */

// clang-format off

/* 명령 줄의 최대 길이를 나타내는 정수 값. */
#define YS_MAX_LINE_LENGTH  2048

/* 일반 계정의 프롬프트 메시지 (prompt message)를 나타내는 문자열. */
#define YS_NON_ROOT_PROMPT  "^ $ "

/* 루트 계정의 프롬프트 메시지 (prompt message)를 나타내는 문자열. */
#define YS_ROOT_PROMPT      "^ # "

// clang-format on

/* Macros ================================================================== */

/* 표준 오류 스트림에 오류 내용을 출력하고, 셸을 종료한다. */
#define YS_PANIC(str) perror(str), abort()

/* 표준 오류 스트림에 문자열을 출력한다. */
#define YS_PRINTF(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

/* Typedefs ================================================================ */

/* 빌트인 명령어를 나타내는 구조체. */
struct builtin_command {
    const char *name;                      // 빌트인 명령어의 이름.
    void (*func)(int argc, char *argv[]);  // 실행할 함수의 메모리 주소.
};

/* (From 'builtin.c') ====================================================== */

/* `argv[0]`이 빌트인 명령어인지 확인한다. */
bool is_builtin_command(const char *argv[], struct builtin_command *bc);

/* (From 'jobs.c') ========================================================= */

// TODO: ...

/* (From 'utils.c') ======================================================== */

/* `str`이 숫자로 변환 가능한 문자열인지 확인한다. */
bool is_number(const char *str);

// 주의: 함수 원형은 반드시 이 줄 위에 선언할 것!
#ifdef __cplusplus
}
#endif

#endif  // `YEOTSH_H`
