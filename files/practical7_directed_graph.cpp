/*
 * Practical 7: Accept a Directed Graph G and compute
 * In-degree and Out-degree of each vertex
 * Using Adjacency Matrix representation
 */

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class DirectedGraph {
    int n;
    vector<vector<int>> matrix;

public:
    DirectedGraph(int n, vector<vector<int>> mat) : n(n), matrix(mat) {}

    void display() {
        cout << "\nAdjacency Matrix:\n   ";
        for (int i = 0; i < n; i++) cout << i << "  ";
        cout << endl;
        for (int i = 0; i < n; i++) {
            cout << i << "  ";
            for (int j = 0; j < n; j++)
                cout << matrix[i][j] << "  ";
            cout << endl;
        }
    }

    void computeDegrees() {
        cout << "\n" << left
             << setw(10) << "Vertex"
             << setw(15) << "In-Degree"
             << setw(15) << "Out-Degree" << endl;
        cout << string(40, '-') << endl;

        int totalIn = 0, totalOut = 0;

        for (int i = 0; i < n; i++) {
            int outDeg = 0, inDeg = 0;
            for (int j = 0; j < n; j++) {
                outDeg += matrix[i][j];   // row sum = out-degree
                inDeg  += matrix[j][i];   // col sum = in-degree
            }
            totalIn  += inDeg;
            totalOut += outDeg;
            cout << left << setw(10) << i
                 << setw(15) << inDeg
                 << setw(15) << outDeg << endl;
        }

        cout << string(40, '-') << endl;
        cout << left << setw(10) << "Total"
             << setw(15) << totalIn
             << setw(15) << totalOut << endl;

        cout << "\nNote: Total In-Degree = Total Out-Degree = Number of Edges = "
             << totalOut << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of vertices in directed graph: "; cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }

    DirectedGraph g(n, matrix);
    g.display();
    g.computeDegrees();

    return 0;
}
