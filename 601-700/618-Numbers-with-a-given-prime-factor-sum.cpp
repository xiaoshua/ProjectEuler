#include <cmath>
#include <iostream>

using namespace std;

typedef long long LL;


LL fib[25];

void initFib() {

    fib[1] = fib[2] = 1;
    for (int i = 3; i < 25; ++i) {
        fib[i] = fib[i - 2] + fib[i - 1];
    }

    // fib[24]=46368
}

const int MAX_FIB = 50000;
typedef long long LL;
int p[MAX_FIB], pn;
bool notP[MAX_FIB];

void initPrime(int n = MAX_FIB) {
    int i, j;

    for (i = 2; i < n; ++i) {
        if (!notP[i]) {
            p[pn++] = i;
        }

        for (j = 0; j < pn && i * p[j] < n; ++j) {
            notP[i * p[j]] = true;
            if (i % p[j] == 0) {
                break;
            }
        }
    }
}

const int MOD = 10000 * 100000;
//check code: force dfs algorithm
LL dfs(int &aimSum, int pi = 0, int sum = 0, LL multi = 1) {
    if (pi == pn) {
        return aimSum == sum ? multi : 0;
    }
    LL ret = 0;
    while (true) {
        ret += dfs(aimSum, pi + 1, sum, multi);
        sum += p[pi];
        multi = p[pi] * multi % MOD;
        if (sum > aimSum) {
            break;
        }
    }
    return ret % MOD;
}

LL dp_sum[MAX_FIB];

void do_dp() {
    dp_sum[0] = 1;
    for (int i = 0; i < pn; ++i) {
        int limit = MAX_FIB - p[i];
        for (int j = 0; j < limit; ++j) {
            dp_sum[j + p[i]] += dp_sum[j] * p[i];
            dp_sum[j + p[i]] %= MOD;
        }
    }
}

int main() {
    initFib();
    initPrime();
    int eight = 8;
    cout << dfs(eight) << endl;
    do_dp();
    cout << dp_sum[8] << endl;
    LL sum = 0;
    for (int i = 3; i < 25; ++i) {
        sum += dp_sum[fib[i]];
    }
    cout << sum % MOD << endl;

    //check for the dp algorithm, just ignore
    for (int j = 0; j < 60; ++j) {
        LL a = dfs(j);
        LL b = dp_sum[j];
        if (a != b) {
            cout << "wrong:" << j << ",real:" << a << ",my:" << b << endl;
//            break;
        }
    }
    return 0;
}
