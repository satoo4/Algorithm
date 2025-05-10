#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long total = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total += A[i];
    }

    long long result = 0;
    for (int i = 0; i < N; ++i) {
        total -= A[i]; // A[i]より後ろの和にする
        result += A[i] * total;
    }

    cout << result << endl;
    return 0;
}
