#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

// カッコ列の正当性をstackで判定
bool isValid(const string& s) {
    stack<char> st;
    for (char c : s) {
        if (c == '(') {
            st.push(c);
        } else { // c == ')'
            if (st.empty()) return false;
            st.pop();
        }
    }
    return st.empty();
}

// 全探索して正しいカッコ列を集める
vector<string> generate(int N) {
    vector<string> res;
    if (N % 2 != 0) return res; // 奇数なら正しい列はない

    int total = 1 << N; // 2^N
    for (int bit = 0; bit < total; ++bit) {
        string s = "";
        for (int i = N - 1; i >= 0; --i) {
            if (bit & (1 << i))
                s += ')';
            else
                s += '(';
        }
        if (isValid(s)) {
            res.push_back(s);
        }
    }

    sort(res.begin(), res.end()); // 辞書順にソート
    return res;
}

int main() {
    int N;
    cin >> N;

    vector<string> ans = generate(N);
    for (const string& s : ans) {
        cout << s << endl;
    }

    return 0;
}
