#include<stdio.h>
#include<stdlib.h>

typedef struct queue {
    int capacity;
    int front;
    int rear;
    int arr[100];
}queue;

typedef struct stack{
    queue q1;
    queue q2;
}stack;

void init_q(queue*q){
    q->front=-1;
    q->rear=-1;
    q->capacity=10;
}

void init_s(stack*s){
    init_q(&s->q1);
    init_q(&s->q2);
}

int isEmpty(queue*q){
    if(q->front==-1){
        return 1;
    }else{
        return 0;
    }
}

int isFull(queue*q){
    if(q->rear==q->capacity-1){
        return 1;
    }else{
        return 0;
    }
}

void enqueue(queue*q,int val){
    if(isEmpty(q)){
        q->front=q->rear=0;
        q->arr[q->rear]=val;
    }else if(isFull(q)){
        printf(" overflow");
    }else{
        q->rear++;
        q->arr[q->rear]=val;
    }
}

int dequeue(queue*q){
    if(isEmpty(q)){
        return -1;
    }
    int val=q->arr[q->front];
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }else{
        q->front++;
    }

    return val;
}

void push(stack*s,int val){
    if(!isFull(&s->q1)){
         enqueue(&s->q1,val);
    }
}

void pop(stack*s){
    if(!isEmpty(&s->q1)){
        while(s->q1.front<s->q1.rear){
          enqueue(&s->q2,dequeue(&s->q1));         
        }
        printf("%d\n",dequeue(&s->q1));

        while(!isEmpty(&s->q2)){
            enqueue(&s->q1,dequeue(&s->q2));
        }
    }
}

int main(){
    stack s;
    init_s(&s);
    push(&s,5);
    push(&s,15);
    push(&s,50);
    push(&s,60);
    push(&s,80);
    push(&s,90);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);

    return 0;
}

