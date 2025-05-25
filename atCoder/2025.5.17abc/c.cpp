#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
// 山谷を考え、左右をどれくらい取れるか考える
//  左端iとし、山、谷が1個ずつある区間内を探すためにjを動かす
// もし山、谷が交互に現れなかったらiをjの位置までスキップ
// 交互に現れていたら次の山or谷が見つかるまでjを動かす
// ＜を０＞を１としRLEを行う
int main()
{
   int N;
   cin >> N;
   vector<int> p(N);

   for (int i = 0; i < N; i++)
   {
      cin >> p.at(i);
   }
   vector<int> d;
   for (int i = 0; i < N - 1; i++)
   {
      // 左が小さいなら0、右が小さいなら1
      d.push_back(p.at(i) < p.at(i + 1) ? 0 : 1);
   }
   using P = pair<int, int>;
   vector<P> rle;
   // Run Length Encoding (RLE) to compress the sequence of 0s and 1s
   // 連続する同じ値をまとめる
   for (int x : d)
   {
      // 前の要素と同じならカウントを増やす
      if (rle.size() && rle.back().first == x)
      {
         rle.back().second++;
      }
      // 前の要素と違うなら新しい要素を追加
      else
      {
         rle.emplace_back(x, 1);
      }
   }
   ll ans = 0;
   for (int i = 0; i < rle.size(); i++)
   {
      if (rle[i].first == 1)
      {
         ll l = 0, r = 0;
         if (0 < i)
            l = rle[i - 1].second;
         if (i + 1 < rle.size())
            r = rle[i + 1].second;
         ans += l * r;
      }
   }
   cout << ans << endl;
   return 0;
}
