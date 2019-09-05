#include <stdio.h>
#include <stdlib.h>

int binarysearch_recursive(int arr[],int start,int end,int target);
int main()
{
    int arr[] = {2,3,7,10,11,14,19,22,25,29,30,32};//test cases
    int start = 0;
    int end = (sizeof(arr)/sizeof(int))-1;
    int target = 11;// input test case
    printf("Target number is on index arr[%d].",binarysearch_recursive(arr,start,end,target));
    return 0;
}
// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarysearch_recursive(int arr[],int start,int end,int target){
    if(end >=1){
        int mid = (start+end)/2;
        // If the element is present at the middle itself
        if(arr[mid] == target){
            return mid;
        }
        // If element is smaller than mid, then it can only be present
        // in left subarray
        else if(arr[mid] > target){
            return binarysearch_recursive(arr,start,mid-1,target);
        }
        // Else the element can only be present in right subarray
        else{
            return binarysearch_recursive(arr,mid+1,end,target);
        }
    }
    // We reach here when element is not present in array
    return -1;
}
