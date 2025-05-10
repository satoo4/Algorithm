#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll=long long;
//３進数に対してbit全探索を行う
int main()
{
   int n,m;
    cin >> n >> m;
    vector<int>c(n);
    rep(i,n){
        cin >> c[i];
    }
    vector<vector<int>>a(m);
    rep(i,m){
        int k;
        cin >> k;
        a[i]=vector<int>(k);
        rep(j,k){
            cin >> a[i][j];
            a[i][j]--;
        }
    }
    vector<int>p3(n+1,1);
    rep(i,n){
        p3[i+1]=p3[i]*3;
    }
    const ll INF=1e18;
    ll ans=INF;

    rep(s,p3[n]){
        vector<int>t(n);
        rep(i,n){
            t[i]=s/p3[i]%3;
        }
        ll cost=0;
        rep(i,n)cost+= c[i]*t[i];
        bool ok=true;
        rep(j,m){
            int cnt=0;
            for(int i:a[j]){
                if(t[i]==1)cnt++;
            }
            if(cnt<2)cost=INF;
            ans = min(ans,cost);
        }
    }
    cout<<ans<<endl;
    return 0;
}
