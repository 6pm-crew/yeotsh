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

/* User-Defined Macros ===================================================== */

// clang-format off

/* 루트 계정의 프롬프트 메시지 (prompt message)를 나타내는 문자열. */
#define YS_MAIN_ROOT_PROMPT      "^ # "

/* 일반 계정의 프롬프트 메시지 (prompt message)를 나타내는 문자열. */
#define YS_MAIN_NON_ROOT_PROMPT  "^ $ "

// clang-format on

/* Macros ================================================================== */

/* 표준 오류 스트림에 문자열을 출력한다. */
#define YS_PRINTF(str) \
    fprintf(stderr, "%s", str), fflush(stderr);

#ifdef __cplusplus
}
#endif

#endif  // `YEOTSH_H`