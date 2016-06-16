#include<time.h>
#include<iostream>
#include <vector>

using namespace std;
const int N = (const int) 1e6;
typedef long long LL;

vector<int> fac[N];
int dp[N];

void init() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            fac[j].push_back(i);
        }
    }
}

int getDigitSum(int n) {
    // 1 is not including
    if (n == 1) {
        return 0;
    }
    int ret = 0;
    while (n) {
        ret += n % 10;
        n /= 10;
    }
    return (ret - 1) % 9 + 1;
}

int getDp(int n) {

    int minFac = fac[n][0];
    int &ret = dp[n];
    ret = getDigitSum(n);
    for (int otherFac : fac[n / minFac]) {
        int a = minFac * otherFac;
        int b = n / a;
        ret = max(ret, dp[a] + dp[b]);
    }

    return ret;
}

int main() {
    clock_t begin = clock();
    init();
    LL sum = 0;
    clock_t end = clock();
    for (int i = 2; i < N; ++i) {
        sum += getDp(i);
    }
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << sum << endl;
    return 0;
}
