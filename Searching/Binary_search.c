/*
Binary search is an efficient algorithm for finding an item from
a sorted list of items. It works by repeatedly dividing in half
the portion of the list that could contain the item, until you've
narrowed down the possible locations to just one.
One of the most common ways to use binary search is to find an
item in an array. For example, the Tycho-2 star catalog contains
information about the brightest 2,539,913 stars in our galaxy.
Suppose that you want to search the catalog for a particular star,
based on the star's name. If the program examined every star in the
star catalog in order starting with the first, an algorithm called
linear search O(n), the computer might have to examine all 2,539,913
stars to find the star you were looking for, in the worst case. If
the catalog were sorted alphabetically by star names, binary search
O(log n) would not have to examine more than 22 stars, even in the
worst case.

Binary Search: Search a sorted array by repeatedly dividing the search
interval in half. Begin with an interval covering the whole array. If
the value of the search key is less than the item in the middle of the
interval, narrow the interval to the lower half. Otherwise narrow it
to the upper half. Repeatedly check until the value is found or the
interval is empty.

The idea of binary search is to use the information that the array is
sorted and reduce the time complexity to O(Log n).
*/
#include <stdio.h>
#include <stdlib.h>

void binary_search(int arr[],int start,int end,int target);
int main()
{
    int arr[] = {2,5,9,12,13,17,19,20,25}/*Test cases*/;
    int start = 0,end,target;
    end = (sizeof(arr)/sizeof(int))-1;
    target = 13;/*Test input*/
    binary_search(arr,start,end,target);
    return 0;
}
void binary_search(int arr[],int start,int end,int target){
    int mid = 0;
    while(start <= end){
        mid = (start+end)/2;
        if(arr[mid] == target){
            printf("Target found on index arr[%d] = %d\n",mid,target);
            return;
        }else if(arr[mid] > target){
            end = (int)mid-1;
        }else{
            start = (int)mid+1;
        }
    }
    printf("Target not found.");
    return;
}
//*execution time : 0.164 s*//
