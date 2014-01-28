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

const int N = 201;

int phi(int n) {
    int r=n, i;
    for(i=2; i*i<=n; ++i) {
        if(n%i==0) {
            r -= r/i;
            while(n%i==0) {
                n /= i;
            }
        }
    }
    if(n!=1) {
        r -= r/n;
    }
    return r;
}
int pMod(long long a, int n, int mod) {
    long long r=1;
    while(n) {
        if(n&1) {
            r=(r*a)%mod;
        }
        a=(a*a)%mod;
        n>>=1;
    }
    return (int)r;
}
int dfs(int dep, int cur, int mod) {
    if(dep==1) {
        return cur;
    }
    int ph = phi(mod), t;
    t = dfs(dep-1, cur, ph);
    int r = pMod(cur, t, mod)+mod;
    return r;
}
int main() {
    cout<<dfs(1855, 1777, 100000000);
    return 0;
}
