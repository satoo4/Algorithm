#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int N,Q;
    cin>>N>>Q;
    string S;
    cin>>S;
    vector<int>cn(N+1);
    for(int i=1;i<S.length();i++){
        cn[i+1]=cn[i]+(S.substr(i-1,2)=="AC");
    }

    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        cout<<cn[r]-cn[l];
    }

}