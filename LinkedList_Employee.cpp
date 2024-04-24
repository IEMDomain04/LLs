#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Employee {
    char name[100];
    int salary;
    struct Employee* next;
};

// Function to create a new employee node
struct Employee* createEmployee(const char* name, int salary) {
    struct Employee* newEmployee = (struct Employee*)malloc(sizeof(struct Employee));
    if (newEmployee == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newEmployee->name, name);
    newEmployee->salary = salary;
    newEmployee->next = NULL;
    return newEmployee;
}

// Function to insert an employee at the beginning of the list
void insertEmployee(struct Employee** head, const char* name, int salary) {
    struct Employee* newEmployee = createEmployee(name, salary);
    newEmployee->next = *head;
    *head = newEmployee;
    printf("Employee %s with salary %d has been added.\n", name, salary);
}

// Function to delete an employee from the list
void deleteEmployee(struct Employee** head, const char* name) {
    struct Employee* temp = *head;
    struct Employee* prev = NULL;

    // If the employee to be deleted is the head employee
    if (temp != NULL && strcmp(temp->name, name) == 0) {
        *head = temp->next;
        free(temp);
        printf("Employee %s has been deleted.\n", name);
        return;
    }

    // Find the employee to be deleted
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // If the employee was not found
    if (temp == NULL) {
        printf("Employee %s not found in the list.\n", name);
        return;
    }

    // Remove the employee from the list
    prev->next = temp->next;
    free(temp);
    printf("Employee %s has been deleted.\n", name);
}

// Function to display the list of employees
void displayEmployees(struct Employee* head) {
    struct Employee* temp = head;
    if (temp == NULL) {
        printf("The employee list is empty.\n");
        return;
    }
    printf("Employee List:\n");
    while (temp != NULL) {
        printf("Name: %s, Salary: %d\n", temp->name, temp->salary);
        temp = temp->next;
    }
}

int main() {
    struct Employee* head = NULL;
    int choice;
    char name[100];
    int salary;

    while (1) 
	{	
        printf("Menu:\n");
        printf("1. Add an employee\n");
        printf("2. Delete an employee\n");
        printf("3. Display the employee list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("Enter the employee name: ");
                scanf("%s", name);
                printf("Enter the employee salary: ");
                scanf("%d", &salary);
                insertEmployee(&head, name, salary);
                break;
            case 2:
                printf("Enter the employee name to be deleted: ");
                scanf("%s", name);
                deleteEmployee(&head, name);
                break;
            case 3:
                displayEmployees(head);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }

    return 0;
}

