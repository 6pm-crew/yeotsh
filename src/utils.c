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

#include <ctype.h>
#include <sys/types.h>

#include "yeotsh.h"

/* Public Functions ======================================================== */

/* `str`이 숫자로 변환 가능한 문자열인지 확인한다. */
bool is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++)
        if (!isdigit(str[i])) return false;
    
    return true;
}
