#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

int maxMeetings(int start[], int end[], int n){
    vector<pair<int,int>> v;
    for(int i = 0;i<n;i++){
        v.push_back(make_pair(start[i],end[i]));
    }
    // vector v holds the pairs
    // sort the pairs
    sort(v.begin(), v.end(), cmp);
    // for(auto i : v){
    //     cout<<i.first<<"->"<<i.second<<endl;
    // }
    // counting in the first element
    int count = 1;
    int j = 0;

    for(int i = 1; i<n;i++){
        if(v[i].first>v[j].second){
            j = i;
            count++;
            // cout<<"count is "<<"->"<<count<<endl;
        }
    }

    return count;
}

int main(){
    int n;
    cin >> n;
    int start[n], end[n];
    for(int i = 0; i < n; i++) cin>>start[i];
    for(int i = 0; i < n; i++) cin>>start[i];
    int res = maxMeetings(start,end,n);
    cout<<res<<endl;
    return 0;
}