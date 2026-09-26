#include <stdio.h>
void Insertion_Sort(int arr[],int n){
    int i,j,key;
    for(i=0;i<n;i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void print__array(int arr[],int n){
    for(int i=0;i<n;i++){
         printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[20],n,i;
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
printf("The sorted array is:-\n");
print__array(arr,n);
Insertion_Sort(arr,n);
printf("The sorted array is:->");
print__array(arr,n);
return 0;
}