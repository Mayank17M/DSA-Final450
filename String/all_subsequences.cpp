/** 
 * Print all subsequences of a string
 * 
 * References: 
 *  https://www.geeksforgeeks.org/print-subsequences-string/
 *  https://www.youtube.com/watch?v=Yg5a2FxU4Fo&t=814s
 */

#include<bits/stdc++.h>
using namespace std;

void printSubsequence(string input, string output){
    if(input.empty()){
        cout<<output<<" ";
        return;
    }
    string op1 = output;
    string op2 = output;
    op2.push_back(input[0]);
    input.erase(input.begin() + 0);
    printSubsequence(input, op1);
    printSubsequence(input, op2);
}

int main(){
    string input = "abcd";
    string output = "";
    printSubsequence(input, output);
    return 0;
}