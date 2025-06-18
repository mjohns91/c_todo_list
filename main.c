/*
 * @author Matthew Johnson
 * Main entry point for the program.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "io.h"
#include "todo.h"

void display_menu() {
    printf("\n=== Todo List Menu ===\n");
    printf("1. List tasks\n");
    printf("2. Add task\n");
    printf("3. Mark task as done\n");
    printf("4. Delete task\n");
    printf("5. Save and exit\n");
    printf("Enter your choice: ");
}

int main(int argc, char *argv[]) {
    load_tasks();
    char choice[10];
    char task_text[TASK_LEN];
    int task_id;

    // Argument options
    if (argc == 1) { // Single arg - interactive mode
        printf("Usage: todo [list|add|done|delete] [text|id]\n");
        printf("No arguments provided. Running in interactive mode.\n");
    } else if (argc > 3) { // Too many args
        printf("Usage: todo [list|add|done|delete] [text|id]\n");
        return EXIT_FAILURE;
    } else {
        if (strcmp(argv[1], "list") == 0) {
            list_tasks();
        } else if (strcmp(argv[1], "add") == 0 && argc >= 3) {
            add_task(argv[2]);
        } else if (strcmp(argv[1], "done") == 0 && argc >= 3) {
            mark_done(atoi(argv[2]));
        } else if (strcmp(argv[1], "delete") == 0 && argc >= 3) {
            delete_task(atoi(argv[2]));
        } else {
            printf("Invalid command.\n");
            return EXIT_FAILURE;
        }
    }

    // No arguments present
    while (1) {
        display_menu();
        fgets(choice, sizeof(choice), stdin);

        switch (choice[0]) {
            case '1':
                list_tasks();
                break;
            case '2':
                printf("Enter task description: ");
                fgets(task_text, TASK_LEN, stdin);
                task_text[strcspn(task_text, "\n")] = 0;
                add_task(task_text);
                break;
            case '3':
                printf("Enter task ID: ");
                scanf("%d", &task_id);
                getchar(); // consume newline
                mark_done(task_id);
                break;
            case '4':
                printf("Enter task ID: ");
                scanf("%d", &task_id);
                getchar(); // consume newline
                delete_task(task_id);
                break;
            case '5':
                save_tasks();
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
