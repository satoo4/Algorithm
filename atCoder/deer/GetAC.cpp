/*累積和
S[i+1]=S[i]+A[i+1]
S[i]はA[1]からA[i-1]までの和であるから以下の式が成り立つ
A[l]+…+A[r-1]=S[r]-S[l]
*/

/*
S[i]←i-1番目までのACの個数
S[i+1]=S[i]+(substr.S(i-1,2)=="AC")
*/
/*
 S=ACACTACG
cn001010010  index番号0と1は常に0
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    int N,Q;
    cin>>N>>Q;
    string S;
    cin>>S;
    vector<int>cs(N+1,0);
    for(int i=1;i<N;i++){
        cs[i+1]=cs[i]+(S.substr(i-1,2)=="AC");
    }
    for(int i=0;i<Q;i++){
        int l,r;
        cin>>l>>r;
        cout<<cs[r]-cs[l]<<endl;
    }

}