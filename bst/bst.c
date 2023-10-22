#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *parnet;
    int data;
    struct node *left;
    struct node *right;
};

void push(struct node **head,int data){
    struct node *current = *head;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right=newnode->left=NULL;
    if(current==NULL){
        *head=newnode;
    }
    else{

        while(data>current->data && current->right!=NULL){
            current=current->right;
        }
        while(data<current->data && current->left!=NULL){
            current=current->left;
        }
        if(data>current->data){
        current->right=newnode;}
        else{
            current->left=newnode;
        }

    }
}

void recurpush(struct node **head,int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right=newnode->left=NULL;
    struct node *current = *head;
    if(current==NULL){
        *head=newnode;
    }
    else if(data>(*head)->data){
        recurpush(&(*head)->right,data);
    }
    else{
        recurpush(&(*head)->left,data);
    }
}



void inorder(struct node *head){
    if (head == NULL)
        return ;
    inorder(head->left);
    printf("%d ",head->data);
    inorder(head->right);
}


void postorder(struct node *head){
    if (head == NULL)
        return ;
    postorder(head->left);
    postorder(head->right);
    printf("%d ",head->data);
}

void preorder(struct node *head){
    if (head == NULL)
        return ;
    printf("%d ",head->data);
    preorder(head->left);
    preorder(head->right);

}

struct node *crenode(int data){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->right=newnode->left=NULL;
    return newnode;

}
int main(){
    int arr[] = {1,2,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    struct node *head =NULL;
    for(int i=0;i<size;i++){
        recurpush(&head,arr[i]);
    }

//    head->data=4;
//    head->left= crenode(2);
//    head->right = NULL;


    printf("inorder traversal :");inorder(head);printf("\n");
    printf("preorder traversal :");preorder(head);printf("\n");
    printf("postorder traversal :");postorder(head);printf("\n");

return 0;
}
