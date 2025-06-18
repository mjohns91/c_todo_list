//
// Created by Matthew Johnson on 6/16/25.
//

#ifndef TODO_H
#define TODO_H

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define MAX_TASKS 100
#define TASK_LEN 256

typedef struct {
    int id;
    char text[TASK_LEN];
    int done;
} Task;

extern Task tasks[MAX_TASKS];
extern int task_count;
void list_tasks();
void add_task(char *text);
void mark_done(int id);
void delete_task(int id);

#endif //TODO_H
