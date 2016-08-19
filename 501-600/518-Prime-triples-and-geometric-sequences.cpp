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
const int N = (int) 1e8;

int p[N], pn;
bool notP[N];
int simpleNumber[N];

void getP(int n = N) {
    int i, j;

    simpleNumber[1] = 1;
    for (i = 2; i < n; ++i) {
        if (!notP[i]) {
            simpleNumber[i] = i;
            p[pn++] = i;
        }

        for (j = 0; j < pn; ++j) {
            int curNum = i * p[j];
            if (curNum >= N) {
                break;
            }
            notP[curNum] = true;

            if (simpleNumber[i] % p[j] == 0) {
                simpleNumber[curNum] = simpleNumber[i] / p[j];
            } else {
                simpleNumber[curNum] = simpleNumber[i] * p[j];
            }


            if (i % p[j] == 0) {
                break;
            }
        }
    }
}

int sqrtNum[N];

void getSqrt() {
    for (int i = 0; i < N; ++i) {
        int sqr = i * i;
        if (sqr >= N) {
            break;
        }
        sqrtNum[sqr] = i;
    }
}

vector<int> candidate[N];

int main() {
    clock_t begin = clock();
    getP();
    getSqrt();

    for (int i = 0; i < pn; ++i) {
        int num = p[i] + 1;
        if (num <= N) {
            candidate[simpleNumber[num]].push_back(num);
        }
    }

    LL sum = 0;

    for (int i = 1; i < N; ++i) {
        int baseNum = i;

        vector<int> &curCandidate = candidate[i];
        int sz = (int) curCandidate.size();
        for (int k = 0; k < sz; ++k) {
            for (int l = k + 1; l < sz; ++l) {
                int curNum = baseNum * sqrtNum[curCandidate[k] / baseNum] * sqrtNum[curCandidate[l] / baseNum];
                if (!notP[curNum - 1]) {
                    sum += curCandidate[k] + curCandidate[l] + curNum - 3;
                    if (curCandidate[l] < 100) {
                        cout << "--------" << endl;
                        cout << curCandidate[k] - 1 << ":" << curNum - 1 << ":" << curCandidate[l] - 1 << endl;
                    }
                }
            }
        }
    }

    clock_t end = clock();
    double allCost = 1.0 * (end - begin) / CLOCKS_PER_SEC;
    cout << "time cost:" << allCost << "S, answer:" << sum << endl;
    return 0;
}
