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
typedef __int64 LL;
LL gcd(LL a, LL b, LL & x, LL & y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    LL d = gcd(b, a % b, x, y), t;
    t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

LL gao(LL * a, LL * r, int n) {
    LL a1 = 1;
    LL r1 = 0;

    for(int i = 0; i < n; ++i) {
        LL a2 = a[i];
        LL r2 = r[i];
        LL x, y;
        LL tt = r2 - r1;
        LL d = gcd(a1, a2, x, y);

        if(tt % d) {
            return -1;
        }

        LL t = a2 / d;
        x = ((tt / d * x) % t + t) % t;
        r1 += a1 * x;
        a1 *= a2 / d;
        r1 %= a1;
    }

    return r1;
}
const int N = 2e6;
int p[N / 2], pn;
bool notP[N];
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

LL a[2], r[2];
int main() {
    getP();
    int limit = 1e6;
    LL ans = 0;
    LL ten = 1;

    for(int i = 2; p[i] <= limit; ++i) {
        if(p[i] > limit) {
            break;
        }

        while(ten < p[i]) {
            ten *= 10;
        }

        a[0] = ten;
        r[0] = p[i];
        a[1] = p[i + 1];
        r[1] = 0;
        LL ret = gao(a, r, 2);
        ans += ret;
    }

    cout << ans << endl;

    return 0;
}

