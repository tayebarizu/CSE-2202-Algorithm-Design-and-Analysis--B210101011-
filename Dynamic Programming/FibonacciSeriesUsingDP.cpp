#include <bits/stdc++.h>
using namespace std;

void fibonacciDP(int n) {
    int fib[n];

    fib[0] = 0;
    if (n > 1)
        fib[1] = 1;

    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    cout << "Fibonacci Series using DP: ";
    for (int i = 0; i < n; i++) {
        cout << fib[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter how many terms: ";
    cin >> n;

    fibonacciDP(n);
    return 0;
}
