//言い換え
/*
操作を分かりやすく言い換える
操作によって作れるものを特徴ずける
*/
//マイナスを真ん中に集める
//もともとのマイナスが偶数個ならば全てのマイナスをプラスにできる
//もともとのマイナスが奇数個ならば全てのマイナスを1コだけ残してプラスにできる

/*
  ++の箇所を--にする
  +-の箇所を++にする
  -+の箇所を+-にする
  --の箇所を++にする

　　のいずれかであり、-の個数は、2個減るor2個増えるor変わらないのいずれかより-の個数のパリティーは操作の前後で不変である
*/
/*
 もとの数列のマイナスが偶数個のとき:マイナスを0個にしたときの総和
 もとの数列のマイナスが奇数個のとき：マイナスを1個にし、絶対値が最小である要素をマイナスにして残りをプラスにする
*/
//このように問題を解けるようになるには不変量を見つけるようになることが重要
#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A.at(i);
    }
    int num_minus=0;
    long long sum_abs=0;
    long long min_abs=1LL<<60;
    for(int i=0;i<N;i++){
        if(A[i]<0){
            num_minus++;
        }
        sum_abs+=abs(A[i]);
        min_abs = min(min_abs, 1LL * abs(A[i]));


    }
    if(num_minus%2==0){
        cout<<sum_abs<<endl;
    }else{
        //全て正の和から絶対値が一番小さな値を引く
        cout<<sum_abs-min_abs*2<<endl;
    }
}