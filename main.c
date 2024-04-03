#include <stdio.h>
#include <stdlib.h>
#include "check.h"
#include "mystrings.h"

int main()
{
    char delim;
    char dir[1000];
    char* paths = input(&delim,dir);
    int a = check(&delim,dir,paths);
    if (a == 0)
    {
		exit(0);
	}
	else
	{
		char* new_paths;
		new_paths = process(&delim,dir,paths);
		output(new_paths);
		free(paths);
		free(new_paths);
	}
    
	return 0;
}