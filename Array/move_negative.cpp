/**
 * An array contains both positive and negative numbers in random order. 
 * Rearrange the array elements so that all negative numbers appear before all positive numbers.
 * 
 * Reference: https://www.geeksforgeeks.org/move-negative-numbers-beginning-positive-end-constant-extra-space/
*/

#include<bits/stdc++.h>
using namespace std;

void rearrange(int a[], int n){
    int j=0;
    for(int i=0; i<n; i++){
        if(a[i]<0){
            if(i!=j) swap(a[i],a[j]);
            j++;
        }
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
 
// Driver code
int main(){
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange(arr, n);
    printArray(arr, n);
    return 0;
}