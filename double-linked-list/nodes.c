#include <stdio.h>
#include <stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};

// lets insert at start
void insertstart(struct node **head,struct node **tail,int data) {
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->prev = NULL;
    p->next = *head;
    p->data = data;
    if (*head == NULL) {
        *head = p;
        *tail = p;
    } else {
        (*head)->prev = p;
        *head = p;
    }
}

// lets insert at end

void insertend(struct node **head,struct node **tail, int data){
    struct node *p = (struct node *) malloc(sizeof(struct node));
    p->data = data;
    p->next = NULL;
    p->prev = *tail;
    if(*tail == NULL){
        *head =p;
        *tail = p;
    }
    else{
        (*tail)->next = p;
        *tail = p;
    }
}

void insertany(struct node **head, int data,int target){
    struct node *current = *head;
    while(current->data!=target){
        current= current->next;
    }
    struct node *after;
    after = current->next;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->prev = current;
    newnode->next = after;
    after->prev = newnode;
    current->next = newnode;
}
//lets deleteany
void deleteany(struct node **head,int target){
    struct node *current = *head;
    struct node *previous,*after;
    while(current->data!=target){
        current= current->next;
    }
    previous = current->prev;
    after = current->next;
    previous->next = after;
    after->prev = previous;
    free(current);
}

// lets delete 1st
void deletefirst(struct node **head){
    struct node *current = *head;
    current=current->next;
    current->prev = NULL;
    free(*head);
    *head = current;
}

void deletelast(struct node **tail){
    struct node *previous= *tail;
    previous = previous->prev;
    previous->next=NULL;
    free(*tail);
    *tail = previous;
}
void trav(struct node *head){
    struct node *p ;
    p = head;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->next;
    }
}

void nodebetween(struct node **head,int price){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = price;
    struct node *current = *head;
    struct node *pre;
    while(current->next!=NULL || (newnode->data>=pre->data && newnode->data<current->data)){
        pre = current;
        current = current->next;

    }
    pre->next = newnode;
    current->prev = newnode;
    newnode->next = current;
    newnode->prev = pre;
}
void rev(struct node **tail){
    struct node *p;
    p=tail;
    while(p!=NULL){
        printf("%d ",p->data);
        p = p->prev;
    }
}
int ispresent(struct node **head,int target){
    struct node *current = *head;
    while(current!=NULL && current->data!=target){
        current=current->next;
    }
    if (current==NULL){
        return 0;
    }
    else{
        return 1;
    }

}
void intersection(struct node **head,struct node **head2,struct node **inter){
    int check;
    struct node *current = *head;
    struct node **temp =NULL;
    struct node **temptail = NULL;
    while(current!=NULL){
        check = ispresent(head2,current->data);
        if (check==1){
            insertstart(&temp,&temptail,current->data);
        }
        current= current->next;
    }
    *inter=temp;
}

void unionlist(struct node **head,struct node **head2,struct node **inter){
    int check;
    struct node *current = *head;
    struct node *current1 = *head2;
    struct node **temp1 =NULL;
    struct node **temptail1 = NULL;


    while(current!=NULL){
        check = ispresent(head2,current->data);
        if (check==0){
            insertstart(&temp1,&temptail1,current->data);
        }
        current= current->next;
    }
    while(current1!=NULL){
        check = ispresent(temp1,current1->data);
        if (check==0){
            insertstart(&temp1,&temptail1,current1->data);
        }
        current1= current1->next;
    }
    *inter=temp1;
}
int main(){
    struct node *head = NULL;
    struct node *tail = NULL;

    insertend(&head,&tail,35);
    insertend(&head,&tail,98);
    insertend(&head,&tail,45);

    struct node *head2 = NULL;
    struct node *tail2 = NULL;
    insertend(&head2,&tail2,48);
    insertend(&head2,&tail2,45);
    insertend(&head2,&tail2,65);

    struct node **inter=NULL;
    unionlist(&head,&head2,&inter);
    trav(inter);
    system("clear");
    return 0;
}
