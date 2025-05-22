#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<long long> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    long long result = 1;
    //powで第一引数の第二引数乗を表現できる
    long long limit = pow(10, K);  

    for (int i = 0; i < N; i++) {
        result *= A[i];
        if (result >= limit) {
            result = 1;  
        }
    }

    cout << result << endl;
    return 0;
}
