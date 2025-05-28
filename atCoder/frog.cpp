#include<bits/stdc++.h>
using namespace std;

//動的計画法
//再帰を用いるだけ度だと同じ計算を何度も行い無駄が多い
//メモ化再帰を用いることで、計算結果を保存し、同じ計算を繰り返さないようにする
//dp[i]←rec(i)の答えを格納する

constexpr long long INF=1LL<<60;
int N;
vector<long long>h;
//メモ化用の配列
vector<long long>dp;
long long rec(int i){
    //終了条件
    if(i==0){
        return 0;
    }
    //すでに計算済みならその値を返す
    if(dp[i]!=-1){
        return dp[i];
    }
    long long result=INF;
    //頂点i-1から来た場合
    if(i-1>=0){
        result=min(result,rec(i-1)+abs(h[i]-h[i-1]));
    }
    //頂点i-2から来た場合
    if(i-2>=0){
        result=min(result,rec(i-2)+abs(h[i]-h[i-2]));
    }
    return dp[i]=result; //計算結果をメモ化して返す
}

int main(){
    cin>>N;
    h.resize(N);
    for(auto &hi:h){
        cin>>hi;
    }
    dp.assign(N,-1); // dp配列を-1で初期化
    long long ans=rec(N-1); // N-1の頂点からスタート
    cout<<ans<<endl; // 最小コストを出力
}