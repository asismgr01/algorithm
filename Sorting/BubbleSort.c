/*Bubble sort is a simple and well-known sorting algorithm.In this algorithm, we 
 start with iterating over an array and compare the first element to the second 
 one and swap them if they are in the wrong order and then compare the second and
 the third one and so on. After this iteration, the largest element goes to the 
 last of the array. Now the largest element is already in the last position, so we
 again repeat this process, leaving the elements which are already in their correct
 positions and this gives us a sorted array. Bubble sort belongs to O(n2) sorting 
 algorithms, which makes it quite inefficient for sorting large data volumes. Bubble 
 sort is stable and adaptive.

 Complexity analysis

 Average and worst case complexity of bubble sort is O(n2). Also, it makes O(n2) swaps
 in the worst case. Bubble sort is adaptive. It means that for almost sorted array it 
 gives O(n) estimation. Avoid implementations, which don't check if the array is already
 sorted on every step (any swaps made). This check is necessary, in order to preserve 
 adaptive property.*/

#include <stdio.h>
#include <stdlib.h>
void bubblesort(int arr[],int len);
void printarr();
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};//test case//
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
