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
char cwd[1024];

/**
 * Loads in tasks from a task text file, if available.
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
            // Print the line for testing
            printf("%d,%s,%d\n", tasks[task_count].id, tasks[task_count].text, tasks[task_count].done);
            task_count++;
        }
    }
    fclose(f);
}

void save_tasks() {

}