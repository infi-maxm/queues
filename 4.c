#include<stdio.h>
#include<stdlib.h>

#define MAX 50

typedef struct Stack{
    int top;
    int arr[50];
}Stack;

typedef struct Queue{
    Stack stack1;
    Stack stack2;
}Queue;

void initStack(Stack*s){
    s->top=-1;
}

int isEmpty(Stack*s){
    if(s->top==-1){
        return 1;
    }else{
        return 0;
    }
}

void push(Stack*s,int value){
    if(s->top==MAX-1){
        return;
    }else{
        s->top++;
        s->arr[s->top]=value;
    }
}

int pop(Stack*s){
    if(isEmpty(s)){
        return -1;
    }else{
        return s->arr[s->top--];
    }
}

void initQueue(Queue*q){
    initStack(&q->stack1);
    initStack(&q->stack2);
}

void enqueue(Queue*q,int value){
    push(&q->stack1,value);
}

int dequeue(Queue*q){
    if(isEmpty(&q->stack2)){
        while(!isEmpty(&q->stack1)){
            push(&q->stack2,pop(&q->stack1));
        }
    }
    return pop(&q->stack2);
}

int main(){

    Queue q;
    initQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    printf("%dn",dequeue(&q));
    printf("%d\n",dequeue(&q));

    return 0;
}