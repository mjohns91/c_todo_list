#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/io.h"
#include "../src/todo.h"

// Test helpers
void create_test_file(const char* content) {
    FILE *f = fopen(FILE_NAME, "w");
    if (f != NULL) {
        fprintf(f, "%s", content);
        fclose(f);
    }
}

void cleanup_test_file(void) {
    remove(FILE_NAME);
}

// Test cases
void test_load_tasks(void) {
    // Setup test data
    create_test_file("1,Test task,0\n2,Another task,1\n");
    
    // Test loading
    load_tasks();
    assert(task_count == 2);
    assert(strcmp(tasks[0].text, "Test task") == 0);
    assert(tasks[0].done == 0);
    assert(strcmp(tasks[1].text, "Another task") == 0);
    assert(tasks[1].done == 1);
    
    cleanup_test_file();
}

int main(void) {
    printf("Running io.c tests...\n");
    
    test_load_tasks();
    
    printf("All io.c tests passed!\n");
    return 0;
}