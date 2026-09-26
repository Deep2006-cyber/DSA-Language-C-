#include<stdio.h>
#include<stdlib.h>
#define max 30
int top=-1;
int stack[max];
void push(int x){
    if(top==max-1){
        printf("\n Stack overflow");
        return;
    }
    stack[++top]=x;
}
void pop(){
    if(top==-1){
        printf("\n Stack empty");
        return;
    }
    else{
        printf(" %d ",stack[top--]);
    }
}
void peek(){
    if(top==-1){
        printf("\n Stack empty");
        return;
    }
    else{
        printf(" %d ",stack[top]);
    }
}
void display(){
    if(top==-1){
        printf("\n Stack empty");
        return;
    }
    else{
        for(int i=top;i>=0;i--)
            printf(" %d ",stack[i]);
    }
}
void search(int x){
    if(top==-1){
        printf("\n The stack is empty");
    }
    else{
        int pos=-1;
        for(int i=0;i<=top;i++){
            if(stack[i]==x){
                pos=i+1;
                break;
            }
        }
        if(pos==-1)
            printf("\n Element not found");
        else
            printf("\n ELement found at position %d",pos);
    }
}
int main(){
    int op,a;
    while(1){
        printf("\n 1.Push\n 2.Pop\n 3.Display\n 4.Peek\n 5.Search\n 6.Exit");
        printf("\n Enter a option: ");
        scanf("%d",&op);
        switch(op){
            case 1:
            printf("\n Enter a number: ");
            scanf("%d",&a);
            push(a);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            peek();
            break;
            case 5:
            printf("\n Enter a number to search: ");
            scanf("%d",&a);
            search(a);
            break;
            case 6:
            exit(0);
            break;
            default:
            printf("\n Invalid option");
            break;
        }
    }
    return 0;
}