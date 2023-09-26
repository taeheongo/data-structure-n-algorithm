#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node {
    int data;
    struct stack_node* next;
} stack_node;

void push(stack_node** top, int data) {
    stack_node* new_node = (stack_node*)malloc(sizeof(stack_node));
    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

stack_node* pop(stack_node** top) {
    stack_node* tmp = *top;
    if (tmp) {
        *top = (*top)->next;
    }

    return tmp;
}

int main() {
    stack_node* top = NULL;

    push(&top, 1);
    push(&top, 2);
    push(&top, 4);
    push(&top, 3);

    while (top != NULL) {
        printf("%d ", top->data);
        pop(&top);
    }
    printf("\n");

    stack_node* top2 = NULL;

    push(&top2, 1);
    push(&top2, 4);
    push(&top2, 2);
    push(&top2, 3);

    while (top2 != NULL) {
        printf("%d ", top2->data);
        pop(&top2);
    }
    printf("\n");

    return 0;
}