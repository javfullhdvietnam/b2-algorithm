#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100  // Define the maximum stack size

// Structure for a website
typedef struct {
    char url[100];
    char title[100];
} Website;

// Structure for a stack
typedef struct {
    Website data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void init(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX - 1;
}

// Function to push a website onto the stack
void push(Stack *s, Website site) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++s->top] = site;
}

// Function to pop a website from the stack
Website pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        Website empty = {"", ""};
        return empty;
    }
    return s->data[s->top--];
}

// Function to display the stack contents
void display(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = s->top; i >= 0; i--) {
        printf("Title: %s, URL: %s\n", s->data[i].title, s->data[i].url);
    }
}

// Function to navigate backward
void back(Stack *backward, Stack *forward) {
    if (isEmpty(backward)) {
        printf("No previous website to go back to.\n");
        return;
    }
    Website site = pop(backward);
    push(forward, site);
    printf("Went back to: %s (%s)\n", site.title, site.url);
}

// Function to navigate forward
void forward(Stack *backward, Stack *forward) {
    if (isEmpty(forward)) {
        printf("No next website to go forward to.\n");
        return;
    }
    Website site = pop(forward);
    push(backward, site);
    printf("Went forward to: %s (%s)\n", site.title, site.url);
}

// Main function to test the functionality
int main() {
    Stack backward, forward;
    init(&backward);
    init(&forward);

    Website site1 = {"https://example.com", "Example"};
    Website site2 = {"https://google.com", "Google"};
    Website site3 = {"https://github.com", "GitHub"};

    // Push websites into the backward stack
    printf("Visiting websites:\n");
    push(&backward, site1);
    printf("Visited: %s (%s)\n", site1.title, site1.url);
    push(&backward, site2);
    printf("Visited: %s (%s)\n", site2.title, site2.url);
    push(&backward, site3);
    printf("Visited: %s (%s)\n", site3.title, site3.url);

    // Test backward navigation
    printf("\nNavigating Back:\n");
    back(&backward, &forward);
    back(&backward, &forward);

    // Test forward navigation
    printf("\nNavigating Forward:\n");
    forward(&backward, &forward);

    // Display current stacks
    printf("\nBackward Stack:\n");
    display(&backward);
    printf("\nForward Stack:\n");
    display(&forward);

    return 0;
}
