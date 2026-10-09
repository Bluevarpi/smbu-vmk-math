#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool judge (const char *str) {
    for (int left = 0, right = strlen(str) - 1; right > left; left++, right--) if (str[left] != str[right]) return false;
    return true;
}

int main () {
    FILE *fp, *Output;
    char str[100001];
    fp = fopen("input.txt", "r");
    if (fgets(str, 100000, fp) == NULL) fclose(fp);
    fclose(fp);
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') str[len - 1] = '\0';
    Output = fopen("output.txt", "w");
    fprintf(Output, judge(str) ? "YES" : "NO");
    fclose(Output);
    return 0;
}
