#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
/**
 * file: main.h
 * description: Header file containing prototypes for all functions
 * used in the pointers and arrays project.
 */

int _putchar(char c);
void reset_to_98(int *n);
void swap_int(int *a, int *b);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);
void print_chessboard(char (*a)[8]);

#endif
