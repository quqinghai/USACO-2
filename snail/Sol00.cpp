#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 125
#define DMAX 4

int grid[MAX][MAX], vis[MAX][MAX];
int dim, bar, best, cur;

int ispoint (int row, int col) {
    return (row >= 0 && col >= 0 && row < dim && col < dim);
}

void mark (int a, int b) {
    vis[a][b] = 1;
    cur++;
}

void unmark (int a, int b) {
    vis[a][b] = 0;
    cur--;
}

void check () {
    if (cur > best) best = cur;
}

void search (int row, int col, int rc, int cc) {
    int a, b;
    if (vis[row][col]) {
        check ();
        return;
    }
    mark (row, col);
    if (!ispoint (row + rc, col + cc) || grid[row + rc][col + cc]) {
        check ();
        rc = !rc;
        cc = !cc;
        if (ispoint (row + rc, col + cc) && !grid[row + rc][col + cc])
            search (row + rc, col + cc, rc, cc);
        if (ispoint (row - rc, col - cc) && !grid[row - rc][col - cc])
            search (row - rc, col - cc, -rc, -cc);
    }
    else
        search (row + rc, col + cc, rc, cc);
    unmark (row, col);
}


int main () {
    FILE *in = fopen ("snail.in", "r");
    FILE *out = fopen ("snail.out", "w");
    int a, b, c;
    char ch[5];
    fscanf (in, "%d%d", &dim, &bar);
    for (a = 0; a < bar; a++) {
        fscanf (in, "%s", &ch);
        grid[atoi (ch + 1) - 1][ch[0] - 'A'] = 1;
    }
    search (0, 0, 0, 1);
    search (0, 0, 1, 0);
    fprintf (out, "%d\n", best);
    return 0;
}
