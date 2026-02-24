#include<stdlib.h>
#include<stdio.h>

#define MAX 100

typedef struct Queue{
  int arr[MAX];  
  int front;
  int rear;
}Queue;

void intqueue(Queue*q){
    q->front=-1;
    q->rear=-1;
}

void enqueue(Queue*q,int x){
    if(q->rear==MAX-1){
        printf("Queue full");
        return;
    }else if(q->front == -1 && q->rear==-1){
        q->front=q->rear=0;
        q->arr[q->rear]=x;
    }else{
        q->rear=q->rear+1;
        q->arr[q->rear]=x;
    }
}

void dequeue(Queue*q){
    if(q->front==-1){
        printf("Queue is empty");
        return;
    }else if(q->front > q->rear){
        q->front=q->rear=-1;
        printf("Queue is empty");
        return;
    }else{
    printf("%d\n",q->arr[q->front]);
    q->front=q->front+1;
    }
}

int main(){
    Queue q;
    intqueue(&q);
    enqueue(&q,5);
    enqueue(&q,15);
    enqueue(&q,25);
    enqueue(&q,35);
    enqueue(&q,45);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
   

}