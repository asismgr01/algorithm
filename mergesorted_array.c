#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[] = {1,4,5,7,9,10};/*test case*/
    int arr1[] = {2,3,6,8,11,12,13};/*test case*/
    int size = sizeof(arr)/sizeof(int);/*size of arr*/
    int size1 = sizeof(arr1)/sizeof(int);/*size of arr1*/
    int size2 = size+size1;/*size of arr[] + size of arr1[]*/
    int arr2[size2];/*new array to store data of arr[] & arr1[] for merging,size of arr2[] = size of arr[] + size of arr1[]*/
    merge_sortedarray(arr,size,arr1,size1,arr2);/*merge function called*/
    /*traverse arr2[]*/
    for(int i=0;i<size2;i++){
        printf("arr2[%d] = %d\n",i,arr2[i]);
    }
    return 0;
}
/*function to merge two sorted array*/
int merge_sortedarray(int arr[],int size,int arr1[],int size1,int arr2[]){
    int i=0,j=0,k=0;
    // Traverse both array
    while(i<size && j<size1){
        // Check if current element of arr[]
        // is smaller than current element
        // of arr1[]. If yes, store first
        // array element of arr[] in arr2[] and increment
        // arr[] index. Otherwise do same
        // with arr1[]
        if(arr[i]<arr1[j]){
            arr2[k] = arr[i];
            i++;
        }else{
            arr2[k] = arr1[j];
            j++;
        }
        k++;
    }
    /*Store remaining elements of arr[]*/
    while(i<size){
        arr2[k] = arr[i];
        i++;
        k++;
    }
    /*Store remaining elements of arr1[]*/
    while(j<size1){
        arr2[k] = arr1[j];
        j++;
        k++;
    }
    return arr2;/*return updated value of arr2[] to main function*/
}
