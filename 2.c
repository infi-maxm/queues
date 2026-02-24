#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node*next;
}node;

void enqueue(node**front,node**rear,int x){
    node*newn=(node*)malloc(sizeof(node));
    newn->next=NULL;
    if(*front==NULL && *rear==NULL){
        *front=*rear=newn;
        newn->data=x;
    }else{
        (*rear)->next=newn;
        newn->data=x;
        *rear=newn;
    }
}

void dequeue(node**front,node**rear){
    if(*front==NULL && *rear==NULL){
        printf("Empty ll");
        return;
    }else if(*front==NULL){
        *rear=NULL;
        printf("Empty ll");
        return;
    }else{
        node*temp=*front;
        printf("%d\n",(*front)->data);
        (*front)=(*front)->next;
        free(temp);
    }
}

int main(){
    node*front=NULL;
    node*rear=NULL;

    enqueue(&front,&rear,10);
    enqueue(&front,&rear,20);
    enqueue(&front,&rear,30);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    dequeue(&front,&rear);
    
}