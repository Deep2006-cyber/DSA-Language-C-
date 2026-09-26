#include<stdio.h>
#define max 100
int main(){
    int a[max],min,n;
    printf("\n Enter the number of elements: ");
    scanf("%d",&n);
    printf("\n Enter the elements: ");
    for(int k=0;k<n;k++)
    scanf("%d",&a[k]);
    printf("\n The original elements are: ");
    for(int k=0;k<n;k++)
        printf(" %d ",a[k]);
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(a[min] > a[j])
            min=j;
        }
    int temp=a[i];
    a[i]=a[min];
    a[min]=temp;
}
printf("\n The sorted elements are: ");
for(int k=0;k<n;k++)
    printf(" %d ",a[k]);
return 0;
}