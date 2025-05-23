//手を動かして考える
/*
  1 2 3 1
  K=1  t=5 n=4  h=3 5-4=1
  K=2  t=7 n=8 h=9  Unfair
  K=3  t=17 n=16 h=15 17-16=1
  K=4  t=31 n=32 h=31 Unfair

  a=5 b=2 c=1 
  K=1 t=3 n=6 h=7 3-6=-3 Unfair
  K=2 t=13 n=10 h=9 13-10=3
  K=3 t=19 n=22 h=23 19-22=-3 Unfair

  K%2==1 ではcout<<(b+c)-(a+c)
  K%2==0ではcout<<(a+c+a+b)-(b+c+a+b)<<endl;

*/

#include<iostream>
using namespace std;

int main(){
    int A,B,C,K;
    cin>>A>>B>>C>>K;
    if(K%2==1){
        cout<<B-A<<endl;
    }else{
        cout<<(A-B)<<endl;
    }
}