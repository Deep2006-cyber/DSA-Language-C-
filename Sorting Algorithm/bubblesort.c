#include<stdio.h>
#define max 20
int main(){
    int a[max],n,temp;
    printf("Enter the size: ");
    scanf("%d",&n);
    printf("\n Enter the elements to sort: ");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("\n The original array is: ");
    for(int i=0;i<n;i++)
        printf(" %d ",a[i]);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    printf("\n The sorted array is: ");
    for(int i=0;i<n;i++){
        printf(" %d ",a[i]);
    }
    return 0;
}