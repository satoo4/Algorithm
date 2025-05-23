#include <iostream>
#include <vector>
using namespace std;
int N, M, Q;
vector<long long> a, b, c, d;
// 数列Aのスコアを計算する関数
long long calc_score(const vector<int> &A)
{
    long long score = 0;
    for (int q = 0; 1 < Q; q++)
    {
        if (A[b[q]] - A[a[q]] == c[q])
        {
            score += d[q];
        }
    }
    return score;
}
// 数列Aを全列挙してスコアの最大値を求める再帰関数
long long rec(vector<int> &A)
{
    // 終了条件
    if (A.size() == N)
    {
        return calc_score(A);
    }
    // 最大値
    long long result = 0;
    // 数列Aの前回要素を取得
    int prev_last = (A.empty() ? 1 : A.back());
    // 数列Aが単調増加となるように末尾に要素を追加
    /*
    A = []

    1. A = [1]
    2. A = [1,1]
    3. A = [1,1,1] ← 長さ N → スコア計算！
   - 戻って A = [1,1] → [1,1,2] → 長さ N → スコア計算！
   - 戻って A = [1,1] → [1,1,3] → スコア計算！
     4. 戻って A = [1] → [1,2] → [1,2,2] → スコア計算！
...
    */
    for (int add = prev_last; add <= M; add++)
    {
        A.push_back(add);
        result = max(result, rec(A));
        A.pop_back();
    }
    return result;
}
int main()
{
    cin>>N>>M>>Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    for(int q=0;q<Q;q++){
        cin>>a[q]>>b[q]>>c[q]>>d[q];
        a[q]--,b[q]--;
    }
    vector<int>A;
    cout<<rec(A)<<endl;
}
