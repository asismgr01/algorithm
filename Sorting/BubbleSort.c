#include <stdio.h>
#include <stdlib.h>
void bubblesort(int arr[],int len);
void printarr();
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = (sizeof(arr)/sizeof(arr[0]))-1;
    bubblesort(arr,n);
    printarr(arr,n);
    return 0;
}
void bubblesort(int arr[],int len){
    int i,j,temp;
    for(i=0;i<=len;i++){
        for(j=0;j<=len-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void printarr(int arr[],int len){
    int i;
    for(i=0;i<=len;i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}
