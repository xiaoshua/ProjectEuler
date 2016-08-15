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

const int maxPow = 1 << 20;
const LL INF = 1000000 * 1000000LL;

map<LL, int> cnt;


int main() {
    clock_t begin = clock();
    for (int i = 2; i < maxPow; ++i) {
        LL curMul = 1LL * i * i;
        LL curSum = 1 + i + curMul;
        while (curSum < INF) {
            ++cnt[curSum];
            curMul *= i;
            curSum += curMul;
        }
    }
    LL sum = 1; // 1 is ok
    for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        sum += it->first;
    }
    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << sum << endl;
    return 0;
}
