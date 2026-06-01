#include <stdio.h>
#include <limits.h>

#define MAX 10

int m[MAX][MAX];  // min scalar multiplications
int s[MAX][MAX];  // split point table

int MatrixChainOrder(int p[], int n) {
    int i, j, k, L, q;

    // Single matrix — zero multiplications
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // L = chain length, from 2 up to n-1
    for (L = 2; L < n; L++) {
        for (i = 1; i <= n - L; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX;

            for (k = i; k <= j - 1; k++) {
                // Cost of splitting at k
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    return m[1][n - 1];
}

void printOptimalParens(int s[][MAX], int i, int j) {
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printf(" x ");
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main() {
    // Dimensions: A1=30×35, A2=35×15, A3=15×5,
    //             A4=5×10,  A5=10×20, A6=20×25
    int p[] = {30, 35, 15, 5, 10, 20, 25};
    int n = sizeof(p) / sizeof(p[0]);  // n = 7 (6 matrices)

    int minOps = MatrixChainOrder(p, n);

    printf("Minimum number of scalar multiplications: %d\n", minOps);
    printf("Optimal parenthesization: ");
    printOptimalParens(s, 1, n - 1);
    printf("\n");

    // Print m[][] table
    printf("\nCost Table m[i][j]:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (j < i) printf("%8s", "-");
            else       printf("%8d", m[i][j]);
        }
        printf("\n");
    }

    return 0;
}
