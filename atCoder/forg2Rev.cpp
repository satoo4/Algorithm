#include<iostream>
#include<vector>
using namespace std;
constexpr long long INF=1LL<<60;

int main(){
    int N;
    cin>>N;
    vector<long long>h(N);
    for(auto&hi :h){
        cin>>hi;
    }
    vector<long long>dp(N,INF);
    dp[0]=0;
    for(int i=1;i<N;i++){
        if(i-1>=0){
            dp[i]=min(dp[i],dp[i-1]+abs(h[i]-h[i-1]));
        }
        if(i-2>=0){
            dp[i]=min(dp[i],dp[i-2]+abs(h[i]-h[i-2]));
        }
    }
    cout<<dp[N-1]<<endl;
}