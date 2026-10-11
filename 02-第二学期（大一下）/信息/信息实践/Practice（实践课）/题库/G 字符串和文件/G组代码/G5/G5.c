#include <stdio.h>
#include <ctype.h>
int main() {
    FILE *fp, *fp_out;
    char str[100001];
    fp = fopen("input.txt", "r");
    if (fgets(str, 100000, fp) == NULL) fclose(fp);
    fclose(fp);
    for (int i = 0; str[i] != '\0'; i++) str[i] = str[i] == 'b' ? 'a' : str[i] == 'a' ? 'b' : str[i] == 'B' ? 'A' : str[i] == 'A' ? 'B' : str[i];
    fp_out = fopen("output.txt", "w");
    fprintf(fp_out, "%s", str);
    fclose(fp_out);
    return 0;
}
