/*1xのとき現在の色を出力し、頂点xのスプリンクラーを起動*/
/*2xyの時頂点xの色をyで上書きする*/

/*頂点数NのグラフGを定義*/
/*G[i]はiに隣接する辺のベクトル*/
/*xの辺の色をcol[x]とする*/
/*xの辺をvで塗り替えるにはcol[x]=col[v]とし、vはG[i]の要素にすればいい*/
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N,M,Q;
    cin>>N>>M>>Q;
    vector<vector<int>>G(N);
    vector<int>col(N);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        //頂点番号が0から始まるようにする
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i=0;i<N;i++){
        cin>>col.at(i);
    }
    for(int i=0;i<Q;i++){
        int s;
        cin>>s;
        if(s==1){
            int x;
            cin>>x;
            //頂点番号が0スタートになるようにする
            x--;
            cout<<col[x]<<endl;
            //xに隣接する辺すなわちG[x]を調べ上げる
            for(auto v:G[x]){
                col[v]=col[x];
            }
        }
        if(s==2){
            int x,y;
            cin>>x>>y;
            x--;
            cout<<col[x]<<endl;
            col[x]=y;
        }
    }

}