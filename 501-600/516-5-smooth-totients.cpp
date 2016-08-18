#include<set>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>

using namespace std;
typedef long long LL;
const int N = (int) 1e7;
typedef long long LL;
int p[N / 10], pn;
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

bool isPrime(LL n) {
    if (n < N) {
        return !notP[n];
    }
    for (int i = 0; 1LL * p[i] * p[i] <= n; ++i) {
        if (n % p[i] == 0) {
            return false;
        }
    }
    return true;
}

const LL INF = 1000000L * 1000000L;
//const LL INF = 100;

vector<LL> hamNumber;

void getHamNumber() {
    priority_queue<LL, vector<LL>, greater<LL> > pq;
    int primes[] = {2, 3, 5};
    for (auto p : primes) {
        pq.push(p);
    }

    while (true) {
        LL ham = pq.top();
        if (ham > INF) {
            break;
        }
        while (pq.top() == ham) {
            pq.pop();
        }
        for (auto p : primes) {
            pq.push(p * ham);
        }
        hamNumber.push_back(ham);
    }

}

vector<LL> validBase;

LL ans = 0;

const LL mask = (1LL << 32) - 1;

void dfs(int dep, LL mul) {

    // * may too big
    if (dep == validBase.size() || validBase[dep] > INF / mul) {
        if (mul <= INF) {
            ans += mul;
            ans &= mask;
        }
        return;
    }

    dfs(dep + 1, mul);
    mul *= validBase[dep];
    dfs(dep + 1, mul);
    mul *= validBase[dep];
    if (dep <= 2) {
        while (mul <= INF) {
            dfs(dep + 1, mul);
            mul *= validBase[dep];
        }
    }
}

int main() {
    clock_t begin = clock();
    getP();
    getHamNumber();
    validBase.push_back(2);
    for (auto ham : hamNumber) {
        if (isPrime(ham + 1) && ham + 1 <= INF) {
            validBase.push_back(ham + 1);
        }
    }

    dfs(0, 1);

    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << ans << endl;
    return 0;
}
