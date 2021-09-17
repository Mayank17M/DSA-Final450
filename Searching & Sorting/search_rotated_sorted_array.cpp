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

/** 
 * @brief Standard Binary Search function 
 * 
 * @param arr Sorted Array of distinct elements
 * @param low Starting index of array
 * @param high Last index of array
 * @param target Key that is to be searched
 * 
 * @return Index of the target
*/
int binarySearch(vector<int> arr, int low, int high, int target){
    while(low<=high){
        int mid = (low + high)/2;
        if(arr[mid]==target) return mid;
        if(arr[mid]>target){
            high = mid-1;
        }
        else if(arr[mid]<target){
            low = mid+1;
        }
    }
    return -1;
}

/** 
 * @details This function finds the number of times the array is
 * rotated. It is equal to the index of the smallest element in the array. 
 * 
 * @param arr Rotated Sorted Array with distinct elements
 * @param low Starting index of array
 * @param high Last index of array
 * 
 * @return Index of the smallest element
 */
int returnMinIdx(vector<int> arr, int low, int high){
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

/**
 * @brief function which search for the target with the help of
 * the other two functions.
 * 
 * @param arr Rotated Sorted Array with distinct elements
 * @param target Key that is to be searched
 * 
 * @return Index of the target
 */ 
int search(vector<int> arr, int target) {
    int minIdx = returnMinIdx(arr, 0, (arr.size()-1));
    int left = binarySearch(arr, 0, (minIdx-1), target);
    int right = binarySearch(arr, minIdx, (arr.size()-1), target);
    if(left>right) return left;
    else if(right > left) return right;
    else return -1;
}

int main(){
    // Let us search 3 in below array
    vector<int> arr = { 5, 6, 7, 8, 9, 10, 1, 2, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    cout<<search(arr, key);
 
    return 0;
}