#include <stdio.h>
#include <ctype.h>

int main() {
    char str[50];
    int state = 0;   // start state

    printf("Enter a string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if (state == 0) {   // start
            if (isalpha(ch) || ch == '_')
                state = 1;
            else {
                state = -1;
                break;
            }
        }
        else if (state == 1) {  // identifier
            if (isalnum(ch) || ch == '_')
                state = 1;
            else {
                state = -1;
                break;
            }
        }
    }

    if (state == 1)
        printf("Valid Identifier\n");
    else
        printf("Invalid Identifier\n");

    return 0;
}