/*
 * Practical 4: Find all non-negative integer solutions to
 * x1 + x2 + ... + xn = C  (C <= 10)
 * Using brute force strategy
 */

#include <iostream>
#include <vector>
using namespace std;

int total = 0;

void solve(int n, int C, int remaining, vector<int>& current) {
    if ((int)current.size() == n) {
        if (remaining == 0) {
            total++;
            for (int i = 0; i < n; i++)
                cout << "x" << (i+1) << "=" << current[i] << (i < n-1 ? " + " : "");
            cout << endl;
        }
        return;
    }

    for (int val = 0; val <= remaining; val++) {
        current.push_back(val);
        solve(n, C, remaining - val, current);
        current.pop_back();
    }
}

int main() {
    int n, C;
    cout << "Enter number of variables (n): "; cin >> n;
    cout << "Enter constant C (C <= 10): "; cin >> C;

    if (C > 10) {
        cout << "C must be <= 10 as per constraint.\n";
        return 1;
    }

    cout << "\nAll non-negative integer solutions to x1 + x2 + ... + x"
         << n << " = " << C << ":\n\n";

    vector<int> current;
    solve(n, C, C, current);

    cout << "\nTotal solutions: " << total << endl;
    return 0;
}
