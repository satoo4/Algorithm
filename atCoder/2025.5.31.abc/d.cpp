#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int totalOnes = 0;
        for (char c : S) {
            if (c == '1') totalOnes++;
        }

        int maxGain = 0, gain = 0;
        for (char c : S) {
            int val = (c == '1') ? 1 : -1;
            gain = max(val, gain + val);
            maxGain = max(maxGain, gain);
        }

        int ans = totalOnes - maxGain;
        cout << ans << '\n';
    }
    return 0;
}
