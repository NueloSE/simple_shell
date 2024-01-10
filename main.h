#ifndef MAIN_H
#define MAIN_H

#define MAX_INPUT_SIZE 1024

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

extern char **environ;

/****memory_handler2.c*****/
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/****getenv.c***/
char *_getenv(const char *name);
int char_count(char *name, int c);
char **path_split(char *name);
int path_finder(char **name);

/******tokenize_input*****/
char **tokenize_input(char *input, size_t *arg_count);

/*****strings_helper.c***/
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char *_strchr(const char *str, int character);
int _strncmp(const char *str1, const char *str2, size_t n);

/******strings_helper2.c*******/
char *_strcat(char *dest, const char *src);
size_t _strcspn(const char *str, const char *target);

/*****exit.c*****/
void myExit(const char *input);


#endif /*MAIN_H*/
