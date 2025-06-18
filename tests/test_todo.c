#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../src/todo.h"
#include "../src/io.h"

// Test fixture setup
void setUp(void) {
    // Reset the tasks array and count before each test
    task_count = 0;
    memset(tasks, 0, sizeof(tasks));
}

// Test cases
void test_add_task(void) {
    setUp();
    
    // Test adding a valid task
    add_task("Test task");
    assert(task_count == 1);
    assert(strcmp(tasks[0].text, "Test task") == 0);
    assert(tasks[0].id == 1);
    assert(tasks[0].done == 0);
    
    // Test adding multiple tasks
    add_task("Second task");
    assert(task_count == 2);
    assert(tasks[1].id == 2);
}

void test_mark_done(void) {
    setUp();
    
    // Add a task and mark it as done
    add_task("Test task");
    mark_done(1);
    assert(tasks[0].done == 1);
}

int main(void) {
    printf("Running todo.c tests...\n");
    
    test_add_task();
    test_mark_done();
    
    printf("All todo.c tests passed!\n");
    return 0;
}