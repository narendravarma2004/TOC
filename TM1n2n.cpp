#include <stdio.h>
#include <string.h>

int main() {
    char str[20];
    int len, i, j;
    int flag0, flag1, flag2;

    printf("Program to show how a Turing machine will process 0^n1^n2^n\n");
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (j = 0; j < len; j++) {
        flag0 = flag1 = flag2 = 0;
        i = 0;

        while (i < len) {
            if (str[i] == '0' && flag0 == 0) {
                str[i] = 'A';
                printf("%s\n", str);
                flag0 = 1; // Mark that a '0' is changed to 'A'
            } else if (str[i] == '1' && flag0 == 1 && flag1 == 0) {
                str[i] = 'B';
                printf("%s\n", str);
                flag1 = 1; // Mark that a '1' is changed to 'B'
            } else if (str[i] == '2' && flag1 == 1 && flag2 == 0) {
                str[i] = 'C';
                printf("%s\n", str);
                flag2 = 1; // Mark that a '2' is changed to 'C'
            }
            i++;
        }

        // Exit loop if no changes were made in the current pass
        if (flag0 == 0 && flag1 == 0 && flag2 == 0) {
            break;
        }
    }

    return 0;
}
