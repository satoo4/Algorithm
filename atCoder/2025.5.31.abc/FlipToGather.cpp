/*
https://atcoder.jp/contests/abc408/editorial/13166
1の区間にある0の個数と0の区間にある1の個数が求める答え
(左右の0)+(左の1)-(左の0)だけ操作すると区間1になる
それが最小になったらそれが答え

*/
#include<iostream>
#include<vector>
using namespace std;
void solve(){
    int n;string s;
    cin>>n>>s;
    vector<int>r0(n+1);
    for(int i=n-1;i>=0;i--){
        //1の個数
        r0[i]=r0[i+1]+(s[i]=='1');
    }
    int ans=1e9;
    int l0=0; // 左の0の個数
    for(int r=1;r<n;r++){
        //0の個数
        if(s[r-1]=='0') l0++;
        int now=r0[r]+l0-(r-1-l0);
    }
}

int main(){
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        int N;
        cin>>N;

    }

}