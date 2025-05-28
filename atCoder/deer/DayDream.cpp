//dp[i]←S[0:i]が"erase","dream","eraser","dreamer"のいずれかで構成されるかを表すブール値
#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin>>S;
    int N=S.size();

    //動的計画法の配列
    vector<bool>dp(N+1,false);
    dp[0]=true; //空文字列は常に成立
    //dp[1],dp[2],dp[3],..dp[N]の順にボトムアップに求めていく
    for(int i=1;i<=N;i++){
        if(i>=5&&dp[i-5]&&S.substr(i-5,5)=="erase"){
            dp[i]=true; //S[0:i]が"erase"で終わる場合
        }
        if(i>=6&&dp[i-6]&&S.substr(i-6,6)=="eraser"){
            dp[i]=true; //S[0:i]が"eraser"で終わる場合
        }
        if(i>=5&&dp[i-5]&&S.substr(i-5,5)=="dream"){
            dp[i]=true; //S[0:i]が"dream"で終わる場合
        }
        if(i>=7&&dp[i-7]&&S.substr(i-7,7)=="dreamer"){
            dp[i]=true; //S[0:i]が"dreamer"で終わる場合
        }
    }
    if(dp[N]){
        cout<<"YES"<<endl; //S全体が"erase","dream","eraser","dreamer"のいずれかで構成される場合
    }else{
        cout<<"NO"<<endl; //S全体が"erase","dream","eraser","dreamer"のいずれかで構成されない場合
    }
}
