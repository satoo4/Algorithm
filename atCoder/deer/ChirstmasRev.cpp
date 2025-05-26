
/*
L(N)=2*L(N-1)+3
S(N)=2*S(N-1)+1
*/
/*
0 X=1
レベルN-1バーガーの先頭からX-1文字目までに含まれるPの個数　rec(N-1,X-1,L,S)  　X=2,3,...,L(N-1)+1
S(N-1)+1 X=L(N-1)+2
レベルN-1バーガーの先頭からX-L(N-1)-2文字目に含まれるPの個数+S(N-1)+1　rec(N-1,X-L(N-1-2,L,S))  X=L(N-1)+3,...,2*L(N-1)+2
2*S(N-1)+1 X=2*L(N-1)+3

*/
#include <bits/stdc++.h>
#include <vector>
using namespace std;
// レベルNバーガーの先頭からX番目までのPの個数を求める関数
long long rec(int N, long long X, const vector<long long> &L, const vector<long long> &S)
{
    // 終了条件
    if (N == 0)
    {
        return 1;
    }
    else if (X == 1)
    {
        return 0;
    }
    else if ( X <= L[N - 1] + 1)
    {
        return rec(N - 1, X - 1, L, S);
    }
    else if (X == L[N - 1] + 2)
    {
        return S[N - 1] + 1;
    }
    else if ( X <= 2 * L[N - 1] + 2)
    {
        return rec(N - 1, X - L[N - 1] - 2, L, S) + S[N - 1] + 1;
    }
    else
    {
        return 2 * S[N - 1] + 1;
    }
}
int main()
{
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> L(N + 1, 1), S(N + 1, 1);
    for (int n = 1; n <= N; n++)
    {
        L[n] = L[n - 1] * 2 + 3;
        S[n] = S[n - 1] * 2 + 1;
    }
    cout << rec(N, X, L, S) << endl;
    return 0;
}