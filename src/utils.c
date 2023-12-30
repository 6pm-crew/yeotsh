#include "yeotsh.h"

int isnumber(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i])) { return 0; }
    }
    return 1;
}
