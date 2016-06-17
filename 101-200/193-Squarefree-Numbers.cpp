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
const int N = (1 << 25) + 10000;
typedef long long LL;
const LL INF = (1LL << 50) - 1;
int p[N], pn;
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

typedef pair<pair<int, int>, LL> Param;

Param getParam(int dep, int flag, LL mul) {
    return make_pair(make_pair(dep, flag), mul);
}


LL dfs(int dep, int flag, LL mul) {
    stack<Param> stackForDfs;

    stackForDfs.push(getParam(dep, flag, mul));

    LL ret = 0;

    while (!stackForDfs.empty()) {
        Param param = stackForDfs.top();
        stackForDfs.pop();
        mul = param.second;
        dep = param.first.first;
        flag = param.first.second;
        ret += flag * (INF / mul / mul);
        for (int i = dep; i < pn; ++i) {
            LL newMul = mul * 1LL * p[i];
            if (newMul > N) {
                break;
            }
            stackForDfs.push(getParam(i + 1, -flag, newMul));
        }
    }

    return ret;

}

int main() {
    clock_t begin = clock();
    getP();
    LL ans = dfs(0, 1, 1LL);
    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << ans << endl;

    return 0;

}
