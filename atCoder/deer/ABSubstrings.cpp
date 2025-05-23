
// 上界(これ以上多く作るのは絶対に不可能だという値）を見積もる→上界を達成する場合を構築する
/*
連結前の文字列に含まれているABは後で合算する
N個の文字列は以下の4通りに分けられる
BxxxA c1
xxxxA c2
Bxxxx c3
xxxxx（これを使ってABが生成されることはないので無視してよい
*/
/*
今回の問題の場合
min(c1+c2,c1+c3)=c1+min(c2,c3)(c2,c3≠0)
min(c1-1,0) (c2=c3=0)
が上界となる
*/
/*
予めT個ABの文字列ができていたとする
c1を全て連結させると(BxxxA)(BxxxA)(BxxxA)...(BxxxA)でここにCを連結させると(BxxxA)(BxxxA)(BxxxA)...(BxxxA)(Bxxxx)となりこれはCと同じ文字列の型になりこの中にABの数はc1個ある
したがってT+min(c2,c3)+c1が求める値となる
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int T = 0, c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; i++)
    {
        string S;
        cin >> S;
        for (int j = 0; j + 1 < S.size(); j++)
        {
            // 最初の文字列中に含まれる"AB"の個数
            if (S.at(j) == 'A' && S.at(j + 1) == 'B')
            {
                T++;
            }
        }
        // patern1
        if (S.at(0) == 'B' && S.back() == 'A')
        {
            c1++;
        }
        // patern2
        else if (S.back() == 'A')
        {
            c2++;
        }
        // patern3
        else if (S.at(0) == 'B')
        {
            c3++;
        }
    }
    if (c2 == 0 && c3 == 0)
    {
        cout << T + max(c1 - 1, 0) << endl;
    }
    else
    {
        cout << T + c1 + min(c2, c3) << endl;
    }
}