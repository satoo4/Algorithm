//パリティーに着目する
//不可能な場合を列挙していく
/*
  X=x_(i+1)-x_i,Y=y_(i+1)-y_i,T=t_(i+1)-t_iとし、毎回原点スタートとする
  不可能なケース
  ①T<X+Yのとき
  ②TとX+Yのパリティが等しくないとき

*/

//解けなかったので要復習
#include<iostream>
#include<vector>
using namespace std;

bool solve(){
    int N;
    cin>>N;
    //前回の時刻と座標を表す変数
    int pt=0,px=0,py=0;
    //Nステップの移動をそれぞれ考える
    for(int i=0;i<N;i++){
        int t,x,y;
        cin>>t>>x>>y;
        int X=abs(x-px);
        int Y=abs(y-py);
        int T=t-pt;
        //T<X+Yの時到達不可能
        if(T<X+Y){
            return false;
        }
        //パリティが合わないとき到達不可能
        if(T%2!=(X+Y)%2){
            return false;
        }
        //前回情報を更新し、原点から移動するようにする
        pt=t,px=x,py=y;
    }
    //最後まで到達
    return true;
}

int main(){
    if(solve()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}