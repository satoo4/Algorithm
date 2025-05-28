/*
for文を使ってdp[1], dp[2], ..., dp[N-1]の順にボトムアップに求めていく方法
*/
#include <bits/stdc++.h>
using namespace std;
constexpr long long INF = 1LL << 60;

int main()
{
    int N;
    cin >> N;
    vector<long long> h(N);
    for (auto &hi : h)
    {
        cin >> hi;
    }
    vector<long long> dp(N, INF);
    // 初期条件（スタート地点へ移動するコストは0)
    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        if (i - 1 >= 0)
        {
            // 頂点i-1まで最短経路で最短経路で行ってから頂点iへと至る方法の最小コスト
            // dp[i]はi番目の頂点に到達するための最小コスト
            /*
            これは「足場 i - 1 に最小コストでたどり着いていて、そこから i にジャンプする」ケース。
            abs(h[i] - h[i - 1]) がジャンプのコスト。
            その合計を現在の dp[i] と比較して、より小さい方を採用。
            */
            dp[i] = min(dp[i], dp[i - 1] + abs(h[i] - h[i - 1]));
        }
        if (i - 2 >= 0)
        {
            /*
            同様にこれは「足場 i - 2 に最小コストでたどり着いていて、そこから i にジャンプする」ケースについて現在のdp[i]と比較し小さい方を採用している
            */
            // 頂点i-2まで最短経路で最短経路で行ってから頂点iへと至る方法の最小コスト
            dp[i] = min(dp[i], dp[i - 2] + abs(h[i] - h[i - 2]));
        }
    }
    cout << dp[N - 1] << endl; // 最小コストを出力
}