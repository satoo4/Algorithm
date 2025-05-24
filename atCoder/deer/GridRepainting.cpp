//幅優先探索
//始点から1手で行けるところを全て探索し、それが終了したら2手で行けるところを全て探索することを繰り返す
/*
1探索の始点となる頂点0をキューに入れる
2頂点0をキューから取り出して探索済みとする
頂点0に隣接する頂点1,4,2をキューに追加する
3キューにさいしょに追加した頂点1をキューから取り出して探索済みとする
頂点1と隣接する頂点0,4,3,7のうちキューに一度も追加されたことのない頂点3,7をキューに追加する
4キューに残っている頂点のうち最初に追加した頂点4を取り出して探索済みとする
頂点4と隣接する頂点0,1,7のうちキューに一度も追加された頃のない頂点はないので終了する
5キューに残っている頂点のうち最初に追加した頂点2を取り出して探索済みとする
頂点2に隣接する頂点0,6のうち頂点6を新たにキューに追加する
6キューに残っている頂点のうち最初に追加した頂点7を取り出して探索済みにする
頂点7と隣接する頂点のうち一度も追加されたことのない頂点はないので終了する
7キューに残っている頂点のうち最初に追加した頂点6を取り出して探索済みとする
頂点6と隣接する頂点2,7,5のうち一度も追加されたことのない頂点はないので終了する
8最後にキューに残っていた頂点5を取り出して探索済みとし、ステップを終了する
*/
#include<queue>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<int>DX={1,0,-1,0};
vector<int>DY={0,1,0,-1};
int main(){
    int H,W;
    cin>>H>>W;
    vector<string> S(H);
    for(auto &row : S){
        cin >> row;
    }

    queue<pair<int,int>>que;
    vector<vector<int>>dist(H,vector<int>(W,-1));
    que.push({0,0});
    dist[0][0]=0;
    
    while(!que.empty()){
        pair<int,int>tmp=que.front();
        int x=tmp.first;
        int y=tmp.second;
        que.pop();
        for(int dir=0;dir<4;dir++){
            int x2=x+DX[dir],y2=y+DY[dir];
            if(x<0||x2>=H||y2<0||y2>=W){
                continue;
            }
            if(S[x2][y2]=='#'){
                continue;
            }
            if(dist[x2][y2]==-1){
                continue;
            }
            que.push({x2,y2});
        }
    }
    int white=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(S[i][j]=='.'){
                white++;
            }
        }
    }
    if(dist[H-1][W-1]!=-1){
        cout<<white-(dist[H-1][W-1]+1)<<endl;
    }else{
        cout<<-1<<endl;
    }

}