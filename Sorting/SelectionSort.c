/*
 #Selection Sort

 The selection sort algorithm sorts an array by repeatedly finding the
 minimum element (considering ascending order) from unsorted part and
 putting it at the beginning. The algorithm maintains two subarrays in
 a given array.

 1) The subarray which is already sorted.
 2) Remaining subarray which is unsorted.

 In every iteration of selection sort, the minimum element (considering
 ascending order) from the unsorted subarray is picked and moved to the
 sorted subarray.

 #Complexity Analysis

 Selection sort is a sorting algorithm that has O(n²) time complexity.
 O(n²) isn’t a good time complexity for sorting lists when it comes to
 large input sizes. This algorithm sorts an array or list by repeatedly
 finding the minimum value (if we are sorting in ascending order) from
 the list or array and placing it at the beginning of the list.
 */

#include <stdio.h>
#include <conio.h>
int main(void){
    int arr[10],i,j,temp;
    printf("Enter ten numbers for array.\n");
    for(i=0;i<10;i++){
        printf("\nEnter the number: ");
        scanf("%d",&arr[i]);
    }
    printf("\nUnsorted Array");
    for(i=0;i<10;i++){
        printf("\nArray[%d]=%d",i,arr[i]);
    }
    printf("\nSelection Sort");
    for(i=0;i<10;i++){
        for(j=i;j<10;j++){
            if(arr[i]>arr[j+1]){
                temp=arr[i];
                arr[i]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(j=0;j<10;j++){
        printf("\nArray[%d]=%d",j,arr[j]);
    }

}
