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
const int N = 10 * 1000 * 1000;
typedef long long LL;
int p[N / 2], pn;
bool notP[N];

void getP(int n = N) {
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


LL gao(int n) {
    getP(n);
    LL ret = 0;
    for (int i = 0; i < pn; ++i) {
        if (p[i] * p[i] >= n) {
            break;
        }
        for (int j = i + 1; j < pn; ++j) {
            if (p[i] * p[j] > n) {
                break;
            }

            LL a = p[i];
            LL b = p[j];
            while (a * b * p[j] <= n) {
                b *= p[j];
            }
            LL maxValue = a * b;

            while (true) {
                a *= p[i];
                while (a * b > n && b > p[j]) {
                    b /= p[j];
                }
                if (a * b > n) {
                    break;
                }
                maxValue = max(maxValue, a * b);
            }

            ret += maxValue;

        }
    }
    return ret;
}

int main() {
    clock_t begin = clock();
    LL sum = gao(N);
    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << sum << endl;
    return 0;
}
