/**
 * Find Missing And Repeating.
 * References:
 *  https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
 *  https://www.youtube.com/watch?v=KOsS5-1q9rU&t=2s
 */ 
#include <bits/stdc++.h>
using namespace std;
 
vector<int> find(int arr[], int size) {
    vector<int> res;
    for (int i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            res.push_back(abs(arr[i]));
    }
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            res.push_back(i + 1);
    }
    return res;
}
 
/* Driver code */
int main() {
    int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> res = find(arr, n);
    for(auto i : res) cout<<i<<" ";
    return 0;
}
