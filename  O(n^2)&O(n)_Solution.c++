#include <iostream>
using namespace std;

// Slow solution - O(n^2)
int countSumSlow(int n) {
    int sum = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            sum += j;
        }
    }

    return sum;
}

// Fast solution - O(n)
int countSumFast(int n) {
    int sum = (n * (n + 1)) / 2;
    return sum;
}

int main() {
    int n = 5;
    cout << "Sum using slow solution: " << countSumSlow(n) << endl;
    cout << "Sum using fast solution: " << countSumFast(n) << endl;
    return 0;
}