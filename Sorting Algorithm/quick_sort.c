#include<stdio.h>
#define MAX 100
void swap(int a[],int l,int r){
    int temp=a[l];
    a[l]=a[r];
    a[r]=temp;
}
int partition(int a[],int low,int high){
    int pivot=a[high],i=low-1;
    for(int j=low;j<=high;j++){
        if(a[j]<pivot){
            i++;
            swap(a,i,j);
        }
    }
    swap(a,i+1,high);
    return i+1;
}
void quicksort(int a[],int low,int high){
    if(low<high){
        int p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}
void printarr(int a[],int size) {
       for (int i=0;i< size ;i++) {
           printf("%d ",a[i]);
       }
    printf("\n");
}
int main(){
    int arr[MAX],n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    for (int i=0;i<n;i++) {
        scanf("%d",&arr[i]);
    }
    printf("Original array:\n");
    printarr(arr,n);
    quicksort(arr,0,n-1);
    printf("Array after sorting:\n");
    printarr(arr,n);
    return 0;
}