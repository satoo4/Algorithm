#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) {
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // 0-indexed に変換
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);
    dfs(G, 0);

    // 1. 連結チェック
    bool connected = true;
    for (int i = 0; i < N; i++) {
        if (!seen[i]) {
            connected = false;
            break;
        }
    }

    // 2. 各頂点の次数が2かどうか
    bool all_degree_two = true;
    for (int i = 0; i < N; i++) {
        if (G[i].size() != 2) {
            all_degree_two = false;
            break;
        }
    }

    if (connected && M == N && all_degree_two) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
