/*
 * Practical 1: SET Operations - SIMPLE VERSION (No classes, no STL)
 * Easy to understand and explain in viva!
 */

#include <stdio.h>

#define MAX 100

// -------------------------------------------------------
// HELPER: Check if element exists in array
// Returns 1 (true) if found, 0 (false) if not found
// -------------------------------------------------------
int is_member(int arr[], int size, int elem) {
    for (int i = 0; i < size; i++)
        if (arr[i] == elem) return 1;
    return 0;
}

// -------------------------------------------------------
// HELPER: Print a set
// -------------------------------------------------------
void display(int arr[], int size) {
    printf("{ ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("}");
}

// -------------------------------------------------------
// 1. POWER SET
// Uses bitmask trick: for n elements, loop 0 to 2^n - 1
// Each bit of 'mask' tells us: include this element or not
// -------------------------------------------------------
void powerset(int A[], int n) {
    int total = 1 << n;  // 2^n
    printf("Power Set of A:\n");
    for (int mask = 0; mask < total; mask++) {
        printf("{ ");
        for (int i = 0; i < n; i++)
            if (mask & (1 << i))   // if i-th bit is set
                printf("%d ", A[i]);
        printf("}\n");
    }
    printf("Total subsets: %d\n", total);
}

// -------------------------------------------------------
// 2. SUBSET CHECK
// A is subset of B if every element of A is in B
// -------------------------------------------------------
int subset_of(int A[], int na, int B[], int nb) {
    for (int i = 0; i < na; i++)
        if (!is_member(B, nb, A[i])) return 0;
    return 1;
}

// -------------------------------------------------------
// 3. UNION: A ∪ B
// All elements of A + elements of B not already in A
// -------------------------------------------------------
int set_union(int A[], int na, int B[], int nb, int result[]) {
    int size = 0;
    for (int i = 0; i < na; i++)
        result[size++] = A[i];                  // add all of A
    for (int i = 0; i < nb; i++)
        if (!is_member(A, na, B[i]))            // add B[i] only if not in A
            result[size++] = B[i];
    return size;
}

// -------------------------------------------------------
// 4. INTERSECTION: A ∩ B
// Only elements present in BOTH A and B
// -------------------------------------------------------
int intersection(int A[], int na, int B[], int nb, int result[]) {
    int size = 0;
    for (int i = 0; i < na; i++)
        if (is_member(B, nb, A[i]))             // if A[i] is also in B
            result[size++] = A[i];
    return size;
}

// -------------------------------------------------------
// 5. COMPLEMENT: A' = U - A
// Elements in Universal set U but NOT in A
// -------------------------------------------------------
int complement(int A[], int na, int U[], int nu, int result[]) {
    int size = 0;
    for (int i = 0; i < nu; i++)
        if (!is_member(A, na, U[i]))            // if U[i] is NOT in A
            result[size++] = U[i];
    return size;
}

// -------------------------------------------------------
// 6. SET DIFFERENCE: A - B
// Elements in A but NOT in B
// Note: A-B is NOT same as B-A !
// -------------------------------------------------------
int set_difference(int A[], int na, int B[], int nb, int result[]) {
    int size = 0;
    for (int i = 0; i < na; i++)
        if (!is_member(B, nb, A[i]))            // if A[i] is NOT in B
            result[size++] = A[i];
    return size;
}

// -------------------------------------------------------
// 7. SYMMETRIC DIFFERENCE: A △ B = (A-B) ∪ (B-A)
// Elements in A or B but NOT in both
// -------------------------------------------------------
int symmetric_difference(int A[], int na, int B[], int nb, int result[]) {
    int diff1[MAX], diff2[MAX];
    int s1 = set_difference(A, na, B, nb, diff1);  // A - B
    int s2 = set_difference(B, nb, A, na, diff2);  // B - A
    return set_union(diff1, s1, diff2, s2, result); // (A-B) ∪ (B-A)
}

// -------------------------------------------------------
// 8. CARTESIAN PRODUCT: A x B
// All ordered pairs (a, b) where a ∈ A and b ∈ B
// Total pairs = |A| × |B|
// -------------------------------------------------------
void cartesian_product(int A[], int na, int B[], int nb) {
    printf("{ ");
    for (int i = 0; i < na; i++)
        for (int j = 0; j < nb; j++)
            printf("(%d,%d) ", A[i], B[j]);
    printf("}");
}

// -------------------------------------------------------
// MAIN
// -------------------------------------------------------
int main() {
    int A[MAX], B[MAX], U[MAX];
    int na, nb, nu;

    printf("Enter number of elements in Set A: ");
    scanf("%d", &na);
    printf("Enter elements of A: ");
    for (int i = 0; i < na; i++) scanf("%d", &A[i]);

    printf("Enter number of elements in Set B: ");
    scanf("%d", &nb);
    printf("Enter elements of B: ");
    for (int i = 0; i < nb; i++) scanf("%d", &B[i]);

    printf("Enter number of elements in Universal Set U: ");
    scanf("%d", &nu);
    printf("Enter elements of U: ");
    for (int i = 0; i < nu; i++) scanf("%d", &U[i]);

    int choice, result[MAX], size;

    do {
        printf("\n--- SET Operations Menu ---\n");
        printf("1. is_member\n");
        printf("2. powerset of A\n");
        printf("3. A subset of B?\n");
        printf("4. A union B\n");
        printf("5. A intersection B\n");
        printf("6. Complement of A\n");
        printf("7. A - B (set difference)\n");
        printf("8. A symmetric difference B\n");
        printf("9. A x B (cartesian product)\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int elem;
            printf("Enter element to check: ");
            scanf("%d", &elem);
            printf("%d in A: %s\n", elem, is_member(A, na, elem) ? "True" : "False");

        } else if (choice == 2) {
            powerset(A, na);

        } else if (choice == 3) {
            printf("A subset of B: %s\n", subset_of(A, na, B, nb) ? "True" : "False");

        } else if (choice == 4) {
            size = set_union(A, na, B, nb, result);
            printf("A union B = "); display(result, size); printf("\n");

        } else if (choice == 5) {
            size = intersection(A, na, B, nb, result);
            printf("A intersection B = "); display(result, size); printf("\n");

        } else if (choice == 6) {
            size = complement(A, na, U, nu, result);
            printf("Complement of A = "); display(result, size); printf("\n");

        } else if (choice == 7) {
            size = set_difference(A, na, B, nb, result);
            printf("A - B = "); display(result, size); printf("\n");

        } else if (choice == 8) {
            size = symmetric_difference(A, na, B, nb, result);
            printf("A symmetric diff B = "); display(result, size); printf("\n");

        } else if (choice == 9) {
            printf("A x B = "); cartesian_product(A, na, B, nb); printf("\n");
        }

    } while (choice != 0);

    return 0;
}
