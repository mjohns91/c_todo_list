//
// Created by Matthew Johnson on 6/16/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "io.h"
#include "todo.h"

Task tasks[MAX_TASKS];
int task_count = 0;

/**
 * Loads tasks from a text file into memory.
 * Each line in the file should represent one task and must be formatted
 * as a comma-separated value (CSV) containing task ID, task description,
 * and completion status.
 *
 * If the file cannot be opened, an error message is printed, and no tasks are loaded.
 * The function reads tasks until the maximum number of tasks (`MAX_TASKS`) is reached
 * or the end of the file is encountered.
 *
 * Tasks are stored in the `tasks` array, and the total number of tasks is updated
 * in the `task_count` variable.
 */
void load_tasks() {
    FILE *f = fopen(FILE_NAME, "r");
    if (f == NULL) {
        printf("Error: Could not open file for reading\n");
        return;
    }

    task_count = 0;
    char line[TASK_LEN + 50];

    while (fgets(line, sizeof(line), f) != NULL && task_count < MAX_TASKS) {
        char temp_text[TASK_LEN];
        // Remove newline if present
        line[strcspn(line, "\n")] = 0;

        // Split the line using strtok
        char *id_str = strtok(line, ",");
        char *text = strtok(NULL, ",");
        char *done_str = strtok(NULL, ",");

        if (id_str && text && done_str) {
            tasks[task_count].id = atoi(id_str);
            strncpy(tasks[task_count].text, text, TASK_LEN - 1);
            tasks[task_count].text[TASK_LEN - 1] = '\0';  // Ensure null termination
            tasks[task_count].done = atoi(done_str);
            task_count++;
        }
    }
    fclose(f);
}

/**
 * Saves all tasks to a text file for persistent storage.
 * Each task is written as a comma-separated line containing:
 * task ID, task description, and completion status.
 * If the file cannot be opened, an error message is displayed.
 */
void save_tasks() {
    FILE *f = fopen(FILE_NAME, "w");
    if (f == NULL) {
        printf("Error: Could not open file for writing\n");
        return;
    }

    for (int i = 0; i < task_count; i++) {
        fprintf(f, "%d,%s,%d\n",
            tasks[i].id,
            tasks[i].text,
            tasks[i].done);
    }

    fclose(f);
}