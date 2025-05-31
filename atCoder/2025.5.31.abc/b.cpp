#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    set<int> unique_sorted;
    for (int i = 0; i < N; ++i) {
        unique_sorted.insert(A[i]);
    }

    cout << unique_sorted.size() << endl;
    for (int num : unique_sorted) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
