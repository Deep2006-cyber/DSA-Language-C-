#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define max 30
struct node{
    char data;
    struct node *next;
};
char infix[max],output[max];
int stack[max],top_eval=-1;
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
void push_eval(int x){
    if(top_eval>max-1){
        printf("\n Stack overflow");
        return;
    }
    stack[++top_eval]=x;
}
int pop_eval(){
    if(top_eval==-1){
        printf("\n stack underflow");
        return -1;
    }
    return stack[top_eval--];
}
int post_eval(char post[]){
    int i=0,a,b,c;
    char ch;
    while(post[i]!='\0'){
        ch=post[i];
        if(isOperand(ch))
        push_eval(ch-'0');
        else{
            a=pop_eval();
            b=pop_eval();
            switch(ch){
                case '+':
                    c=a+b;
                    break;
                case '-':
                    c=b-a;
                    break;
                case '*':
                    c=b*a;
                    break;
                case '/':
                    c=b/a;
                    break;
                case '^':
                    c=pow(b,a);
                    break;
            }
            push_eval(c);
        }
        i++;
    }
    return pop_eval();
}
int main(){
    int i=0;
    char p;
    printf("\n Enter the infix equation: ");
    fgets(infix,max-1,stdin);
    infix[strcspn(infix, "\n")] = '\0';
    while(infix[i]!='\0'){
        char ch=infix[i];
        if(isOperand(ch)){
            output[ind]=ch;
            ind++;   
        }
        else if(ch==')'){
            while('('!=peek() && !isEmpty()){
                output[ind]=pop();
                ind++;
            }
            pop();
        }
        else if(ch=='('){
            push(ch);
        }
        else{
            if(ch=='^'){
                while(!isEmpty() && precedence(peek())>precedence(ch) && peek()!='(')
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
    printf("\n The output expression is: %s",output);
    printf("\n The postfix evaluation is: %d",post_eval(output));
    return 0;
}