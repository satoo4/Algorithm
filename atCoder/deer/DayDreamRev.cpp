#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    int N = S.size();
    vector<bool> dp(N + 1, 0);
    dp[0] = true; // 空文字列は常にマッチする
    for(int i=1;i<=N;i++){
        if(i-5>=0&&dp[i-5]&&S.substr(i-5,5) == "dream"){
            dp[i] = true;
        }
         if(i-7>=0&&dp[i-7]&&S.substr(i-7,7) == "dreamer"){
            dp[i] = true;
        }
        if(i-5>=0&&dp[i-5]&&S.substr(i-5,5) == "erase"){
            dp[i] = true;
        }
        if(i-6>=0&&dp[i-6]&&S.substr(i-6,6) == "eraser"){
            dp[i] = true;
        }
    }
    if(dp[N]){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}