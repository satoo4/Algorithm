/*
imos法
https://atcoder.jp/contests/abc408/editorial/13165

*/
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> imos(n+1);
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        l--; // Convert to 0-based index
        r--; // Convert to 0-based index
        imos[l]++;
        imos[r+1]--;
    }
    for(int i=1;i<=n;i++){
        imos[i] += imos[i-1];
    }
    int ans = 1e9;
    for(int i = 0; i < n; ++i){
        ans=min(ans, imos[i]);
    }
    cout << ans << endl;
    return 0;
}