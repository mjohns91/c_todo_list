//
// Created by Matthew Johnson on 6/17/25.
//
#include "todo.h"

#include <stdio.h>
#include <string.h>

/**
 * @brief Displays the list of tasks with their status and ID.
 *
 * The method iterates through the global `tasks` array and prints each task.
 * Completed tasks are displayed in green, and incomplete tasks are displayed in yellow.
 * The color resets after each task is printed.
 *
 * The displayed format includes:
 * - Task ID
 * - Task description
 * - Task completion status (✓ for completed, blank for incomplete)
 *
 * The method assumes that the `task_count` global variable contains the total number of
 * tasks and that each task is stored in the global array `tasks`.
 *
 * Global variables used:
 * - `tasks` (array of Task): The list of tasks to display.
 * - `task_count` (int): The total number of tasks currently in the list.
 *
 * ANSI color codes are used for color formatting:
 * - Green for completed tasks.
 * - Yellow for incomplete tasks.
 *
 * The color codes are defined as:
 * - `ANSI_COLOR_GREEN`: Green color code.
 * - `ANSI_COLOR_YELLOW`: Yellow color code.
 * - `ANSI_COLOR_RESET`: Resets terminal color to default.
 */
void list_tasks() {
    for (int i = 0; i < task_count; i++) {
        // If a task is done, show in green, otherwise in yellow
        const char* color = tasks[i].done ? ANSI_COLOR_GREEN : ANSI_COLOR_YELLOW;
        printf("%s%d. %s [%s]%s\n",
               color,
               tasks[i].id,
               tasks[i].text,
               tasks[i].done ? "✓" : " ",
               ANSI_COLOR_RESET);  // Always reset color after printing
    }
}

/**
 * Adds a new task to the task list with the given text description.
 * The task is automatically assigned the next available ID and
 * marked as not done by default.
 *
 * @param text Pointer to a null-terminated string containing the task description.
 *            Maximum length is TASK_LEN - 1 characters.
 *
 * @note If the task list is full (task_count >= MAX_TASKS), the function will
 *       display an error message and the task won't be added.
 *
 * @example
 *     add_task("Complete documentation");
 */
void add_task(char *text) {
    if (strlen(text) > TASK_LEN) {
        printf("Error: Task description is too long.\n");
    } else {
        tasks[task_count].id = task_count + 1;
        strcpy(tasks[task_count].text, text);
        tasks[task_count].done = 0;
        task_count++;
        printf("Task added.\n");
    }
}

/**
 * Marks a task as completed given its ID.
 * The task's 'done' field will be set to 1 if found.
 *
 * @param id The unique identifier of the task to mark as done.
 *          Must be a positive integer matching an existing task ID.
 *
 * @note If no task is found with the given ID, an error message
 *       will be displayed.
 *
 * @example
 *     mark_done(1);  // Marks task #1 as completed
 */
void mark_done(int id) {
    tasks[id - 1].done = 1;
    printf("Task [%d] marked as done.\n", tasks[id - 1].id);
}

/**
 * Removes a task from the task list given its ID.
 * After deletion, all subsequent tasks are shifted left to
 * maintain array continuity.
 *
 * @param id The unique identifier of the task to delete.
 *          Must be a positive integer matching an existing task ID.
 *
 * @note If no task is found with the given ID, an error message
 *       will be displayed.
 * @note The task_count is decremented after successful deletion.
 *
 * @example
 *     delete_task(2);  // Deletes task #2 from the list
 */
void delete_task(int id) {
    int found = 0;

    // Find the task to delete
    for (int i = 0; i < task_count; i++) {
        if (tasks[i].id == id) {
            found = 1;

            // Shift remaining tasks left
            for (int j = i; j < task_count - 1; j++) {
                tasks[j] = tasks[j + 1];
            }

            task_count--;
            printf("%sTask %d deleted successfully%s\n",
                   ANSI_COLOR_GREEN, id, ANSI_COLOR_RESET);
            return;
        }
    }

    if (!found) {
        printf("%sError: Task %d not found%s\n",
               ANSI_COLOR_RED, id, ANSI_COLOR_RESET);
    }
}