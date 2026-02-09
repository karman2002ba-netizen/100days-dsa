//Mirror the Code Name
#include <stdio.h>
#include <string.h>

int main() {
    char name[] = "CodeName";
    int len = strlen(name);

    for (int i = len - 1; i >= 0; i--) {
        printf("%c", name[i]);
    }

    return 0;
}
