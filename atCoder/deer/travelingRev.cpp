#include<bits/stdc++.h>
using namespace std;
bool isTravelable(){
    int N;
    cin>>N;
    int pt=0,px=0,py=0;
    for(int i=0;i<N;i++){
        int t,x,y;
        cin>>t>>x>>y;
        int X=abs(x-px);
        int Y=abs(y-py);
        int T=t-pt;
        //X+YがTよりも大きいとき
        if(T<X+Y){
            return false;
        }
        //TとX+Yのパリティが一致しないとき
        if((T%2)!=((X+Y)%2)){
            return false;
        }
        pt=t;
        px=x;
        py=y;
    }
    return true;
}

int main(){
    if(isTravelable()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}