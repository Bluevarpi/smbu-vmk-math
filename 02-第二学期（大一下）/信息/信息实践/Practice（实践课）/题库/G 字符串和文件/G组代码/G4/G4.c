#include <stdio.h>
#include <string.h>
int cnt1[26], cnt2[26], n;
int main() {
    FILE *Input, *Output;
    char word1[105], word2[105], ans[212];
    Input = fopen("input.txt", "r");
    if (fscanf(Input, "%s %s", word1, word2) != 2) fclose(Input);
    fclose(Input);
    for (int i = 0; word1[i] != '\0'; i++) cnt1[word1[i] - 'a']++;
    for (int i = 0; word2[i] != '\0'; i++) cnt2[word2[i] - 'a']++;
    for (int i = 0; i < 26; i++) if (cnt1[i] == 1 && cnt2[i] == 1) ans[n++] = 'a' + i;
    Output = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) fprintf(Output, "%c ", ans[i]);
    fclose(Output);
    return 0;
}
