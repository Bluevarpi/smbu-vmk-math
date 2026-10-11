#include <stdio.h>
#include <ctype.h>
int cnt_little, cnt_big;
int main() {
    FILE *Input, *Output;
    char str[100001];
    Input = fopen("input.txt", "r");
    if (fgets(str, 100000, Input) == NULL) fclose(Input);
    fclose(Input);
    for (int i = 0; str[i] != '\0'; i++) {
        if (islower((unsigned char)str[i])) cnt_little++;
        else if (isupper((unsigned char)str[i])) cnt_big++;
    }
    Output = fopen("output.txt", "w");
    fprintf(Output, "%d %d", cnt_little, cnt_big);
    fclose(Output);
    return 0;
}
