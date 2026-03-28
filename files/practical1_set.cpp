/*
 * Practical 1: SET Class with Member Functions
 * Operations: is_member, powerset, subset, union, intersection,
 *             complement, set_difference, symmetric_difference, cartesian_product
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class SET {
public:
    vector<int> elements;

    SET() {}
    SET(vector<int> elems) {
        set<int> s(elems.begin(), elems.end());
        elements = vector<int>(s.begin(), s.end());
    }

    void display() {
        cout << "{ ";
        for (int e : elements) cout << e << " ";
        cout << "}";
    }

    bool is_member(int elem) {
        return find(elements.begin(), elements.end(), elem) != elements.end();
    }

    vector<SET> powerset() {
        vector<SET> result;
        int n = elements.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++)
                if (mask & (1 << i))
                    subset.push_back(elements[i]);
            result.push_back(SET(subset));
        }
        return result;
    }

    bool subset_of(SET& other) {
        for (int e : elements)
            if (!other.is_member(e)) return false;
        return true;
    }

    SET set_union(SET& other) {
        vector<int> res = elements;
        for (int e : other.elements)
            if (!is_member(e)) res.push_back(e);
        return SET(res);
    }

    SET intersection(SET& other) {
        vector<int> res;
        for (int e : elements)
            if (other.is_member(e)) res.push_back(e);
        return SET(res);
    }

    SET complement(SET& universal) {
        vector<int> res;
        for (int e : universal.elements)
            if (!is_member(e)) res.push_back(e);
        return SET(res);
    }

    SET set_difference(SET& other) {
        vector<int> res;
        for (int e : elements)
            if (!other.is_member(e)) res.push_back(e);
        return SET(res);
    }

    SET symmetric_difference(SET& other) {
        SET diff1 = set_difference(other);
        SET diff2 = other.set_difference(*this);
        return diff1.set_union(diff2);
    }

    void cartesian_product(SET& other) {
        cout << "{ ";
        for (int a : elements)
            for (int b : other.elements)
                cout << "(" << a << "," << b << ") ";
        cout << "}";
    }
};

int main() {
    int na, nb, nu;
    cout << "Enter number of elements in Set A: "; cin >> na;
    vector<int> a(na);
    cout << "Enter elements of A: ";
    for (int& x : a) cin >> x;

    cout << "Enter number of elements in Set B: "; cin >> nb;
    vector<int> b(nb);
    cout << "Enter elements of B: ";
    for (int& x : b) cin >> x;

    cout << "Enter number of elements in Universal Set U: "; cin >> nu;
    vector<int> u(nu);
    cout << "Enter elements of U: ";
    for (int& x : u) cin >> x;

    SET A(a), B(b), U(u);
    int choice;

    do {
        cout << "\n--- SET Operations Menu ---\n";
        cout << "1. is_member\n2. powerset of A\n3. A subset of B?\n";
        cout << "4. A union B\n5. A intersection B\n6. Complement of A\n";
        cout << "7. A - B (set difference)\n8. A symmetric difference B\n";
        cout << "9. A x B (cartesian product)\n0. Exit\n";
        cout << "Choice: "; cin >> choice;

        if (choice == 1) {
            int elem; cout << "Enter element: "; cin >> elem;
            cout << elem << " in A: " << (A.is_member(elem) ? "True" : "False") << endl;
        } else if (choice == 2) {
            vector<SET> ps = A.powerset();
            cout << "Power Set of A:\n";
            for (SET& s : ps) { s.display(); cout << "\n"; }
            cout << "Total subsets: " << ps.size() << endl;
        } else if (choice == 3) {
            cout << "A subset of B: " << (A.subset_of(B) ? "True" : "False") << endl;
        } else if (choice == 4) {
            cout << "A union B = "; A.set_union(B).display(); cout << endl;
        } else if (choice == 5) {
            cout << "A intersection B = "; A.intersection(B).display(); cout << endl;
        } else if (choice == 6) {
            cout << "Complement of A = "; A.complement(U).display(); cout << endl;
        } else if (choice == 7) {
            cout << "A - B = "; A.set_difference(B).display(); cout << endl;
        } else if (choice == 8) {
            cout << "A symmetric difference B = "; A.symmetric_difference(B).display(); cout << endl;
        } else if (choice == 9) {
            cout << "A x B = "; A.cartesian_product(B); cout << endl;
        }
    } while (choice != 0);

    return 0;
}
