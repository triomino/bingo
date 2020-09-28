#include <stdio.h>
#include <bit>

int check(char a[][3]) {
    int l0 = 1, l1 = 1, l2 = 1, r0 = 1, r1 = 1, r2 = 1, x0 = 1, x1 = 1;
    for (int i = 0; i < 3; ++i) {
        l0 &= a[0][i] == '*';
        l1 &= a[1][i] == '*';
        l2 &= a[2][i] == '*';
        r0 &= a[i][0] == '*';
        r1 &= a[i][1] == '*';
        r2 &= a[i][2] == '*';
        x0 &= a[i][i] == '*';;
        x1 &= a[i][2-i] == '*';
    }
    return l0 || l1 || l2 || r0 || r1 || r2 || x0 || x1;
}

int main(int argc, char *argv[]) {
    int lots;
    scanf("%d", &lots);
    int up = 1 << 9, tot = 0, all = 0;
    for (int i = 0; i < up; ++i) {
        int cnt = 0;
        char a[3][3];
        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                a[x][y] = '.';
            }
        }
        for (int j = i, p; j; j = j ^ p) {
            p = j & -j;
            int n = std::__popcount(p-1);
            a[n/3][n%3] = '*';
            cnt++;
        }
        if (cnt == lots) {
            all++;
            if (check(a)) {
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        printf("%c", a[x][y]);
                    }
                    printf("\n");
                }
                printf("\n");
                tot++;
            }
        }
    }
    printf("%d/%d\n", tot, all);
}