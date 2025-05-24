#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,M,Q;
    cin>>N>>M>>Q;
    vector<vector<int>>G(N);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        u--,v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int>colors(N);
    for(auto &color:colors){
        cin>>color;
    }
    for(int i=0;i<Q;i++){
        int q,x,y;
        cin>>q>>x;
        x--;
        cout<<colors[x]<<endl;
        if(q==1){
            for(auto v:G[x]){
                colors[v]=colors[x];
            }
        }
        if(q==2){
            cin>>y;
            colors[x]=y;
        }
    }
}