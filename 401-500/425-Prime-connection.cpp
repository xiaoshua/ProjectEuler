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
typedef pair<int, int> PII;
typedef vector<int> VI;
const int N = (const int) (1e7 + 1);

int p[N / 2], pn;
bool notP[N];

void getP(int n = N) {
    int i, j;
    notP[1] = true;
    notP[0] = true;
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


VI digit;

void getDigit(int n) {
    digit.clear();
    while (n) {
        digit.push_back(n % 10);
        n /= 10;
    }
}

int tenPower[10];

void getRelation(int n, VI &relation) {
    getDigit(n);
    relation.clear();

    int len = (int) digit.size();
    // remove digit
    if (n > 9) {
        int t = n / 10;
        if (!notP[t]) {
            relation.push_back(t);
        }
        t = n - tenPower[len - 1] * digit[len - 1];
        if (!notP[t]) {
            relation.push_back(t);
        }
    }

    //add digit
    for (int i = 1; i < 10; ++i) {
        int t = i * tenPower[len] + n;
        if (t < N && !notP[t]) {
            relation.push_back(t);
        }
    }

    //replace digit
    for (int j = 0; j < len; ++j) {
        int clearN = n - digit[j] * tenPower[j];
        for (int k = 0; k < 10; ++k) {
            int t = clearN + k * tenPower[j];
            if (t < N && !notP[t]) {
                relation.push_back(t);
            }
        }
    }

}


bool isRelation[N];
bool inq[N];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {

    clock_t begin = clock();
    getP();
    tenPower[0] = 1;
    for (int i = 1; i < 10; ++i) {
        tenPower[i] = tenPower[i - 1] * 10;
    }
    LL ans = 0;
    pq.push(2);
    isRelation[2] = inq[2] = true;
    VI relationPrime;

    for (int i = 2; i < N; ++i) {
        while (!pq.empty() && pq.top() <= i) {
            int cur = pq.top();
            pq.pop();
            isRelation[cur] = true;
            getRelation(cur, relationPrime);
            for (auto p : relationPrime) {
                if (!inq[p]) {
                    inq[p] = true;
                    pq.push(p);
                }
            }
        }
        if (!notP[i] && !isRelation[i]) {
            if (i < 1000) {
                cout << i << endl;
            }
            ans += i;
        }
    }

    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << ans << endl;

    return 0;
}
