//http://www.mathblog.dk/project-euler-106-minimum-comparisons-special-sum-sets/
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
typedef long long LL;

const int N = 60;
LL C[N][N];
LL catalan(int n) {
    return C[2 * n][n] / (n + 1);
}
int main() {

    int i, j;

    for(i = 0; i < N; ++i) {
        C[i][0] = 1;

        for(j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    LL ans = 0;
    int n = 12;

    for(i = 2; i * 2 <= n; ++i) {
        ans += C[n][i] * C[n - i][i] / 2;
        ans -= C[n][2 * i] * catalan(i);
    }

    cout << ans << endl;

    return 0;
}
