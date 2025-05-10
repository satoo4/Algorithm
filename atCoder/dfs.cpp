//深さ優先探索
//stackを用いる

#include <iostream>
#include <vector>
using namespace std;
using Graph=vector<vector<int>>;

vector<bool>seen;
void dfs(const Graph&G,int v){
    seen[v]=true;//vを訪問済みにする
    
    //vからいける各頂点next_vについて
    for(auto next_v:G[v]){
        if(seen[next_v])continue;//next_vが訪問済みならスルー
        dfs(G,next_v);//再帰的に探索
    }

}

int main(){
    int N,M;
    cin>>N>>M;

    Graph G(N);
    for(int i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);//aからbに行ける
        G[b].push_back(a);//bからaに行ける
    }
    seen.assign(N,false);//全ての頂点を未訪問にする
    dfs(G,0);//0から探索開始
}

/*入力例
4 3
0 1
1 2
2 3
*/