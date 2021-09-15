/**
 * Program to Check if a string is a valid shuffle of two distinct strings
 * 
 * References: https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
 */

/** 
 * Sample output:
 * 
 * 1XY2 is a valid shuffle of XY and 12 
 * Y1X2 is a valid shuffle of XY and 12     
 * Y21XX is not a valid shuffle of XY and 12  
 */

#include<bits/stdc++.h>
using namespace std;

bool check_valid_shuffle(string s1, string s2, string res){
    if(s1.length()+s2.length() != res.length())
        return false;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    sort(res.begin(), res.end());
    int i =0, j=0, k=0;
    while(k != res.length()){
        if(i<s1.length() && s1[i]==res[k])
            i++;
        else if(j<s2.length() && s2[j]==res[k])
            j++;
        else return false;
        k++;
    }
    if(i<s1.length() || j<s2.length()) return false;
    return true;
}

int main(){
    string s1 = "CAB";
    string s2 = "231";
    string res = "1AB2C3";
    check_valid_shuffle(s1, s2, res)?cout<<"True":cout<<"False";
    return 0;
}