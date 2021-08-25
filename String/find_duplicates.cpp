//Print all the duplicates and their counts in the input string.

#include <bits/stdc++.h>
using namespace std;

void printDups(string S){
    unordered_map<char,int> m;
    for(int i=0;i<S.size();i++){
        m[S[i]]++;
    }
    for(auto i:m){
        if(i.second>1){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }
}

int main()
{
    string str = "test string";
    printDups(str);
    return 0;
}