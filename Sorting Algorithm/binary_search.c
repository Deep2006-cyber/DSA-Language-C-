#include <stdio.h>
int bin_search(int a[],int n,int key){
    int l=0;
    int h=n-1;
    while(l<=h){
        int mid=(l+h)/2;
        if (a[mid]==key)
        return mid;
        else if (a[mid]<key)
        l=mid+1;
        else 
        h=mid-1;    
    }
    return -1;
}
int main(){
    int n,terget, a[20];
    printf("Enter the size of array:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
printf("Enter the terget to find:");
scanf("%d",&terget);
int result=bin_search(a,n,terget);
if(result!=-1)
printf("data found at %d position",result);
else
printf("data not found");
return 0;
}