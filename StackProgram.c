#include <stdio.h>
#include <windows.h>// For Computer Screen
#include <stdbool.h>// For Boolean Function

/* 
April 25, 2024
### Stack Program ### 
This code is in Industry Standard Coding Practices Format

@Authors: 
    Group 2 
    - Jimenez, Jenny 
    - Manduriaga, Emman 
    - Manlapaz, Arkhquiel
    - Sabordio, Augustin

The program allows users to push and pop values in an array, display top and all values in the array and check if stack is empty or not.
*/
#define intMax 100 //Maximum Element of Stack

struct Stack 
{
    int arrStack[intMax]; //For Stack Array
    int intTop;  // Index of the top element
};

// Initialize the stack
void init(struct Stack *s) 
{
    s->intTop = -1;  // Set top to -1 to indicate an empty stack
}

// Check if the stack is empty
bool isEmpty(struct Stack *s) {
    if (s->intTop == -1) 
        printf("Stack is empty\n");
     else 
        printf("Stack has %d elements\n", s->intTop + 1);

    return s->intTop == -1;
}


// Check if the stack is full
bool isFull(struct Stack *s) 
{
    return s->intTop == intMax - 1;  // If top is at the maximum index, stack is full
}

// Push an element in the stack
void push(struct Stack *s, int intElement) 
{
    if (!isFull(s)) 
        s->arrStack[++s->intTop] = intElement;  // Increment top and insert element
     else 
        printf("Error: Stack is full\n");
}

// Pop an element from the stack
int pop(struct Stack *s) 
{
    if (!isEmpty(s)) 
        return s->arrStack[s->intTop--];  // Decrement top and return the element
     else 
     {
        printf("Error: Stack is empty\n");
        return -1; // Return a default value indicating error
    }
}

// Get the top element of the stack
int topElement(struct Stack *s) {
    if (!isEmpty(s)) 
        return s->arrStack[s->intTop];  // Return the element at the top
     else 
     {
        printf("Error: Stack is empty\n");
        return -1; // Return a default value indicating error
    }
}

// Display all elements in the stack
void display(struct Stack *s) 
{
    if (!isEmpty(s)) 
    {
        printf("Stack elements:\n");
        for (int counter = s->intTop; counter >= 0; counter--) 
            printf("%d\n", s->arrStack[counter]);  // Print each element from top to bottom
    } 
    else 
        printf("Stack is empty\n");
}

// Main function 
int main() {
    struct Stack stack;
    init(&stack);
    int intChoice, intElement;

	//Do-While Loop for Continuous User Input
    do {
        // Display menu
        printf("Stack Menu:\n");
        printf("1: Push Element\n");
        printf("2: Pop Element\n");
        printf("3: Top Element\n");
        printf("4: Display Stack\n");
        printf("5: Check if Empty\n");
        printf("6: Check if Full\n");
        printf("7: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &intChoice);

        // Perform the selected operation
        switch (intChoice) {
            case 1:
                system("cls");
                printf("Enter element to push: ");
                scanf("%d", &intElement);
                push(&stack, intElement);
                printf("Element is pushed!\n\n");
                break;
            case 2:
                system("cls");
                printf("Popped element: %d\n", pop(&stack));
                printf("Element is popped!\n\n");
                break;
            case 3:
                system("cls");
                printf("Top element: %d\n", topElement(&stack));
                printf("Top element displayed!\n\n");
                break;
            case 4:
                system("cls");
                display(&stack);
                printf("Stack display completed!\n\n");
                break;
            case 5:
                system("cls");
                printf("Stack is %s\n", isEmpty(&stack) ? "empty" : "not empty\n\n"); // Ternary Operator for basic Logic. 
                break;
            case 6:
                system("cls");
                printf("Stack is %s\n", isFull(&stack) ? "full" : "not full\n\n"); // Ternary Operator for basic Logic.
                break;
            case 7:
                system("cls");
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                scanf("%d");
        }
    } while (intChoice != 7);

    return 0;
}
