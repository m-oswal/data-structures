#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if (front == NULL) {
        front = rear = newnode;
    }
    else {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return -1;  // Return a sentinel value or handle error as needed
    }
    struct node* temp = front;
    int data = temp->data;
    front = front->next;
    free(temp);
    return data;
}

int isEmpty() {
    return front == NULL;
}

void peek() {
    if (front == NULL) {
        printf("Queue is empty\n");
    }
    else {
        printf("Front data: %d\n", front->data);
    }
}

void display() {
    struct node* temp = front;
    if (temp == NULL) {
        printf("Queue Empty\n");
    }
    else {
        while (temp != NULL) {
            printf("Element = %d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {

    int i = 0; // Start from node 0
    int visited[7] = {0};
    int a[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}
    };

    printf("%d ", i);
    visited[i] = 1;
    enqueue(i); // Enqueue i for exploration

    while (!isEmpty()) {
        int node = dequeue();
        for (int j = 0; j < 7; j++) {
            if (a[node][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

    display();

    return 0;
}
