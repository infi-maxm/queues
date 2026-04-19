#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int capacity;
    int front;
    int rear;
    int arr[25];
}queue;

typedef struct stack{
    int sarr[25];
    int top;
    int capacity;
}stack;

void init_q(queue*q){
    q->front=-1;
    q->rear=-1;
    q->capacity=25;
}

void init_s(stack*s){
    s->top=-1;
    s->capacity=25;
}

void push(stack*s,int val){
    if(s->top==s->capacity-1){
        printf("Stack overflow");
    }else{
        s->top++;
        s->sarr[s->top]=val;
    }
}

int pop(stack*s){
    if(s->top==-1){
        printf("Stack underflow");
        return -1;
    }else{
        return s->sarr[s->top--];
    }

}

void enqueue(queue*q,stack*s){
    if(s->top==-1){
    return;
    }
    if(q->front==-1){
        q->front=0;
        q->rear=0;
        q->arr[q->rear]=pop(s);
        return;
    }else if(q->rear==q->capacity-1){
        return;
    }else{
        q->rear++;
        q->arr[q->rear]=pop(s);
    }

}

int dequeue(queue*q){
   
   if(q->front==-1){
    return -1;
   }

   int r=q->arr[q->front];

   if(q->front==q->rear){
    q->front=-1;
    q->rear=-1;
   }
   else{
     q->front++; 
   }

   return r;
}

int main(){
    stack s;
    queue q;

    init_q(&q);
    init_s(&s);

    push(&s,5);
    push(&s,10);
    push(&s,15);
    push(&s,20);


     for(int i=0;i<=s.top;i++){
        printf("%d ",s.sarr[i]);
    }

    while(s.top!=-1){
        enqueue(&q,&s);
    }

    while(q.front!=-1){
        push(&s,dequeue(&q));
    }

    for(int i=0;i<=s.top;i++){
        printf("f:%d ",s.sarr[i]);
    }

}




