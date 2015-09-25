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
const int N = 4e7;
typedef long long LL;
int p[N / 5], pn;
bool notP[N];
int euler[N];
int eulerLen[N];
LL sum = 0;
void getP(int n = N) {
    int i, j;
    euler[1] = 1;
    eulerLen[1] = 1;

    for(i = 2; i < n; ++i) {

        if(!notP[i]) {
            p[pn++] = i;
            euler[i] = i - 1;

        }

        eulerLen[i] = eulerLen[euler[i]] + 1;

        if(!notP[i] && eulerLen[i] == 25) {
            cout << i << endl;
            sum += i;
        }

        for(j = 0; j < pn; ++j) {
            int cur = i * p[j];

            if(cur >= n) {
                break;
            }

            notP[cur] = true;

            if(i % p[j] == 0) {
                euler[cur] = euler[i] * p[j];
                break;
            } else {
                euler[cur] = euler[i] * (p[j] - 1);
            }
        }
    }
}

int main() {
    getP();
    cout << sum << endl;
}


