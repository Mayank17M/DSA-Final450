/** 
 * Consider an array of distinct numbers sorted in increasing order. 
 * The array has been rotated (clockwise) k number of times. 
 * Given such an array, find the value of k. 
 * 
 * References: 
 *  https://www.geeksforgeeks.org/find-rotation-count-rotated-sorted-array/
 *  https://www.youtube.com/watch?v=4WmTRFZilj8
 */

#include<bits/stdc++.h>
using namespace std;

int countRotations(int arr[], int low, int high){
    int n = high+1;
    if(high < low) return 0;
    if (high == low) return low;
    while(low<=high){
        int mid = (high + low) / 2;
        int prev = (mid+n-1)%n;
        int next = (mid +1)%n;
        if(arr[mid]<=arr[next] && arr[mid]<=arr[prev]){
            return mid; 
        }
        else {
            if(arr[mid]>=arr[low] && arr[mid]<=arr[high]) return low; 
            else if(arr[mid]>=arr[low]){low=mid+1;}
            else if(arr[mid]<=arr[high]){high=mid-1;}
        }
    }
}

int main(){
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countRotations(arr, 0, n-1);
    return 0;
}

