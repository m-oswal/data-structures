#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

// to insert start
void insert_first(struct node **head,int data){
    struct node *temp;
    temp = *head;

    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(temp ==NULL){
        (*head)=newnode;
    }else{
        newnode->next = (*head);
        (*head) = newnode;
    }
}
// to insert at end.
void insert_end(struct node **head,int data){
    struct node *temp;
    temp = (*head);
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if(temp ==NULL){
        (*head)=newnode;}
    else{
        while(temp->next!=NULL){
            temp=temp->next;}
        temp->next = newnode;
    }
}

//to insert anywhere
void insert_any(struct node **head,int pos,int data){
    struct node *temp;
    struct node *prev=NULL;
    temp = (*head);
    struct node* newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    int count=0;
    while(temp!=NULL && temp->next!=NULL && count<pos){
        prev=temp;
        temp=temp->next;
        count++;
    }
    if(count==pos){
        if(prev!=NULL){
        prev->next = newnode;
        newnode->next = temp;}
        else{
            newnode->next = (*head);
            (*head)=newnode;

        }
    }else{
        printf("pos doesnt exist");
        free(newnode);
    }
}


void delete_first(struct node **head){
    struct node *temp;
    temp = (*head);
    (*head)= temp->next;
    free(temp);
}

//delete last
void delete_last(struct node **head){
    struct node *temp;
    struct node*prev;
    temp = (*head);
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    if(prev!=NULL){
        prev->next =NULL;
    }else{
        (*head)=NULL;
    }
    free(temp);
}

//delete any

void delete_any(struct node **head,int data){
    struct node *temp;
    struct node *prev=NULL;
    temp = (*head);

    while(temp->next!=NULL && temp->data !=data){
        prev = temp;
        temp=temp->next;
    }

    if(prev!=NULL){
        prev->next =temp->next;
        free(temp);
    }else{
        (*head)=temp->next;
        free(temp);
    }
}

//delete any pos

void delete_pos(struct node **head,int pos){
    struct node *temp;
    struct node *prev=NULL;
    temp = (*head);
    int count=0;
    while(temp->next!=NULL && count<pos){
        prev = temp;
        temp=temp->next;
        count++;
    }
    if(count==pos){
    if(prev!=NULL){
        prev->next =temp->next;
        free(temp);
    }else{
        (*head)=temp->next;
        free(temp);
    }}
    else{
        printf("not found");
    }
}

//reverse list
void rev(struct node **head,struct node **head2){
    struct node *temp;
    temp=(*head);

    while(temp!=NULL){
        insert_first(head2,temp->data);
        temp = temp->next;
    }
}
void display(struct node *head){
    struct node* temp =head;
    while(temp!=NULL){
        printf("%d ->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

// we will concatenate 2 list now

void conc(struct node **head,struct node **head2){
    struct node *temp;
    temp=(*head);

    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = (*head2);
}
int main() {
    struct node* head = NULL;
    struct node* head2 = NULL;
    int choice, data, pos;
    while (1) {
        printf("\nLinked List Menu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete at a specific position\n");
        printf("7. Reverse the list\n");
        printf("8. Display the list\n");
        printf("9. Concatenate with another list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insert_first(&head, data);
                break;

            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insert_end(&head, data);
                break;

            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &pos);
                insert_any(&head, pos, data);
                break;

            case 4:
                delete_first(&head);
                break;

            case 5:
                delete_last(&head);
                break;

            case 6:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                delete_any(&head, data);
                break;

            case 7:
                rev(&head, &head2);
                printf("List reversed.\n");
                break;

            case 8:
                printf("Current List: ");
                display(head);
                break;

            case 9:
                printf("Concatenating with another list.\n");
                conc(&head, &head2);
                break;

            case 0:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
