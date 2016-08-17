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
//const int N = 100 + 1;
const int N = 10000 * 10000 + 1;
typedef long long LL;
int p[N / 2], pn;
int ans[N];
bool notP[N];
vector<int> vm[N / 2];

int getCount(int n, int prime) {
    int ret = 0;
    while (n) {
        n /= prime;
        ret += n;
    }
    return ret;
}

LL gao(int n = N) {
    int i, j;
    LL ret = 0;

    for (i = 2; i < n; ++i) {
        if (!notP[i]) {
            p[pn] = i;
            LL t = i;
            int m = i;
            int needCnt = 1;
            int realCnt = 1;
            while (t < n) {
                while (realCnt < needCnt) {
                    m += i;
                    realCnt = getCount(m, i);
                }
                vm[pn].push_back(m);
                ans[t] = m;
                t *= i;
                needCnt += 1;
            }
            ++pn;
        }

        ret += ans[i];

        for (j = 0; j < pn; ++j) {
            int curNum = i * p[j];
            if (curNum >= n) {
                break;
            }
            notP[curNum] = true;

            if (i % p[j] == 0) {
                int cnt = 1;
                int tmp = i;
                while (tmp % p[j] == 0) {
                    ++cnt;
                    tmp /= p[j];
                }
                ans[curNum] = max(ans[tmp], vm[j][cnt - 1]);
                break;
            } else {
                ans[curNum] = max(ans[p[j]], ans[i]);
            }
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
