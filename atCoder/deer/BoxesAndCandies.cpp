//貪欲法の問題
//1最初の箱にXを超える量が入っている場合、Xまで食べておく
//2左から順に、個数を数えていき、次の箱に入れるとXを超える場合は、超過分を計算して次の箱に入れる量を調整する
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N;
    long long X;
    cin >> N>>X;
    vector<long long> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    long long result=0;
    //先頭部分のみXからの超過分を先に食べておく
    if(a[0]>X){
        result+= a[0] - X;
        a[0] = X;
    }
    //左端から順に処理していく
    for(int i=0;i+1<N;i++){
       if(a[i] + a[i+1] > X){
            //次の箱に入れると超過する場合
            result += a[i] + a[i+1] - X; //超過分を計算
            a[i+1] = X - a[i]; //次の箱に入れる量を調整
        } 
    }
    cout << result << endl; //結果を出力
}