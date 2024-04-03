all:main
main:main.c check.c mystrings.c
    gcc -Wall -o main main.c check.c mystrings.c