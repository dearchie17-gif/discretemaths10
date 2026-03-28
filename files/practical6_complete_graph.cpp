/*
 * Practical 6: Check if a given graph is a Complete Graph
 * Using Adjacency Matrix representation
 * A complete graph Kn has edges between every pair of distinct vertices
 */

#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> matrix;

public:
    Graph(int n, vector<vector<int>> mat) : n(n), matrix(mat) {}

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

    bool isCompleteGraph() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j && matrix[i][j] != 0) return false;   // no self-loops
                if (i != j && matrix[i][j] != 1) return false;   // all pairs connected
            }
        }
        return true;
    }

    void analyze() {
        int edgeCount = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                edgeCount += matrix[i][j];

        int expectedEdges = n * (n - 1);
        cout << "\nExpected edges for K" << n << " : " << expectedEdges << endl;
        cout << "Actual edges (directed count): " << edgeCount << endl;

        if (isCompleteGraph())
            cout << "\nResult: The graph IS a Complete Graph (K" << n << ").\n";
        else
            cout << "\nResult: The graph is NOT a Complete Graph.\n";
    }
};

int main() {
    int n;
    cout << "Enter number of vertices: "; cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the " << n << "x" << n << " adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        cout << "Row " << i << ": ";
        for (int j = 0; j < n; j++) cin >> matrix[i][j];
    }

    Graph g(n, matrix);
    g.display();
    g.analyze();

    return 0;
}
