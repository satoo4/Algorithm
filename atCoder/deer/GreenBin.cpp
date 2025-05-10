#include <iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N ;
    map<string,int> words;
    for(int i=0;i<N;i++){
        string v;
        cin >> v;
        //sortするときの書き方注意
        sort(v.begin(),v.end());
        words[v]++;
    }
    int ans = 0;
    for(auto word:words){
        int num = word.second;
        ans += (num*(num-1))/2;
    }
    cout << ans << endl;
    return 0;
}
