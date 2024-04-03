#define MAX_LEN 2000
char *input(char *delim, char *dir);
int check(char *delim, char *dir, char *paths);
char *process(char *delim, char *dir, char *paths);
void output(char* new_paths);