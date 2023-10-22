#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value){
    struct node *p;
    p= (struct node *)malloc(sizeof(struct node));
    p->data = value;
    p->next = NULL;
    if((front == NULL)&&(rear==NULL)){
        front = rear = p;
    }else{
        rear->next = p;
        rear = p;
    }
    printf("node is inserted\n");
}

int dequeue(){
    if(front == NULL){
        printf("\n underflow\n");
        return -1;
    }
    else{
        struct node *temp = front;
        int temp_data = front->data;
        front = front ->next;
        free(temp);
        return temp_data;
    }
}

void display(){
    struct node *temp;
    if((front == NULL)&&(rear == NULL)){
        printf("\nqueue is empty\n");
    }else{
        printf("the queue is \n");
        temp = front;
        while(temp){
            printf("%d-->",temp->data);
            temp=temp->next;};
     }
    printf("\n");
    }



int main(){
    int ch,val;
    int run=1;
    while(run==1){
    printf("1]enqueue\n2]dequeue\n3]display\n4]exit\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch (ch) {
        case 1:
            printf("enter the value:");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 2:
            printf("element removed:%d",dequeue());
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            run=0;
            break;
        default:
            printf("\nwrong choice\n");
    }}
}
