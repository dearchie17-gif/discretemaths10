/*
 * Practical 3: Generate all Permutations of a set of digits
 * - Without repetition
 * - With repetition
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Without repetition using next_permutation
void permutationsWithoutRepetition(vector<int> digits, int r) {
    // Take only first r elements and permute
    // Generate all r-length subsets first then permute
    sort(digits.begin(), digits.end());
    int count = 0;
    cout << "\nPermutations WITHOUT repetition (r=" << r << "):\n";

    // Use indices to select r elements
    vector<int> indices(digits.size());
    for (int i = 0; i < (int)digits.size(); i++) indices[i] = i;

    do {
        vector<int> chosen;
        for (int i = 0; i < r; i++) chosen.push_back(digits[indices[i]]);
        sort(chosen.begin(), chosen.end());
        do {
            for (int x : chosen) cout << x << " ";
            cout << endl;
            count++;
        } while (next_permutation(chosen.begin(), chosen.end()));
    } while (next_permutation(indices.begin(), indices.end()));

    // Simpler approach: generate all permutations of full set, take prefix of size r
    // Reset and use cleaner method
    count = 0;
    vector<int> perm = digits;
    sort(perm.begin(), perm.end());
    vector<vector<int>> results;
    do {
        vector<int> sub(perm.begin(), perm.begin() + r);
        results.push_back(sub);
    } while (next_permutation(perm.begin(), perm.end()));

    // Remove duplicates
    sort(results.begin(), results.end());
    results.erase(unique(results.begin(), results.end()), results.end());

    for (auto& p : results) {
        cout << "[ ";
        for (int x : p) cout << x << " ";
        cout << "]\n";
        count++;
    }
    cout << "Total: " << count << endl;
}

// With repetition using recursive generation
void generateWithRepetition(vector<int>& digits, vector<int>& current, int r) {
    if ((int)current.size() == r) {
        cout << "[ ";
        for (int x : current) cout << x << " ";
        cout << "]\n";
        return;
    }
    for (int d : digits) {
        current.push_back(d);
        generateWithRepetition(digits, current, r);
        current.pop_back();
    }
}

int main() {
    int n;
    cout << "Enter number of digits: "; cin >> n;
    vector<int> digits(n);
    cout << "Enter the digits: ";
    for (int& x : digits) cin >> x;

    int r;
    cout << "Enter length r: "; cin >> r;

    int choice;
    cout << "\n1. Without repetition\n2. With repetition\n3. Both\nChoice: ";
    cin >> choice;

    if (choice == 1 || choice == 3) {
        // Clean without-repetition
        sort(digits.begin(), digits.end());
        vector<vector<int>> results;
        do {
            vector<int> sub(digits.begin(), digits.begin() + r);
            results.push_back(sub);
        } while (next_permutation(digits.begin(), digits.end()));
        sort(results.begin(), results.end());
        results.erase(unique(results.begin(), results.end()), results.end());

        cout << "\nPermutations WITHOUT repetition (r=" << r << "):\n";
        for (auto& p : results) {
            cout << "[ ";
            for (int x : p) cout << x << " ";
            cout << "]\n";
        }
        cout << "Total: " << results.size() << endl;
    }

    if (choice == 2 || choice == 3) {
        cout << "\nPermutations WITH repetition (r=" << r << "):\n";
        vector<int> current;
        generateWithRepetition(digits, current, r);
    }

    return 0;
}
