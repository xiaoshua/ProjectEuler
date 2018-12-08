#include <cmath>
#include <iostream>

using namespace std;

typedef long long LL;

const int MAX_CNT = 51;
const int MAX_SUM = 10000 * 50;

char dp[MAX_CNT][MAX_SUM];

void merge(char &ret, char &add) {
    if (add > 1 || ret > 1) {
        ret = 2;
    } else {
        ret += add;
    }
}

int main() {

    dp[0][0] = 1;
    for (int i = 1; i <= 100; ++i) {
        int sq = i * i;
        for (int j = MAX_CNT - 2; j >= 0; --j) {
            for (int k = MAX_SUM; k >= 0; --k) {
                if (!dp[j][k]) {
                    continue;
                }
                merge(dp[j + 1][k + sq], dp[j][k]);
            }
        }
    }

    LL sum = 0;
    for (int i = 1; i < MAX_SUM; ++i) {
        if (dp[50][i] == 1) {
            sum += i;
        }
    }
    cout << sum << endl;

    return 0;
}
