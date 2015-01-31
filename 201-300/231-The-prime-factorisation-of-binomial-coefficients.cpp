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

const int N = 2e7+9;
int p[N/5], pn;
bool notP[N];
void getP(int n=N) {
    int i, j;
    for(i=2; i<n; ++i) {
        if(!notP[i]) p[pn++]=i;
        for(j=0; j<pn && i*p[j]<n; ++j) {
            notP[i*p[j]]=true;
            if(i%p[j]==0) break;
        }
    }
}

int getPow(int fac, int p) {
    int r=0;
    while(fac>=p) {
        fac /= p;
        r += fac;
    }
    return r;
}

int main() {
    getP();
    int n=20000000, m=15000000;
    long long ans=0;
    for(int i=0; i<pn; ++i) {
        ans += p[i]*(getPow(n, p[i])-getPow(m, p[i]) - getPow(n-m, p[i]));
    }
    cout<<ans<<endl;
}
