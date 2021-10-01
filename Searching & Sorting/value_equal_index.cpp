/**
 * Given an array Arr of N positive integers. 
 * Your task is to find the elements whose value is equal to that of its index value.
 * References:
 *  https://www.geeksforgeeks.org/find-a-fixed-point-in-a-given-array/
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * Using Binary Search.
 * When the given array is sorted.
 * Time Complexity: O(Logn)
 */ 
vector<int> valueEqualToIndex(int arr[], int low, int high){
    vector<int> res= {};
    if(high>=low){
        int mid = low + (high - low) / 2;
        if(mid==arr[mid]){
            res.push_back(mid);
        }
        if(mid>arr[mid]){
            valueEqualToIndex(arr, (mid+1) , high);
        }
        else{
            valueEqualToIndex(arr, low , (mid-1));
        }
    }
    return res;
}


/**
 * Using Linear Search. 
 * Time Complexity: O(n)
 */ 

/**
vector<int> valueEqualToIndex(int arr[], int n) {
    vector<int> res ={};
    for(int i=0;i<n;i++){
        if(arr[i]==i){
            res.push_back(i);
        }
    }
    return res;
}
*/

int main(){
    int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
    int n = sizeof(arr)/sizeof(arr[0]);
    //auto ans = valueEqualToIndex(arr, n);
    vector<int> ans = valueEqualToIndex(arr,0,n-1);
    if(ans.empty()){
        cout<<"Not found";
    }
    else{
        for(int x: ans){
            cout<<x<<" ";
        }
    }
    return 0;
}

