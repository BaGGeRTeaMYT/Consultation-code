#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void) {
    int n = 0;
    scanf("%d%*c", &n);
    char *s1 = malloc(n*sizeof(char) + 1);
    char *s2 = malloc(n*sizeof(char) + 1);
    char *s3 = malloc(n*sizeof(char) + 1);
    char tmp = '0';
    fgets(s1, n + 1, stdin);
    while (tmp = getchar(), isspace(tmp));
    fgets(s2 + 1, n, stdin);
    s2[0] = tmp;
    while (tmp = getchar(), isspace(tmp));
    fgets(s3 + 1, n, stdin);
    s3[0] = tmp;
    s3 = realloc(s3, (n*3 + 1)*sizeof(char));
    for (int i = n; i < 3*n; i++) {
        if (i < 2*n) {
            s3[i] = s1[i - n];
        } else {
            s3[i] = s2[i - 2*n];
        }
    }
    s3[3*n] = '\0';
    printf("%s", s3);
    free(s1);
    free(s2);
    free(s3);
    return 0;
}