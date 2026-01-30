#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_URL_LENGTH 100

// Stack structure
typedef struct {
    char items[MAX_STACK_SIZE][MAX_URL_LENGTH];
    int top;
} Stack;

// BrowserHistory structure
typedef struct {
    char currentPage[MAX_URL_LENGTH];
    Stack backStack;
    Stack forwardStack;
} BrowserHistory;

/* ---------- Stack Functions ---------- */

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack *stack, const char *url) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    strcpy(stack->items[++stack->top], url);
}

char* pop(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->items[stack->top--];
}

void clearStack(Stack *stack) {
    stack->top = -1;
}

/* ---------- BrowserHistory Functions ---------- */

void initBrowserHistory(BrowserHistory *bh, const char *homepage) {
    strcpy(bh->currentPage, homepage);
    initStack(&bh->backStack);
    initStack(&bh->forwardStack);
}

void visit(BrowserHistory *bh, const char *url) {
    push(&bh->backStack, bh->currentPage);
    strcpy(bh->currentPage, url);
    clearStack(&bh->forwardStack);
}

const char* back(BrowserHistory *bh) {
    if (isEmpty(&bh->backStack)) {
        printf("No page to go back to\n");
        return bh->currentPage;
    }
    push(&bh->forwardStack, bh->currentPage);
    strcpy(bh->currentPage, pop(&bh->backStack));
    return bh->currentPage;
}

const char* forward(BrowserHistory *bh) {
    if (isEmpty(&bh->forwardStack)) {
        printf("No page to go forward to\n");
        return bh->currentPage;
    }
    push(&bh->backStack, bh->currentPage);
    strcpy(bh->currentPage, pop(&bh->forwardStack));
    return bh->currentPage;
}

void showStatus(BrowserHistory *bh) {
    int i;

    printf("Current Page: %s\n", bh->currentPage);

    printf("Back Stack: ");
    for (i = 0; i <= bh->backStack.top; i++) {
        printf("%s ", bh->backStack.items[i]);
    }
    printf("\n");

    printf("Forward Stack: ");
    for (i = 0; i <= bh->forwardStack.top; i++) {
        printf("%s ", bh->forwardStack.items[i]);
    }
    printf("\n--------------------------------\n");
}

/* ---------- Example Usage ---------- */

int main() {
    BrowserHistory bh;

    initBrowserHistory(&bh, "home.com");
    visit(&bh, "google.com");
    visit(&bh, "openai.com");
    showStatus(&bh);

    back(&bh);
    showStatus(&bh);

    forward(&bh);
    showStatus(&bh);

    return 0;
}
