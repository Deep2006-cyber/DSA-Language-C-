#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 30
struct node{
    char data;
    struct node *next;
};
char input[max],output[max];
int ind=0;
struct node *top=NULL;
int precedence(char a){
    if (a=='^')
        return 3;
    else if(a=='/' || a=='*')
        return 2;
    else if(a=='+' || a=='-')
        return 1;
    else
        return 0;
}
void push(char a){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=a;
    if(top==NULL){
        newnode->next=NULL;
        top=newnode;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
}
char pop(){
    if(top==NULL)
    return '\0';
    else{
        struct node *temp=top;
        top=top->next;
        char b=temp->data;
        temp->next=NULL;
        free(temp);
        return b;
    }
}
char peek(){
    if(top==NULL)
        return '\0';
    else
        return top->data;
}
int isOperand(char s){
    if(s=='+'|| s=='-'|| s=='*'|| s=='/' || s=='(' || s==')'|| s=='^')
        return 0;
    else
        return 1;
}
int isEmpty(){
    if(top==NULL)
        return 1;
    return 0;
}
int main(){
    int i=0;
    printf("\n Enter the infix equation: ");
    fgets(input,max-1,stdin);
    input[strcspn(input, "\n")] = '\0'; 
    while(input[i]!='\0'){
        char ch=input[i];
        if(isOperand(ch)){
            output[ind]=ch;
            ind++;   
        }
        else if(ch=='('){
            push(ch);
        }
        else if(ch==')'){
            while('('!=peek() && !isEmpty()){
                output[ind]=pop();
                ind++;
            }
            pop();
        }
        else{
            if(ch=='^'){
                while(!isEmpty() &&  peek()!='(' && precedence(peek())>precedence(ch))
                output[ind++]=pop();
            }
           else {
                while(!isEmpty() && peek() != '(' && precedence(peek()) >= precedence(ch)) {
                    output[ind++] = pop();
                }
            }
            push(ch);
        }
        i++;
    }
    while(!isEmpty()){
        output[ind]=pop();
         ind++;
    }
    output[ind]='\0';
    printf("\n The postfix expression is: %s",output);
    return 0;
}