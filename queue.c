#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int customerNumber;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

int isEmpty(Queue q) {
    if (q.front == NULL) {
        return 1;
    }
    return 0;
}

void enqueue(Queue* q, int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->customerNumber = number;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->front == NULL) {
        return -1;
    }
    Node* temp = q->front;
    int number = temp->customerNumber;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return number;
}

int peekQueue(Queue q) {
    if (q.front == NULL) {
        return -1;
    }
    return q.front->customerNumber;
}

int main() {
    Queue q;
    initQueue(&q);
    int choice, customerNum;

    do {
        printf("\n--- Bank Queue Menu ---\n");
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. View Next Customer\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter customer number: ");
                scanf("%d", &customerNum);
                enqueue(&q, customerNum);
                break;
            case 2:
                customerNum = dequeue(&q);
                if (customerNum == -1) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Served customer: %d\n", customerNum);
                }
                break;
            case 3:
                customerNum = peekQueue(q);
                if (customerNum == -1) {
                    printf("Queue is empty!\n");
                } else {
                    printf("Next customer: %d\n", customerNum);
                }
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
```[cite: 2]