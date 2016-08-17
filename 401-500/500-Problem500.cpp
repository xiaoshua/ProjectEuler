#include<map>
#include<set>
#include<sstream>
#include<iostream>

using namespace std;
typedef long long LL;
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

//pair<cost, pair<prime, count> >
set<pair<LL, pair<int, int> > > si;
const int POW = 500500;
const int mod = 500500507;

int main() {
    clock_t begin = clock();
    getP();
    for (int i = 0; i < POW; ++i) {
        si.insert(make_pair(LL(p[i]) * p[i], make_pair(p[i], 1)));
    }

    while (true) {
        pair<LL, pair<int, int> > minCostNum = *si.begin();
        pair<LL, pair<int, int> > maxCostNum = *si.rbegin();
        if (minCostNum.first * minCostNum.first > maxCostNum.first) {
            break;
        }
        si.erase(si.begin());
        si.erase(maxCostNum);
        si.emplace(minCostNum.first * minCostNum.first,
                   make_pair(minCostNum.second.first, minCostNum.second.second * 2 + 1));
    }
    LL ans = 1;
    for (auto it = si.begin(); it != si.end(); ++it) {
        for (int i = 0; i < it->second.second; ++i) {
            ans = (ans * it->second.first) % mod;
        }
    }
    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << ans << endl;
    return 0;
}
