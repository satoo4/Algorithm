#include<bits/stdc++.h>
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
    long long min_abs=LLONG_MAX;
    for(int i=0;i<N;i++){
        if(A.at(i)<0){
            // マイナスの数をカウント
            num_minus++;
        }
        sum_abs+=abs(A.at(i));
        min_abs=min(min_abs, 1LL * abs(A.at(i)));
    }
    if(num_minus%2==0){
        cout<<sum_abs<<endl;
    }else{
        // 全て正の和から絶対値が一番小さな値を引く
        //ここでsum_absは全ての要素の絶対値の和であり、min_absは絶対値が最小の要素の絶対値
        //一度全ての絶対値を足しているのでmin_absに2をかけて引いている
        cout<<sum_abs-min_abs*2<<endl;
    }
}