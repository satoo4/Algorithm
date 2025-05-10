#include <iostream>
#include<vector>
using namespace std;

int main()
{
    int N,Y;
    cin >> N >> Y;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N-i;j++){
            int k=N-i-j;
            if(k<0)continue;
            if(Y==10000*i+5000*j+1000*k){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

}
