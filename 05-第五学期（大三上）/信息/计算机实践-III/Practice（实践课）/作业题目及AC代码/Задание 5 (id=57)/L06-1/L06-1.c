#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word_item {
	char *word;
	struct word_item *next;
};

static void free_list(struct word_item *p) {
    struct word_item *q;
    while (p) q = p->next, free(p->word), free(p), p = q;
}

static int add_word(struct word_item **h, struct word_item **t, const char *w) {
    struct word_item *n = malloc(sizeof(*n));
    if (!n || !(n->word = malloc(strlen(w) + 1))) return free(n), -1;
    strcpy(n->word, w), n->next = NULL;
    *h ? ((*t)->next = n) : (*h = n);
    return *t = n, 0;
}

int main(void) {
    char buf[1024];
    while (fgets(buf, sizeof(buf), stdin)) {
        struct word_item *head = NULL, *tail = NULL, *p;
        char *cur = NULL, c;
        size_t len = 0, cap = 0;
        int in_q = 0, q_cnt = 0;
        buf[strcspn(buf, "\n")] = '\0';
        for (int i = 0; (c = buf[i]); ++i) {
            if (c == '\"') {
				in_q = !in_q, q_cnt++;
				continue;
			}
            if (!in_q && (c == ' ' || c == '\t')) {
                if (len) {
                    if (add_word(&head, &tail, cur)) return free(cur), free_list(head), 1;
                    len = 0;
                }
                continue;
            }
            if (len + 1 >= cap) {
                char *tmp = realloc(cur, cap = cap ? cap * 2 : 16);
                if (!tmp) return free(cur), free_list(head), 1;
                cur = tmp;
            }
            cur[len++] = c; cur[len] = '\0';
        }
        if (len && add_word(&head, &tail, cur)) return free(cur), free_list(head), 1;
        free(cur);
        if (q_cnt % 2) printf("Error: unmatched quotes\n");
        else for (p = head; p; p = p->next) printf("[%s]\n", p->word);
        free_list(head);
    }
    return 0;
}