#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

struct word_item {
	char *word;
	struct word_item *next;
};

static void free_list(struct word_item *head) {
    struct word_item *p = head, *q;
    while (p) q = p->next, free(p->word), free(p), p = q;
}

static int add_word(struct word_item **h, struct word_item **t, const char *w) {
    struct word_item *n;
    return (!(n = malloc(sizeof(*n))) || !(n->word = malloc(strlen(w) + 1))) ? (free(n), -1) : (strcpy(n->word, w), n->next = 0, *t = *h ? ((*t)->next = n) : (*h = n), 0);
}

static char **list_to_array(struct word_item *h, int *cnt) {
    int n = 0;
    struct word_item *p = h;
    for (; p; n++, p = p->next);
    char **arr = malloc(n * sizeof(*arr));
    if (!arr) return *cnt = 0, NULL;
    for (*cnt = n, n = 0, p = h; p; p = p->next) arr[n++] = p->word;
    return arr;
}

static int parse_command(char **tokens, int start, int end, char ***argv_out, char **in_file_out, char **out_file_out, int *out_mode_out) {
    char *in_file = NULL, *out_file = NULL; int out_mode = 0, j, argc = 0, k, wrong = 0; char **argv;
    for (j = start; j < end; j++) {
        if (!tokens[j]) continue;
        if (strcmp(tokens[j], "<") == 0) {
            if ((in_file || j + 1 >= end || !tokens[j + 1]) && (wrong = 1)) break;
            in_file = tokens[j + 1]; tokens[j] = tokens[j + 1] = NULL; j++; continue;
        }
        if (strcmp(tokens[j], ">") == 0) {
            if ((out_mode || j + 1 >= end || !tokens[j + 1]) && (wrong = 1)) break;
            out_mode = 1; out_file = tokens[j + 1]; tokens[j] = tokens[j + 1] = NULL; j++; continue;
        }
        if (strcmp(tokens[j], ">>") == 0) {
            if ((out_mode || j + 1 >= end || !tokens[j + 1]) && (wrong = 1)) break;
            out_mode = 2; out_file = tokens[j + 1]; tokens[j] = tokens[j + 1] = NULL; j++; continue;
        }
    }
    if (wrong) return -1;
    for (j = start; j < end; j++) if (tokens[j]) argc++;
    if (!argc) return -1;
    argv = (char **)malloc((argc + 1) * sizeof(*argv));
    if (!argv) return -1;
    for (k = 0, j = start; j < end; j++) if (tokens[j]) argv[k++] = tokens[j];
    return argv[k] = NULL, *argv_out = argv, *in_file_out = in_file, *out_file_out = out_file, *out_mode_out = out_mode, 0;
}

int main(void) {
    char buf[1024];
    while (fgets(buf, sizeof(buf), stdin)) {
        struct word_item *head = NULL, *tail = NULL;
        char *cur = NULL, c; size_t cur_len = 0, cur_cap = 0, i, len;
        int in_quotes = 0, quotes_count = 0, error = 0;
        len = strlen(buf);
        if (len && buf[len - 1] == '\n') buf[len - 1] = '\0';
        for (i = 0; (c = buf[i]) != '\0'; ++i) {
            if (c == '\"' && (in_quotes ^= 1, quotes_count++, 1)) continue;
            if (!in_quotes) {
                if (c == ' ' || c == '\t') {
                    if (cur_len && (add_word(&head, &tail, cur) ? (error = 1) : (cur_len = 0, 0))) break;
                    continue;
                }
                if (c == '<') {
                    if (cur_len && (add_word(&head, &tail, cur) ? (error = 1) : (cur_len = 0, 0))) break;
                    if (add_word(&head, &tail, "<") && (error = 1)) break;
                    continue;
                }
                if (c == '>') {
                    if (cur_len && (add_word(&head, &tail, cur) ? (error = 1) : (cur_len = 0, 0))) break;
                    if (buf[i + 1] == '>') {
						if (add_word(&head, &tail, ">>") && (error = 1)) break;
						i++;
					}
                    else if (add_word(&head, &tail, ">") && (error = 1)) break;
                    continue;
                }
                if (c == '|') {
                    if (cur_len && (add_word(&head, &tail, cur) ? (error = 1) : (cur_len = 0, 0))) break;
                    if (add_word(&head, &tail, "|") && (error = 1)) break;
                    continue;
                }
            }
            if (cur_len + 1 >= cur_cap) {
                size_t new_cap = cur_cap ? cur_cap * 2 : 16; char *tmp = (char *)realloc(cur, new_cap);
                if (!tmp && (error = 1)) break;
                cur = tmp, cur_cap = new_cap;
            }
            cur[cur_len++] = c, cur[cur_len] = '\0';
        }
        if (!error && cur_len) if (add_word(&head, &tail, cur)) error = 1;
        free(cur);
        if (error) return free_list(head), 1;
        if (quotes_count % 2 && (printf("Error: unmatched quotes\n"), fflush(stdout), free_list(head), 1)) continue;
        if (!head) continue;
		int tokc, j, pipe_pos = -1, wrong = 0;
        char **tokens = list_to_array(head, &tokc);
        if (!tokens && tokc > 0) return free_list(head), 1;
        for (j = 0; j < tokc; j++) if (tokens[j] && !strcmp(tokens[j], "|") && (pipe_pos == -1 ? (pipe_pos = j, 0) : (wrong = 1))) break;
        if (wrong && (printf("Error: wrong token\n"), fflush(stdout), free(tokens), free_list(head), 1)) continue;
        if (pipe_pos == -1) {
            char **argv, *in_file, *out_file; int out_mode;
            if (parse_command(tokens, 0, tokc, &argv, &in_file, &out_file, &out_mode) < 0 && (printf("Error: wrong token\n"), fflush(stdout), free(tokens), free_list(head), 1)) continue;
            fflush(NULL);
            pid_t pid = fork();
            if (pid < 0) return perror("fork"), free(argv), free(tokens), free_list(head), 1;
            if (pid == 0) {
                if (in_file) {
                    int fd_in = open(in_file, O_RDONLY);
                    if (fd_in < 0) perror(in_file), _exit(1);
                    if (dup2(fd_in, STDIN_FILENO) < 0) perror("dup2"), close(fd_in), _exit(1);
                    close(fd_in);
                }
                if (out_mode && out_file) {
                    int flags = O_WRONLY | O_CREAT | (out_mode == 1 ? O_TRUNC : O_APPEND);
                    int fd_out = open(out_file, flags, 0666);
                    if (fd_out < 0) perror(out_file), _exit(1);
                    if (dup2(fd_out, STDOUT_FILENO) < 0) perror("dup2"), close(fd_out), _exit(1);
                    close(fd_out);
                }
                execvp(argv[0], argv), perror(argv[0]), _exit(1);
            }
            waitpid(pid, NULL, 0), free(argv), free(tokens), free_list(head);
            continue;
        }
        tokens[pipe_pos] = NULL;
        char **argv1, **argv2, *in1, *out1, *in2, *out2;
		int out_mode1, out_mode2;
        if (parse_command(tokens, 0, pipe_pos, &argv1, &in1, &out1, &out_mode1) < 0 && (printf("Error: wrong token\n"), fflush(stdout), free(tokens), free_list(head), 1)) continue;
        if (parse_command(tokens, pipe_pos + 1, tokc, &argv2, &in2, &out2, &out_mode2) < 0 && (printf("Error: wrong token\n"), fflush(stdout), free(argv1), free(tokens), free_list(head), 1)) continue;
        if ((out_mode1 || in2) && (printf("Error: wrong token\n"), fflush(stdout), free(argv1), free(argv2), free(tokens), free_list(head), 1)) continue;
        int pfd[2]; pid_t pid1, pid2;
        if (pipe(pfd) < 0) return perror("pipe"), free(argv1), free(argv2), free(tokens), free_list(head), 1;
        fflush(NULL);
        pid1 = fork();
        if (pid1 < 0) return perror("fork"), free(argv1), free(argv2), free(tokens), free_list(head), 1;
        if (pid1 == 0) {
            if (in1) {
                int fd_in = open(in1, O_RDONLY);
                if (fd_in < 0) perror(in1), _exit(1);
                if (dup2(fd_in, STDIN_FILENO) < 0) perror("dup2"), close(fd_in), _exit(1);
                close(fd_in);
            }
            if (dup2(pfd[1], STDOUT_FILENO) < 0) perror("dup2"), _exit(1);
            close(pfd[0]), close(pfd[1]), execvp(argv1[0], argv1), perror(argv1[0]), _exit(1);
        }
        pid2 = fork();
        if (pid2 < 0) return perror("fork"), free(argv1), free(argv2), free(tokens), free_list(head), 1;
        if (pid2 == 0) {
            if (dup2(pfd[0], STDIN_FILENO) < 0) perror("dup2"), _exit(1);
            close(pfd[1]), close(pfd[0]);
            if (out_mode2 && out2) {
                int flags = O_WRONLY | O_CREAT | (out_mode2 == 1 ? O_TRUNC : O_APPEND);
                int fd_out = open(out2, flags, 0666);
                if (fd_out < 0) perror(out2), _exit(1);
                if (dup2(fd_out, STDOUT_FILENO) < 0) perror("dup2"), close(fd_out), _exit(1);
                close(fd_out);
            }
            execvp(argv2[0], argv2), perror(argv2[0]), _exit(1);
        }
        close(pfd[0]); close(pfd[1]), waitpid(pid1, NULL, 0), waitpid(pid2, NULL, 0), free(argv1), free(argv2), free(tokens), free_list(head);
    }
    return 0;
}