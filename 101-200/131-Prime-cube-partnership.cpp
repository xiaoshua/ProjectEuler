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
const int N = 1e6 + 1;
typedef long long LL;
int p[N / 2], pn;
bool notP[N];
void getP(int n = N) {
    int i, j;

    for(i = 2; i < n; ++i) {
        if(!notP[i]) {
            p[pn++] = i;
        }

        for(j = 0; j < pn && i * p[j] < n; ++j) {
            notP[i * p[j]] = true;

            if(i % p[j] == 0) {
                break;
            }
        }
    }
}

LL cubic[N];

int main() {
    int i, j;
    getP();

    for(i = 0; i < N; ++i) {
        cubic[i] = 1LL * i * i * i;
    }

    int cnt = 0;
    LL limit = 1e6;

    for(i = 0; i < N; ++i) {
        for(j = i - 1; j > 0; --j) {
            LL dif = cubic[i] - cubic[j];

            if(dif > limit) {
                break;
            }

            if(!notP[dif]) {
                cout << dif << endl;
                ++cnt;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
