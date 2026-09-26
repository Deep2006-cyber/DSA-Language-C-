#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int priority;
    struct node *next;
}QNode;
typedef struct Node{
    QNode *front;
    QNode *rear;
}Queue;
QNode* CreateNode(){
    QNode* newnode=(QNode*)malloc(sizeof(QNode));
    if(!newnode)
        return NULL;
    printf("\n Enter the data: ");
    scanf("%d",&newnode->data);
    printf("\n Enter the priority: ");
    scanf("%d",&newnode->priority);
    newnode->next=NULL;
    return newnode;
}
void Enqueue(Queue *q){
    QNode *newnode=CreateNode();
    if(q->rear==NULL){
        q->front=q->rear=newnode;
    }
    else{
        QNode *temp=q->front;
        if((q->front->priority)>(newnode->priority)){
            newnode->next=q->front;
            q->front=newnode;
        }
        else{
        while((temp->next!=NULL) && (temp->next->priority)<=(newnode->priority))
            temp=temp->next;
        newnode->next=temp->next;
        temp->next=newnode;
        if (newnode->next==NULL)
        q->rear=newnode;
        }
    }
}
void Dequeue(Queue *q){
    if(q->rear==NULL){
        printf("\n The queue is empty");
        return;
    }
    else if(q->front->next==NULL){
        printf("\n %d",q->front->data);
        QNode *temp=q->front;
        q->front=NULL;
        q->rear=NULL;
        free(temp);
    }
    else{
        QNode *temp=q->front;
        q->front=q->front->next;
        printf("\n %d",temp->data);
        temp->next=NULL;
        free(temp);
    }
}
void Display(Queue *q){
    QNode *temp;
    if(q->rear==NULL)
        printf("\n The queue is empty");
    else{
        temp=q->front;
        while(temp){
            printf("data:%d priority:%d\n",temp->data,temp->priority);
            temp=temp->next;
        }
    }
}
int main(){
    Queue q={NULL,NULL};
    int a;
    while(1){
        printf("\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit");
        printf("\n Enter a option: ");
        scanf("%d",&a);
        switch(a){
            case 1:
                Enqueue(&q);
                break;
            case 2:
                Dequeue(&q);
                break;
            case 3:
                Display(&q);
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\n Invalid option");
                break;
        }
    }
    return 0;
}