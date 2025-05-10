#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
    string S;
    cin >> S;

    for (char c = 'a'; c <= 'z'; c++)
    {
        bool found = false;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == c)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << c << endl;
            return 0;
        }
    }
}
