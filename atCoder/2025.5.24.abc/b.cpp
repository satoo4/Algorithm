#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int X, Y;
    cin >> X >> Y;

    int count = 0;
    for (int a = 1; a <= 6; ++a) {
        for (int b = 1; b <= 6; ++b) {
            if ((a + b >= X) || (abs(a - b) >= Y)) {
                count++;
            }
        }
    }

    double ans = count / 36.0;

    // 割り切れる場合（誤差考慮して判定）
    if (fabs(ans * 36 - round(ans * 36)) < 1e-9) {
        // 末尾の0を出さず、必要最低限の桁のみ表示
        cout << ans << endl;
    } else {
        // 誤差を抑えるために30桁まで表示
        cout << fixed << setprecision(30) << ans << endl;
    }

    return 0;
}
