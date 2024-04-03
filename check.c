#include <stdio.h>
#include <stdlib.h>
#include "check.h"
#include "mystrings.h"
#include <string.h>

char *input(char *delim, char *dir)
{
    printf("delim: ");
    scanf(" %c", delim);
    printf("user name: ");
    scanf("%s", dir);
    printf("dir: ");
    getchar(); // clear input buffer
    fgets(dir, 1000, stdin);
    printf("%s", dir);
    // Удаляем символ новой строки, если он есть
    if (dir[strlen(dir) - 1] == '\n')
    {
        dir[strlen(dir) - 1] = '\0';
    }
    printf("paths: ");
    char *paths = malloc(MAX_LEN);
    fgets(paths, MAX_LEN, stdin);
    // Удаляем символ новой строки, если он есть
    if (paths[strlen(paths) - 1] == '\n')
    {
        paths[strlen(paths) - 1] = '\0';
    }
    return paths;
}

int check(char *delim, char *dir, char *paths)
{
    if (my_strlen(paths) > MAX_LEN)
    {
        printf("error, max len str = %d symbols\n", MAX_LEN);
        return 0;
    }
    return 1;
}

char *process(char *delim, char *dir, char *paths)
{
    char *new_paths = calloc(MAX_LEN, sizeof(char));
    char *del_f = my_strtok(paths, delim);
    while (del_f != NULL)
    {
        if (del_f[0] == '~' && del_f[1] == '/')
        {
            char *p = malloc(MAX_LEN * sizeof(char));
            my_strcpy(p, dir);
            my_strcat(p, del_f + 1);
            my_strcat(p, delim); // добавляем разделитель
            my_strcat(new_paths, p);
            free(p);
        }
        else
        {
            my_strcat(new_paths, del_f); // добавляем подстроку пути
            my_strcat(new_paths, delim); // добавляем разделитель
        }
        del_f = my_strtok(NULL, delim);
    }
    if (my_strlen(new_paths) > 0 && new_paths[my_strlen(new_paths) - 1] == delim[0])
    {
        new_paths[my_strlen(new_paths) - 1] = '\0';
    }
    return new_paths;
}

void output(char *new_paths)
{
    printf("new paths: %s\n", new_paths);
}
