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
const int N = 2e6;
typedef long long LL;
int p[N / 3], pn;
bool notP[N];
LL mod = 1e16;
void add(LL & a, LL b) {
    a += b;

    if(a >= mod) {
        a %= mod;
    }
}
void getP(int n = N) {
    int i, j;

    for(i = 2; i < n; ++i) {
        if(!notP[i]) {
            p[pn++] = i;
        }

        for(j = 0; j < pn && i * p[j] < n; ++j) {
            notP[i * p[j]] = true;

            if(i % p[j] == 0) {
                break;
            }
        }
    }
}

LL dp[N];
LL getResult() {
    getP();
    dp[0] = 1;
    int i, j;
    for(i = 2; i < 5000; ++i) {
        if(!notP[i]) {
            for(j = N - 1 - i; j >= 0; --j) {
                add(dp[j + i], dp[j]);
            }

        }
    }

    LL ans = 0;

    for(i = 2; i < N; ++i) {
        if(!notP[i]) {
            add(ans, dp[i]);
        }
    }
    return ans;
}
int main() {
    cout << getResult();
    return 0;
}


