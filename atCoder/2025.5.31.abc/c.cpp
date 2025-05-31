/*
普通にバケットを使うだけだとTLEになる
imos法（差分配列を作り後から累積和を取る）を使うとO(N+M)で解ける
1. 配列 diff[] を用意（長さ N+1）
2. 各区間 [L, R] に対して：
     diff[L] += 1
     diff[R+1] -= 1
3. 最後に累積和（prefix sum）をとることで、
   各位置の最終的な加算値を得る

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    // 差分配列 (長さ N+1 にして R+1 の処理を可能に)
    vector<int> diff(N + 1, 0);

    // 各砲台の範囲に +1, R+1 に -1
    for (int i = 0; i < M; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;  // 0-based に変換
        diff[l] += 1;
        if (r + 1 < N) diff[r + 1] -= 1;
    }

    // 累積和で本来の gurded 配列を復元
    vector<int> gurded(N);
    gurded[0] = diff[0];
    for (int i = 1; i < N; ++i) {
        gurded[i] = gurded[i - 1] + diff[i];
    }

    // 最小値を求める
    int ans = *min_element(gurded.begin(), gurded.end());
    cout << ans << endl;

    return 0;
}
