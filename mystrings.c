#include <stdio.h>
#include "mystrings.h"

size_t my_strlen(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strcat(char *dest, char *src)
{
    char *tmp = dest + my_strlen(dest);
    int i;
    for (i = 0; src[i] != '\0'; i++)
        tmp[i] = src[i];
    tmp[i] = '\0';
    return dest;
}

char *my_strtok(char *string, char *delim)
{
    static char *last;
    if (string != NULL)
        last = string;
    if (last == NULL)
        return NULL;
    char *tmp = last;
    while (*tmp == delim[0])
        tmp++;
    if (*tmp == '\0')
        return NULL;
    int i;
    last = tmp;
    for (i = 0; tmp[i] != delim[0]; i++)
        if (tmp[i] == '\0')
        {
            last = NULL;
            return tmp;
        }
    last += i + 1;
    tmp[i] = '\0';
    return tmp;
}

int my_strcmp(char *str1, char *str2)
{
    int i;
    for (i = 0; str1[i] == str2[i]; i++)
        if (str1[i] == '\0')
            return 0;

    if (str1[i] > str2[i])
        return 1;
    else
        return -1;
}

char *my_strcpy(char *toHere, char *fromHere)
{
    int i;
    for (i = 0; fromHere[i] != '\0'; i++)
        toHere[i] = fromHere[i];
    toHere[i] = '\0';
    return toHere;
}