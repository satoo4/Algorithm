#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    map<string,long long> S;
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        S[s]++;
    }
    int ans = 0;
    for(auto s:S){
        long long num = s.second;
        ans += (num * (num - 1)) / 2; // 組み合わせの数を計算
    }
    cout << ans << endl;
    return 0;
}