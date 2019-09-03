/*
 Insertion sort works in the similar way as we sort cards in our hand in a card game.

 We assume that the first card is already sorted then, we select an unsorted card. If
 the unsorted card is greater than the card in hand, it is placed on the right otherwise,
 to the left. In the same way, other unsorted cards are taken and put at their right place.
 A similar approach is used by insertion sort. Insertion sort is a sorting algorithm that
 places an unsorted element at its suitable place in each iteration.Insertion sort is not
 the best sorting algorithm in terms of performance as compared to bubble sort and selection
 sort. But it’s little more efficient than selection sort and bubble sort in practical
 scenarios. Insertion sort is also pretty intuitive sorting technique.

 This algorithm is not suitable for large data sets as its average and worst case complexity
 are of Ο(n2), where n is the number of items.
*/

#include <stdio.h>
#include <stdlib.h>
void display(int arr[],int size);
void InsertionSort(int arr[],int size);
int main()
{
    int arr[] = {4,3,2,10,12,1,5,6};/*test cases*/
    int size = (sizeof(arr)/sizeof(int))-1;
    printf("Unsorted array.\n");
    display(arr,size);/*unsorted array*/
    InsertionSort(arr,size);
    printf("Sorted array.\n");
    display(arr,size);/*sorted array*/
    return 0;
}
void InsertionSort(int arr[],int size){
    int temp;
    for(int i=1;i<=size;i++){
        for(int j=i;j>=1;j--){
            if(arr[j]<arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
    }
}
void display(int arr[],int size){
    for(int i=0;i<=size;i++){
        printf("arr[%d] = %d\n",i,arr[i]);
    }
}
