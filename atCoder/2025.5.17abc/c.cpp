#include <iostream>
#include<vector>
using namespace std;


// 左端iとし、山、谷が1個ずつある区間内を探すためにjを動かす
//もし山、谷が交互に現れなかったらiをjの位置までスキップ
//交互に現れていたら次の山or谷が見つかるまでjを動かす
//
int main() {
   int N;
   vector<int>P(N);
   cin>>N;
   for(int i=0;i<N;i++){
    cin>>P.at(i);
   }
   int ans=0;
   for(int i=0;i<N;i++){
    int j=i+1;
    if()
   }
}
