#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin>>S;
    vector<string>words;
    //iは一歩一歩進分けではないからi++と書かないように注意
    for(int i=0;i<S.size();){
        int j=i+1;
        //whileループから抜ける時jは大文字の位置にいる
        while(j<S.size()&&islower(S[j])){
            j++;
        }
        string word=S.substr(i,j+1-i);
        word[0]=tolower(word[0]);
        word.back()=tolower((word.back()));
        words.push_back(word);
        i=j+1;
    }
    sort(words.begin(),words.end());
    string result="";
    for(auto word:words){
        word[0]=toupper(word[0]);
        word.back()=toupper(word.back());
        result+=word;
    }
    cout<<result<<endl;
    return 0;
}