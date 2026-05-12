#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_STRING_LENGTH 256

typedef struct {
    char title[MAX_STRING_LENGTH];
    char description[MAX_STRING_LENGTH];
    char dueDate[MAX_STRING_LENGTH];
} Task;

void addTask(Task *tasks, int *taskCount);
void viewTasks(Task *tasks, int taskCount);
void updateTask(Task *tasks, int taskCount);
void deleteTask(Task *tasks, int *taskCount);
void clearBuffer();
void displayMenu();

int main() {
    Task tasks[MAX_TASKS];  // Array to store tasks
    int taskCount = 0;      // Counter to track number of tasks
    int choice;

    while (1) {
        displayMenu(); // Display the menu
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();  // Clear the input buffer after reading integer

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);  // Add a new task
                break;
            case 2:
                viewTasks(tasks, taskCount);  // View all tasks
                break;
            case 3:
                updateTask(tasks, taskCount);  // Update an existing task
                break;
            case 4:
                deleteTask(tasks, &taskCount);  // Delete a task
                break;
            case 5:
                printf("Exiting the program...\n");
                exit(0);  // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nTo-Do List Application\n");
    printf("1. Add Task\n");
    printf("2. View Tasks\n");
    printf("3. Update Task\n");
    printf("4. Delete Task\n");
    printf("5. Exit\n");
}

// Function to add a new task
void addTask(Task *tasks, int *taskCount) {
    if (*taskCount >= MAX_TASKS) {
        printf("Task list is full! Cannot add more tasks.\n");
        return;
    }

    printf("Enter task title: ");
    fgets(tasks[*taskCount].title, MAX_STRING_LENGTH, stdin);
    tasks[*taskCount].title[strcspn(tasks[*taskCount].title, "\n")] = 0;  // Remove newline

    printf("Enter task description: ");
    fgets(tasks[*taskCount].description, MAX_STRING_LENGTH, stdin);
    tasks[*taskCount].description[strcspn(tasks[*taskCount].description, "\n")] = 0;

    printf("Enter task due date (e.g., YYYY-MM-DD): ");
    fgets(tasks[*taskCount].dueDate, MAX_STRING_LENGTH, stdin);
    tasks[*taskCount].dueDate[strcspn(tasks[*taskCount].dueDate, "\n")] = 0;

    (*taskCount)++;
    printf("Task added successfully!\n");
}

// Function to view all tasks
void viewTasks(Task *tasks, int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available.\n");
        return;
    }

    printf("\nYour To-Do List:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("Task %d: %s\n", i + 1, tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("Due Date: %s\n\n", tasks[i].dueDate);
    }
}

// Function to update a task
void updateTask(Task *tasks, int taskCount) {
    if (taskCount == 0) {
        printf("No tasks to update.\n");
        return;
    }

    int taskNumber;
    printf("Enter task number to update: ");
    scanf("%d", &taskNumber);
    clearBuffer();  // Clear the input buffer after reading integer

    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    taskNumber--; // Adjust for zero-based indexing

    printf("Enter new task title (leave empty to keep current): ");
    fgets(tasks[taskNumber].title, MAX_STRING_LENGTH, stdin);
    tasks[taskNumber].title[strcspn(tasks[taskNumber].title, "\n")] = 0;  // Remove newline

    printf("Enter new task description (leave empty to keep current): ");
    fgets(tasks[taskNumber].description, MAX_STRING_LENGTH, stdin);
    tasks[taskNumber].description[strcspn(tasks[taskNumber].description, "\n")] = 0;

    printf("Enter new task due date (leave empty to keep current): ");
    fgets(tasks[taskNumber].dueDate, MAX_STRING_LENGTH, stdin);
    tasks[taskNumber].dueDate[strcspn(tasks[taskNumber].dueDate, "\n")] = 0;

    printf("Task updated successfully!\n");
}

// Function to delete a task
void deleteTask(Task *tasks, int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }

    int taskNumber;
    printf("Enter task number to delete: ");
    scanf("%d", &taskNumber);
    clearBuffer();  // Clear the input buffer after reading integer

    if (taskNumber < 1 || taskNumber > *taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    taskNumber--; // Adjust for zero-based indexing

    // Shift tasks to remove the deleted task
    for (int i = taskNumber; i < *taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (*taskCount)--;

    printf("Task deleted successfully!\n");
}

// Function to clear the input buffer
void clearBuffer() {
    while (getchar() != '\n');
}
