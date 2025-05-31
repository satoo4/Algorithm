/*締切日であるM日目から0日目までさかのぼるように考える
  i日目について(i=M-1,M-2,...0)
  1.残っている仕事のうち
  2.A<=M-iを満たし
  3.Bが最大のものを選べばいい
*/
/*
このままだと計算量がO(N^2)になってしまうので、ヒープを用いる
priority_queue:ヒープに含まれる要素のうち、最大のものを取り出したり削除したりできる
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    int N, M;
    cin>>N>>M;
    //AtoB[i]:A[i]=vとなるiに対するB[i]の集合
    vector<vector<int>>AtoB(M+1);
    for(int i=0;i<N;i++){
        int A, B;
        cin>>A>>B;
        if(A > M) continue; // AがMを超える場合は無視
        //日数がAの仕事を管理
        //Aが小さい順になる
        AtoB[A].push_back(B);
    }
    long long result = 0;
    priority_queue<int> que;
    //締切日から0日目までさかのぼる(AtoB[0]から順に見る)
    for(auto Bs:AtoB){
        for(auto B:Bs){
            que.push(B); //Bをヒープに追加
        }
        if(!que.empty()){
            //ヒープの最大値を取り出す
            result += que.top();
            que.pop(); //取り出した最大値を削除
        }
    }
    cout << result << endl; //結果を出力
}