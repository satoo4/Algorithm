#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string S;
    cin >> S;
    vector<string> words;
    for (int i = 0; i < S.size();)
    {
        int j = i + 1;
        while (j < S.size() && islower(S[j]))
        {
            ++j;
        }
        string word = S.substr(i, j +1-i);
        word[0] = tolower(word[0]);
        word.back() = tolower(word.back());
        words.push_back(word);
        i = j+1 ;
    }
    sort(words.begin(), words.end());
    string result="";
    for (auto word : words)
    {
        word[0] = toupper(word[0]);
        word.back()= toupper(word.back());
        result += word;
    }
    cout << result << endl;
    return 0;

}
