#include<iostream>
#include<vector>
using namespace std;
int N;
vector<long long>h;
vector<long long>dp;
constexpr long long INF=1LL<<60;
long long rec(int i){
    if(i==0){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    long long result =INF;
    if(i-1>=0){
        result=min(result,rec(i-1)+abs(h[i]-h[i-1]));
    }
    if(i-2>=0){
        result=min(result,rec(i-2)+abs(h[i]-h[i-2]));
    }
    return dp[i]=result;
}
int main(){
    cin>>N;
    h.resize(N);
    for(auto& hi:h){
        cin>>hi;
    }
    dp.assign(N,-1);
    cout<<rec(N-1)<<endl;
}