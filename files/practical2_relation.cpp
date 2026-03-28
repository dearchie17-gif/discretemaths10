/*
 * Practical 2: RELATION Class using Matrix Notation
 * Checks: Reflexive, Symmetric, Anti-symmetric, Transitive
 * Classifies: Equivalence, Partial Order, or None
 */

#include <iostream>
#include <vector>
using namespace std;

class RELATION {
    int n;
    vector<vector<int>> matrix;

public:
    RELATION(int n, vector<vector<int>> mat) : n(n), matrix(mat) {}

    void display() {
        cout << "\nRelation Matrix:\n   ";
        for (int i = 0; i < n; i++) cout << i << "  ";
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << i << "  ";
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << "  ";
            cout << endl;
        }
    }

    bool isReflexive() {
        for (int i = 0; i < n; i++)
            if (matrix[i][i] != 1) return false;
        return true;
    }

    bool isSymmetric() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] != matrix[j][i]) return false;
        return true;
    }

    bool isAntisymmetric() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j && matrix[i][j] == 1 && matrix[j][i] == 1)
                    return false;
        return true;
    }

    bool isTransitive() {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 1)
                    for (int k = 0; k < n; k++)
                        if (matrix[j][k] == 1 && matrix[i][k] == 0)
                            return false;
        return true;
    }

    void classify() {
        bool R  = isReflexive();
        bool S  = isSymmetric();
        bool AS = isAntisymmetric();
        bool T  = isTransitive();

        cout << "\nReflexive      : " << (R  ? "Yes" : "No") << endl;
        cout << "Symmetric      : " << (S  ? "Yes" : "No") << endl;
        cout << "Anti-symmetric : " << (AS ? "Yes" : "No") << endl;
        cout << "Transitive     : " << (T  ? "Yes" : "No") << endl;

        if (R && S && T)
            cout << "\nRelation Type  : Equivalence Relation\n";
        else if (R && AS && T)
            cout << "\nRelation Type  : Partial Order Relation\n";
        else
            cout << "\nRelation Type  : None (not Equivalence or Partial Order)\n";
    }
};

int main() {
    int n;
    cout << "Enter number of elements in the set: "; cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " relation matrix row by row:\n";
    for (int i = 0; i < n; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }

    RELATION rel(n, matrix);
    rel.display();
    rel.classify();

    return 0;
}
