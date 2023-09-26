#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node {
    int data;
    struct queue_node* pre;
    struct queue_node* next;
} queue_node;

typedef struct Q {
    queue_node* head;
    queue_node* tail;
} Q;

Q* create_Q() {
    Q* q = (Q*)malloc(sizeof(Q));
    q->head = NULL;
    q->tail = NULL;

    return q;
}

void enqueue(Q* q, int data) {
    queue_node* new_node = (queue_node*)malloc(sizeof(queue_node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->pre = NULL;

    if (q->head == NULL) {
        q->head = new_node;
        q->tail = new_node;
    } else {
        q->tail->next = new_node;
        new_node->pre = q->tail;
        q->tail = q->tail->next;
    }
}

queue_node* dequeue(Q* q) {
    if (q->head == NULL) {
        return NULL;
    } else {
        queue_node* target = q->head;

        if (q->head == q->tail) {
            q->head = NULL;
            q->tail = NULL;
        } else {
            q->head->next->pre = NULL;
            q->head = q->head->next;
        }

        return target;
    }
}

int is_empty(Q* q) { return q->head == NULL; }

void print(Q* q) {
    queue_node* cur = q->head;
    while (cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    Q* q = create_Q();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);

    while (!is_empty(q)) {
        print(q);
        free(dequeue(q));
    }

    return 0;
}