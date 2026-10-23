#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

int isEmpty(Stack s) {
    return s.top == NULL;
}

void push(Stack* s, char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

char pop(Stack* s) {
    if (isEmpty(*s)) {
        printf("Stack is empty!\n");
        return 0;
    }
    Node* temp = s->top;
    char poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}

char peek(Stack s) {
    if (s.top == NULL) {
        printf("Stack is empty \n");
        return '\0';
    }
    return s.top->data;
}

int evaluatePostfix(char* exp) {
    Stack s;
    initStack(&s);
    int i = 0;
    while (exp[i] != '\0') {
        if (exp[i] >= '0' && exp[i] <= '9') {
            push(&s, exp[i] - '0');
        } 
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/') {
            int val2 = pop(&s);
            int val1 = pop(&s);
            switch (exp[i]) {
                case '+':
                    push(&s, val1 + val2);
                    break;
                case '-':
                    push(&s, val1 - val2);
                    break;
                case '*':
                    push(&s, val1 * val2);
                    break;
                case '/':
                    push(&s, val1 / val2);
                    break;
            }
        }
        i++;
    }
    return pop(&s);
}

int main() {
    Stack s;
    initStack(&s);
    int choice;
    char exp[100];

    do {
        printf("\n--- Menu ---\n");
        printf("1. Push / Pop / Display\n");
        printf("2. Evaluate Postfix Expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Operations on stack can be tested here.\n");
                break;
            case 2:
                printf("Enter a postfix expression: ");
                scanf("%s", exp);
                int result = evaluatePostfix(exp);
                printf("Result = %d\n", result);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}