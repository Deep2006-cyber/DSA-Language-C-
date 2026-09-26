#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define N 15
int f=-1,r=-1;
int queue[N];
void enqueue(int n){
    if(r>N-1)
        printf("\n Queue is full");
    else{
        if(f==-1)
            f=0;
        queue[++r]=n;
    }
}
int dequeue(){
    int n;
    if(f==-1)
        return INT_MIN;
    else{
        n=queue[f++];
        if(f>r)
        f=r=-1;
        return n;
    }
}
int peek(){
    int n;
    if(f==-1)
        return INT_MIN;
    else
        return queue[f];
}
void Empty_queue(){
    if(f==-1)
        return;
    while(f!=-1)
        dequeue();
}
int IsEmpty(){
    return f==-1;
}
void print_queue(){
    if(f==-1)
    printf("\n The Queue is empty");
    else{
        for(int i=f;i<=r;i++)
        printf(" %d ",queue[i]);
    }
}
int main(){
    int a,m;
    while(1){
    printf("\n 1.Enqueue\n 2.Dequeue\n 3.Print\n 4.Exit");
    printf("\n Enter a option: ");
    scanf("%d",&a);
        switch(a){
            case 1:
            printf("\n Enter the data: ");
            scanf("%d",&m);
            enqueue(m);
            break;
            case 2:
            m=dequeue();
            if(m==INT_MIN)
                printf("\n Queue is empty");
            else
                printf("\n The element is: %d",m);
            break;
            case 3:
            print_queue();
            break;
            case 4:
            exit(0);
            default:
            printf("\n Invalid option");
        }

    }
return 0;
}