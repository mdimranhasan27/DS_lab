#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> v={"abid","babul","emran","faruk","himel","jony","karim","pavel","rony","siam"};
    int idx=0;
    //finding karim index
    for(int i=0;i<v.size();i++){
        if(v[i]=="karim") idx=i;
    }
    //deleting karim index
    for(int j=idx;j<v.size();j++){
        v[j]=v[j+1];
    }
    v.pop_back();
    //printing
    for(auto x:v) cout<<x<<" ";
    cout<<"\n";
    //deleting index 3
    for(int k=2;k<v.size();k++){
        v[k]=v[k+1];
    }
    v.pop_back();
    //printing
    for(auto x:v) cout<<x<<" ";
    cout<<"\n"; 
    return 0;
}