#include<time.h>
#include<iostream>

using namespace std;
const int N = (const int) (1e8 + 1);
typedef long long LL;
int p[N], pn;
int path[N];

bool getP(int n = N) {
    int i, j;

    for (i = 2; i < n; ++i) {
        if (!path[i]) {
            p[pn++] = i;
        }

        for (j = 0; j < pn && i * p[j] < n; ++j) {
            if (path[i] >= 0) {
                path[i * p[j]] = i;
            } else {
                path[i * p[j]] = -1;
            }

            if (i % p[j] == 0) {
                path[i * p[j]] = -1;
                break;
            }
        }
    }
}

int fac[100], flen;

bool dfs(int dep, int mul, int num) {
    if (dep == flen) {
        return !path[mul + num / mul];
    }
    return dfs(dep + 1, mul, num) && dfs(dep + 1, mul * fac[dep], num);
}

bool judge(int num) {
    flen = 0;
    int t = num;
    while (true) {
        if (!path[t]) {
            fac[flen++] = t;
            break;
        }
        if (flen > 50) {
            cout << num << endl;
        }
        fac[flen++] = t / path[t];
        t = path[t];
    }
    return dfs(0, 1, num);
}

int main() {
    clock_t begin = clock();
    getP();

    //1 is ok
    LL sum = 1;
    for (int i = 2; i < N - 1; ++i) {
        if (!path[i + 1] && path[i] >= 0 && judge(i)) {
            if (i < 1000) {
                cout << i << endl;
            }
            sum += i;
        }
    }

    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << sum << endl;
    return 0;
}
