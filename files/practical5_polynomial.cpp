/*
 * Practical 5: Evaluate a Polynomial Function using an Array
 * Example: f(n) = 4n^2 + 2n + 9
 * Coefficients stored in array, evaluated for given n (default n=5)
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void displayPolynomial(vector<int>& coeffs) {
    int degree = coeffs.size() - 1;
    cout << "f(n) = ";
    bool first = true;
    for (int i = 0; i < (int)coeffs.size(); i++) {
        int power = degree - i;
        if (coeffs[i] == 0) continue;
        if (!first) cout << " + ";
        cout << coeffs[i];
        if (power == 1) cout << "n";
        else if (power > 1) cout << "n^" << power;
        first = false;
    }
    cout << endl;
}

long long evaluatePolynomial(vector<int>& coeffs, int n) {
    int degree = coeffs.size() - 1;
    long long result = 0;
    for (int i = 0; i < (int)coeffs.size(); i++) {
        int power = degree - i;
        result += (long long)coeffs[i] * (long long)pow(n, power);
    }
    return result;
}

int main() {
    int size;
    cout << "Polynomial Evaluator\n";
    cout << "Enter number of coefficients (degree+1): ";
    cin >> size;

    vector<int> coeffs(size);
    cout << "Enter coefficients from highest degree to constant:\n";
    cout << "(e.g., for 4n^2 + 2n + 9, enter: 4 2 9)\n";
    for (int i = 0; i < size; i++) {
        cout << "Coefficient " << i << ": ";
        cin >> coeffs[i];
    }

    cout << "\nPolynomial: ";
    displayPolynomial(coeffs);

    int n;
    cout << "Enter value of n (default 5): ";
    cin >> n;

    long long result = evaluatePolynomial(coeffs, n);
    cout << "\nf(" << n << ") = " << result << endl;

    return 0;
}
