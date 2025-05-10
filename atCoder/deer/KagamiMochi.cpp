#include <iostream>
#include<vector>
using namespace std;
//予めバケットのサイズを決めておく
constexpr int MAX = 1000000;

int main()
{
    int N;
    cin >> N;
    vector<int>nums(MAX,0);
    for(int i=0;i<N;i++){
        int v;
        cin >> v;
        nums[v]=1;
    }
    int ans = 0;
    for(auto num:nums){
        ans += num;
    }
    cout << ans << endl;
    return 0;

}


//補足
/*
文字列sが何個あるかをnum[s]で数える場合以下のようにmapを使う

vector<string> s_list={"cat","dog","cat","cat","dog"};
int main(){
    map<string,int> num;
    for(auto s: s_list){
        num[s]++;
    }
    for(auto n:num){
        cout << n.first << " " << n.second << endl;
    }
        
*/