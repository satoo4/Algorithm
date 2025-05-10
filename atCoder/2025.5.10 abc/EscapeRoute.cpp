#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int H, W;
vector<string> grid;
vector<vector<pair<int, int>>> from; // 親の位置（どこから来たか）

// 方向ベクトル：上, 右, 下, 左
const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};
const char dir[4] = {'^', '>', 'v', '<'};

int main() {
    cin >> H >> W;
    grid.resize(H);
    from.assign(H, vector<pair<int, int>>(W, {-1, -1}));
    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;

    for (int i = 0; i < H; ++i) {
        cin >> grid[i];
    }

    // 非常口をキューに追加（多点スタートBFS）
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == 'E') {
                que.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    // BFS
    while (!que.empty()) {
        auto [y, x] = que.front(); que.pop();
        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W) continue;
            if (grid[ny][nx] != '.' || dist[ny][nx] != -1) continue;
            dist[ny][nx] = dist[y][x] + 1;
            from[ny][nx] = {y, x}; // 親を記録
            que.push({ny, nx});
        }
    }

    // 結果を作成
    vector<string> ans = grid;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (grid[i][j] == '.') {
                auto [py, px] = from[i][j];
                for (int d = 0; d < 4; ++d) {
                    if (i + dy[d] == py && j + dx[d] == px) {
                        ans[i][j] = dir[d]; // 「どっちに行けば非常口に近づくか」
                    }
                }
            }
        }
    }

    // 出力
    for (int i = 0; i < H; ++i) {
        cout << ans[i] << '\n';
    }

    return 0;
}
