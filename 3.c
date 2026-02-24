#include<stdio.h>
#include<stdlib.h>

#define capacity 5

typedef struct queue{
    int arr[capacity];
    int front;
    int rear;
}Queue;

void initqueue(Queue*q){
    q->front=-1;
    q->rear=-1;
}

void enqueue(Queue*q,int x){
    if(q->front==-1 && q->rear==-1){
        q->front=q->rear=0;
        q->arr[q->rear]=x;
        return ;
    }else if(q->front==(q->rear+1)%capacity){
        q->rear=0;
    }else{
        q->rear=(q->rear + 1)%capacity;
        q->arr[q->rear]=x;
    }
}

void dequeue(Queue*q){
    if(q->front==-1 && q->rear==-1){
        printf("Empty queue");
        return;
    }else if(q->front==(q->rear + 1)%capacity){
        q->rear=q->front=-1;
    }else{
        printf("%d\n",q->arr[q->front]);
        q->front=(q->front + 1)%capacity;
    }
}

int main(){
    Queue q;
    initqueue(&q);
    enqueue(&q,5);
    enqueue(&q,54);
    enqueue(&q,55);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q,6);
    enqueue(&q,62);
    enqueue(&q,64);
    dequeue(&q);
}