/**
 * Find first and last positions of an element in a sorted array.
 * References:
 *  https://www.geeksforgeeks.org/find-first-and-last-positions-of-an-element-in-a-sorted-array/
 *  https://www.youtube.com/watch?v=zr_AoTxzn0Y
 */

#include<bits/stdc++.h>
using namespace std;


/**
 * Naive Approach.
 * Time Complexity: O(n) 
 * Auxiliary Space: O(1)
 */ 

/**
vector<int> findOccurence(int arr[], int n, int x){
    vector<int> res;
    int first = -1, last = -1;
    for(int i=0; i<n; i++){
        if(x!=arr[i]) continue;
        if(first == -1) first = i;
        last = i;
    }
    res.push_back(first);
    res.push_back(last);
    return res;
}
*/

/**
 * Efficient solution: Using binary search.
 * Time Complexity : O(log n) 
 * Auxiliary Space : O(1) 
 */ 
int firstOccurence(int arr[], int n, int x){
    int low = 0, high = n-1, res;
    while(low<=high){
        int mid = (low+high)/2;
        if(x<arr[mid]){
            high=mid-1;
        }
        else if(x>arr[mid]){
            low=mid+1;
        }
        else{
            res=mid;
            high=mid-1;
        }
    }
    return res;
}
int secondOccurence(int arr[], int n, int x){
    int low = 0, high = n-1, res;
    while(low<=high){
        int mid = (low+high)/2;
        if(x<arr[mid]){
            high=mid-1;
        }
        else if(x>arr[mid]){
            low=mid+1;
        }
        else{
            res=mid;
            low=mid+1;
        }
    }
    return res;
}

int main(){
    int arr[] = {1,2,2,3,5,6,7,2,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x =2 ;
    cout<<firstOccurence(arr,n,x)<<endl;
    cout<<secondOccurence(arr,n,x)<<endl;
}