#ifndef MAIN_H
#define MAIN_H

#define MAX_INPUT_SIZE 1024
#define ENV_MAX_SIZE 100

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
void free_array(char **array);

/****getenv.c***/
char *_getenv(char **variable, const char *name);
size_t char_count(char *name, char c);
int find_path(char **name, char *path);

/******tokenize.c*****/
void tokenize_input(char ***, char *input, size_t *arg_count);
int file_access(char *name);

/*****strings_helper.c***/
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
char *_strchr(const char *str, int character);
int _strncmp(const char *str1, const char *str2, size_t n);

/******strings_helper2.c*******/
char *_strcat(char *dest, const char *src);
size_t _strcspn(const char *str, const char *target);
int _strcmp(const char *str1, const char *str2);

/*****exit******/
void myExit(char *input);

/*****executions.c*****/
void execute_func(char **args, char **env);
int isWhitespace(char *str);

/*****envrionment_built-in*******/
void display_env(char *input);


#endif /*MAIN_H*/
