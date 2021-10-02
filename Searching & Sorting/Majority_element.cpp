/**
 * Given an array A of N elements. Find the majority element in the array. 
 * A majority element in an array A of size N is an element that appears more than N/2 times in the array.
 * References: 
 *  https://www.youtube.com/watch?v=n5QY3x_GNDg
 */ 

#include <bits/stdc++.h>
using namespace std;

/* Using Moore's Voting Algorithm: TC- O(n), SC- O(1) */

int findCandidate(int arr[], int n){
    int count = 1;
    int maj_idx = 0;
    for(int i=1; i<n; i++) {
        if(arr[maj_idx] == arr[i]) count++;
        else count--;

        if(count == 0) {
            maj_idx = i;
            count=1;
        }
    }
    return arr[maj_idx];
}

bool isMajority(int arr[], int n , int cad) {
    int count =0;
    for(int i=0;i<n;i++) {
        if(arr[i] == cad) count++;
    }
    if(count>n/2) return true;
    else return false;
}

int majorityElement(int arr[], int n) {
    int candidate = findCandidate(arr, n);

    if(isMajority(arr, n , candidate)) return candidate;
    else return -1;
}

/* Using map: TC- O(n), SC- O(n)
int majorityElement(int a[], int size) {

    unordered_map<int,int> map;
    for(int i=0;i<size;i++){
        map[a[i]]++;
    }
    for(int i=0;i<size;i++){
        if(map[a[i]]>size/2) return a[i];
    }
    return -1;
}
*/

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<majorityElement(arr, n);
    return 0;
}