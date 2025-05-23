/*
レベル0バーガー：パティ1枚
レベルLバーガー：バン1枚、レベルL-1バーガー、パティ1枚、レベルL-1バーガー、バン1枚を積み重ねたもの

P:パティ　B:バン　レベルiバーガー:L(i)
ex)
レベル1バーガーL(1)
L(1)=BL(0)PL(0)B→BPPPB
レベル2バーガーB(2)
L(2)=BL(1)PL(0)B→BBPPPBPBPPPBB

L(N)=BL(N-1)PL(N-1)B



*/

/*
レベルNバーガーの先頭からX番目までのPの個数
0 X=1
レベルN-1バーガーの先頭からX-1文字目までに含まれるPの個数　X=2,3...,L(N-1)+1
S(N-1)+1  X=L(N-1)+2
レベルN-1バーガーの先頭からX-L(N-1)-2文字目までに含まれるPの個数 X=L(N-1)+3...2L(N-1)+2
2S(N-1)+1 X=L(N-1)+3

レベルLバーガーの長さL(N)とパティの個数S(N)に着目して考える
L(N)=L(N-1)+3 (L(0)=1)
S(N)=S(N-1)+1 (S(0)=0が成り立つ)
*/
#include <iostream>
#include <vector>
using namespace std;

// Xによるパティの個数を再帰的に求める関数
// 参照渡しを用いている
long long rec(int N, long long X, const vector<long long> &L, const vector<long long> &S)
{
    if (N == 0)
    {
        return 1;
    }
    if (X == 1)
    {
        return 0;
    }
    else if (X <= L[N - 1] + 1)
    {
        return rec(N - 1, X - 1, L, S);
    }
    else if (X == L[N - 1] + 2)
    {
        return  S[N - 1] + 1;
    }
    else if ( X <= 2 * L[N - 1] + 2)
    {
        return rec(N - 1, X - L[N - 1] - 2, L, S)+S[N-1]+1;
    }
    else
    {
        return S[N - 1]*2 + 1;
    }
}

int main()
{
    int N, X;
    cin >> N >> X;
    // バーガーの長さLとパティの数S
    vector<long long> L(N + 1,1), S(N + 1,1);
    for (int n = 1; n <= N; n++)
    {
        L[n] = L[n - 1]*2 + 3;
        S[n] = S[n - 1]*2 + 1;
    }
    cout << rec(N, X, L, S) << endl;
}