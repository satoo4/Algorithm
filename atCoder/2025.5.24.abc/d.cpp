#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
vector<long long> A_flat;

int main() {
    cin >> H >> W;
    vector<vector<long long>> A(H, vector<long long>(W));
    A_flat.reserve(H * W);

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
            A_flat.push_back(A[i][j]);
        }

    int n = H * W;
    long long ans = 0;

    // 全てのマスの使う/使わないをbit全探索
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<vector<bool>> used(H, vector<bool>(W, false));
        bool valid = true;

        // ドミノを置くシミュレーション
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                int idx = i * W + j;
                if ((mask >> idx) & 1) continue; // このマスは使わない（= ドミノで覆われている）

                // チェック：右
                if (j + 1 < W) {
                    int r_idx = i * W + (j + 1);
                    if (!((mask >> r_idx) & 1)) {
                        // どちらも使われてない → ドミノの重複（NG）
                        valid = false;
                        break;
                    }
                }
                // チェック：下
                if (i + 1 < H) {
                    int d_idx = (i + 1) * W + j;
                    if (!((mask >> d_idx) & 1)) {
                        // どちらも使われてない → ドミノの重複（NG）
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) break;
        }

        if (!valid) continue;

        // XOR計算（使わないマスの値）
        long long xor_sum = 0;
        for (int i = 0; i < n; ++i) {
            if ((mask >> i) & 1) {
                xor_sum ^= A_flat[i];
            }
        }
        ans = max(ans, xor_sum);
    }

    cout << ans << endl;
    return 0;
}
