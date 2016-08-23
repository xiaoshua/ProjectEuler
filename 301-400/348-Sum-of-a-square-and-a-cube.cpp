#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = 21;

vector<LL> candidate;

int digit[N];

LL getCube(LL n) {
    LL left = 0, right = 1 << 20, mid, ret = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (mid * mid * mid <= n) {
            left = mid + 1;
            ret = mid;
        } else {
            right = mid - 1;
        }
    }
    return ret;
}

void judge(int len) {
    LL num = 0;
    for (int i = 0; i < len; ++i) {
        num = num * 10 + digit[i];
    }

    LL cube = getCube(num);
    LL square = 2;
    int cnt = 0;
    for (LL i = cube; i > 1; --i) {
        LL a = i * i * i;
        while (a + square * square < num) {
            ++square;
        }
        if (a + square * square == num) {
            ++cnt;
        }
    }
    if (cnt == 4) {
        cout << num << endl;
        candidate.push_back(num);
    }
}

void dfs(int len, int L, int R) {

    if (L > R) {
        judge(len);
        return;
    }


    for (int i = (L == 0); i < 10; ++i) {
        digit[L] = digit[R] = i;
        dfs(len, L + 1, R - 1);
    }
}

void gao() {
    for (int len = 1; ; ++len) {
        dfs(len, 0, len - 1);
        cout << "len:" << len << endl;
        if (candidate.size() >= 5) {
            break;
        }
    }

    sort(candidate.begin(), candidate.end());
    LL sum = 0;
    for (int i = 0; i < 5; ++i) {
        sum += candidate[i];
    }
    cout << "sum:" << sum << endl;
}

int main() {
    clock_t begin = clock();
    gao();
    clock_t end = clock();
    double allCost = 1.0 * (end - begin) / CLOCKS_PER_SEC;
    cout << "time cost:" << allCost << endl;
    return 0;
}
