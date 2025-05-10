//幅優先探索
//queueを使って、最短距離を求める
//隣接するリストのうち、未訪問のノードをキューに追加していく
//queueの先頭を取り出して、そこに移動

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph=vector<vector<int>>;

int main(){
    int N,M;cin>>N>>M;
    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b;cin>>a>>b;
        G[a].push_back(b);//aからbに行ける
        G[b].push_back(a);//bからaに行ける
    }
    vector<int>dist(N,-1);//距離を-1で初期化
    queue<int>que;

    dist[0]=0;//0からの距離は0
    que.push(0);//0をキューに追加
    while(!que.empty()){
        int v=que.front();
        que.pop();//キューの先頭を取り出す

        for(int nv:G[v]){
            if(dist[nv]==-1){//未訪問のノード
                dist[nv]=dist[v]+1;//距離を更新
                que.push(nv);//キューに追加
            }
        }
    }
    for(int v=0;v<N;v++){
        cout<<v<<":"<<dist[v]<<" "<<endl;
    }
}