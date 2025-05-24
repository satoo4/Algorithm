#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
/*
①ボタンaの回数＝Sの桁数
②ボタンbの回数
407だと704の順に見ていく
後ろから見ていく

1後ろの数>前の数　１０　0>7  前の数＞後ろの数
2後ろの数=前の数　＋０　　　　　　　　　　　　　　　
3後ろの数＜前の数　前の数        4>0　前の数<後ろの数

これで累積和を取れば行けるバズ
*/

int main()
{
    string S;
    cin >> S;
    vector<int> digits;
    for (int i = S.size() - 1; i >= 0; --i)
    {
        digits.push_back(S[i] - '0');
    }
    int aCount = S.size();
    int bCount=0;
   
    // vector<int> cn(aCount + 1, 0);
    // reverse(S.begin(), S.end());
    for (int i = 0; i < aCount-1; i++)
    {
        // if(digits[0]){
        //     bCount+=digits[0];
        // }
        // 1
        if (digits[i]> digits[i+1])
        {
            bCount +=10-(digits[i]-digits[i+1]);
        }
        // 3
        else if (digits[i]< digits[i+1])
        {
            bCount += digits[i+1]-digits[i] ;
        }
        // 2
        else
        {
            bCount += 0;
        }
    }
    cout << aCount + bCount+digits[0] << endl;

    return 0;
}
