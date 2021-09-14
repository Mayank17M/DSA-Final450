/**
 * Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
 * https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1
 */

#include<bits/stdc++.h>
using namespace std;

/**
 * Naive approach:
 * 
 * void sort012(int a[], int n){
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(a[i]==0) count0++;
        if(a[i]==1) count1++;
        if(a[i]==2) count2++;
    }
    int i=0;
    while(count0>0){
        a[i++]=0;
        count0--;
    }
    while(count1>0){
        a[i++]=1;
        count1--;
    }
    while(count2>0){
        a[i++]=2;
        count2--;
    }
}
*/

//Reference: https://www.geeksforgeeks.org/sort-an-array-of-0s-1s-and-2s/

void sort012(int a[], int n){
    int low=0, mid =0;
    int high=n-1;
    while(mid<=high){
        switch(a[mid]){
            case 0:
                swap(a[low++], a[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(a[high--],a[mid]);
                break;
        }
    }
}

// Utility function to print the contents of an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

// Driver code
int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(int);
 
    sort012(arr, n);
    printArr(arr,n);
    return 0;
}