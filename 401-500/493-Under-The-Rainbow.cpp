#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
typedef long double LD;
const int N = 21;

//ith color, ball number, distinct colors
LD dp[8][N][8];
LD fac[N];
LD eps = 1e-15;

void gao() {
    fac[0] = 1;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i - 1] * i;
    }

    dp[0][0][0] = 1;
    for (int t = 0; t < 7; ++t) {
        for (int i = N - 1; i >= 0; --i) {
            for (int j = 6; j >= 0; --j) {
                if (dp[t][i][j] < eps) {
                    continue;
                }
                for (int k = 0; k <= 10 && k + i < N; ++k) {
                    dp[t + 1][i + k][j + (k>0)] += dp[t][i][j] * fac[10] / fac[k] / fac[10 - k];
                }
            }
        }
    }

    LD all = 0;
    LD expect = 0;
    for (int i = 1; i <= 7; ++i) {
        all += dp[7][N - 1][i];
        expect += i * dp[7][N - 1][i];
    }
    cout << setprecision(20);
    cout << expect << "," << all << "," << expect / all << endl;


}

int main() {
    clock_t begin = clock();
    LL sum = 0;

    gao();
    clock_t end = clock();
    double allCost = 1.0 * (end - begin) / CLOCKS_PER_SEC;
    cout << "time cost:" << allCost << "S, answer:" << sum << endl;
    return 0;
}
