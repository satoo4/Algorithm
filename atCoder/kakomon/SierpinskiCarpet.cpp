/*
再帰関数を用いる
終了条件n=1の時[1][1]に'.'を置き周りを'#'で囲う(carpet[1][1]='.')
n>=2のときcarpet[n]はcarpet[n-1]を8個真ん中の.を囲うように配置したもの

*/
#include<bits/stdc++.h>
using namespace std;


int main(){
    int N;
    cin>>N;
    vector<vector<int>>carpet(3, vector<int>(3, '#'));
    carpet[1][1] = '.';
    

}