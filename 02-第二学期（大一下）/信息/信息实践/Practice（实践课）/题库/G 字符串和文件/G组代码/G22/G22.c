#include <stdio.h>
#include <string.h>
#include <ctype.h>

char trans(char c) {
    if (strchr("aehiouwy", tolower(c))) return '\0';
    switch (tolower(c)) {
        case 'b': case 'f': case 'p': case 'v': return '1';
        case 'c': case 'g': case 'j': case 'k': case 'q': case 's': case 'x': case 'z': return '2';
        case 'd': case 't': return '3';
        case 'l': return '4';
        case 'm': case 'n': return '5';
        case 'r': return '6';
        default: return '\0';
    }
}

void soundex(const char *word, char *code) {
    int i = 1, j = 1;
    for (code[0] = word[0]; word[i] && j < 4; ++i) if (trans(word[i]) && (j == 1 || trans(word[i]) != code[j - 1])) code[j++] = trans(word[i]);
    for (; j < 4; ++j) code[j] = '0';
    code[4] = '\0';
}

int main() {
    FILE *Input, *Output;
    char word[10000], soundex_code[5];
    Input = fopen("input.txt", "r");
	fgets(word, sizeof(word), Input);
    word[strcspn(word, "\n")] = 0;
    fclose(Input);
    Output = fopen("output.txt", "w");
    soundex(word, soundex_code);
    fprintf(Output, "%s", soundex_code);
    fclose(Output);
    return 0;
}
