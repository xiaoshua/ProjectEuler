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

const int maxPow = 59049;
LL dp[2][maxPow][11];
int threePow[11];

int cnt[10];

LL run() {
    int i, j, k, l;
    threePow[0] = 1;
    for (i = 1; i < 11; ++i) {
        threePow[i] = threePow[i - 1] * 3;
    }
    int pre = 0, cur = 1;
    dp[cur][0][0] = 1;
    for (i = 1; i < 21; ++i) {
        swap(pre, cur);
        memset(dp[cur], 0, sizeof(dp[cur]));
        memset(cnt, 0, sizeof(cnt));
        for (j = 0; j < maxPow; ++j) {
            int sumCnt = 0;
            if (j > 0) {
                ++cnt[0];
                int t = 0;
                while (cnt[t] == 3) {
                    cnt[t] = 0;
                    ++t;
                    ++cnt[t];
                }
                for (k = 0; k < 10; ++k) {
                    sumCnt += cnt[k];
                }
            }
            if (sumCnt + 1 != i) {
                continue;
            }
            for (k = 0; k < 11; ++k) {
                if (dp[pre][j][k] == 0) {
                    continue;
                }
                for (l = (i == 1 ? 1 : 0); l < 10; ++l) {
                    if (cnt[l] < 2) {
                        int newJ = j + threePow[l];
                        int newK = (k * 10 + l) % 11;
                        dp[cur][newJ][newK] += dp[pre][j][k];
                    }
                }
            }
        }
    }

    return dp[cur][maxPow - 1][0];

}


int main() {
    clock_t begin = clock();
    LL sum = run();
    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << sum << endl;
    return 0;
}
