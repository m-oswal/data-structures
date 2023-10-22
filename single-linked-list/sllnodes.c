#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
// lets create function to add the node to the start
void insertstart(struct node **head,int data){
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->next = *head;
    *head = p;
}
void deletefirst(struct node**head){
    struct node *current = *head;

    if(current!=NULL){
        (*head)=current->next;
    }
    free(current);
}

void deletelast(struct node **head) {
    struct node *current = *head;
    struct node *prev = NULL;

    if (current == NULL) {
        return;
    }

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev != NULL) {
        prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(current);
}

void deleteodd(struct node **head){
    int pos=0;
    struct node *current = *head;
    struct node *pre;
    while(current!=NULL){
        if(pos==0){
            struct node *temp = current;
            current=current->next;
            free(temp);
            *head = current;
            pos++;
        }else{
            if(pos%2!=0){
                pre = current;
                current=current->next;
                pos++;
            }
            else{
                pos++;
                struct node *temp=current;
                current=current->next;
                pre->next = current;
                free(temp);
            }
        }
    }
}
//lets create to add at the end
void insertend(struct node **head,int data){
    if(*head == NULL){
        *head = malloc(sizeof(struct node));
        (*head)->data=data;
        (*head)->next = NULL;}
    else{
        struct node *p = *head;

        while(p->next!=NULL){
            p=p->next;
        }
        struct node *new_node =(struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->next = NULL;
        p->next = new_node;
    }
}

//now the fun part insert any

void insertany(struct node **head,int data,int index){
    int count = 0;//will use this to check if we reached the desired index
    struct node *p = *head;
    while(p!=NULL && count<index-1){
        p=p->next;
        count++;
    }
    struct node *new_node =(struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = p->next;
    p->next = new_node;

}

// now to delete any

void deleteany(struct node **head,int target){
    struct node *current = *head;
    struct node *prev = NULL;

    while (current->data!=target){
        prev=current;
        current = current->next;
    }
    if(prev!=NULL){
    prev ->next = current->next;
    free(current);}
    else{
        *head = current->next;
        free(current);
    }
}

//a function to transverse the list
void trav(struct node *head){
    struct node *p ;
    p = head;
    while(p!=NULL){
        printf("%d\n",p->data);
        p = p->next;
    }
}

//insert by compare

int main(){
    struct node *head = NULL;

    insertend(&head,45);
    insertend(&head,8);
    insertend(&head,90);
    insertend(&head,67);
    insertend(&head,98);
    deletelast(&head);
   deleteodd(&head);
    trav(head);


    return 0;
}
