#include <stdio.h>
#include <string.h>

int main() {
    char stack[20];
    char input[20], rem_input[20];
    int top = 0, count = 0;
    int len, i, j = 0, k, m, a, l;

    printf("Simulation of PDA for n 0's followed by 2n 1's\n");
    printf("Enter a string: ");
    scanf("%s", input);

    l = strlen(input);
    stack[0] = 'Z';
    printf("Stack\tInput\n");
    printf("%s\t%s\n", stack, input);

    while (1) {
        len = strlen(input);
        while (len > 0) {
            if (input[0] == '0') {
                top = top + 1;
                stack[top] = '0';
                stack[top + 1] = '\0';
                m = 0;
                for (k = 1; k < len; k++) {
                    rem_input[m] = input[k];
                    m = m + 1;
                }
                rem_input[m] = '\0';
                strcpy(input, rem_input);
                printf("%s\t%s\n", stack, input);
            }
            if (input[0] == '1') {
                count++;
                if (count % 2 == 0) {
                    if (top < 1) {
                        printf("String not accepted\n");
                        goto end;
                    } else {
                        stack[top] = '\0';
                        top = top - 1;
                        m = 0;
                        for (k = 1; k < len; k++) {
                            rem_input[m] = input[k];
                            m = m + 1;
                        }
                        rem_input[m] = '\0';
                        strcpy(input, rem_input);
                        printf("%s\t%s\n", stack, input);
                    }
                } else {
                    m = 0;
                    for (k = 1; k < len; k++) {
                        rem_input[m] = input[k];
                        m = m + 1;
                    }
                    rem_input[m] = '\0';
                    strcpy(input, rem_input);
                    printf("%s\t%s\n", stack, input);
                }
            }
            break;
        }
        j = j + 1;
        if (j == l) {
            break;
        }
    }

    if (top >= 1) {
        printf("String not accepted\n");
    } else {
        printf("String accepted\n");
    }

end:
    printf(".............\n");
    return 0;
}
