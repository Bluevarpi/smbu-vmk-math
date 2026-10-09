#include <stdio.h>

void print_digit(char s[]) {
	int cnt[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (int i = 0; s[i] != '.'; i++) if ('0' <= s[i] && s[i] <= '9') cnt[s[i] - '0']++;
	for (int i = 0; i <= 9; i++) if (cnt[i]) printf("%d %d\n", i, cnt[i]);
}

int main () {
	char s[100000], c;
	for (int i = 0; (c = getchar()) != '\n'; i++) s[i] = c;
    print_digit(s);
    return 0;
}
