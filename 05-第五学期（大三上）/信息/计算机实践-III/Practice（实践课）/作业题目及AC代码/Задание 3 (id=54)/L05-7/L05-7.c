#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct list { char word[20]; struct list *next; };

struct list *add_to_list(struct list *head, char *w) {
    struct list *p = malloc(sizeof(struct list)), *q = head;
    strcpy(p->word, w), p->next = NULL;
    if (!head) return p;
    while (q->next) q = q->next;
    return q->next = p, head;
}

void swap_elements(struct list *a, struct list *b) {
    char tmp[20];
    strcpy(tmp, a->word), strcpy(a->word, b->word), strcpy(b->word, tmp);
}

void print_list(struct list *head) {
    for (; head; head = head->next) printf("%s%s", head->word, head->next ? " " : "");
}

void delete_list(struct list *head) {
    struct list *t;
    while ((t = head)) head = head->next, free(t);
}

int main(void) {
    char s[1005], *tok;
	struct list *head = NULL, *i, *j;
    fgets(s, 1005, stdin);
    for (tok = strtok(s, " .\n"); tok; tok = strtok(NULL, " .\n")) head = add_to_list(head, tok);
    for (i = head; i && i->next; i = i->next) for (j = head; j->next; j = j->next) if (strcmp(j->word, j->next->word) > 0) swap_elements(j, j->next);
    return print_list(head), delete_list(head), 0;
}