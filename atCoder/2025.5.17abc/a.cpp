#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    // 時刻を分に変換して比較
    int deadline = A * 60 + B;
    int submit = C * 60 + D;

    if (submit < deadline) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
