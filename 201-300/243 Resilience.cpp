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
int p[]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
LL ans = 1LL<<51;
LL x=15499, y=94744;
bool ok(LL a, LL b) {
//    return a/b<x/y;
    return a*y<b*x;
}
void dfs(int dep, LL cur, LL coP, int lim) {
    if(cur >= ans) {
        return;
    }
    if(cur>1 && ok(coP, cur-1)) {
        ans=cur;
        return;
    }
    cur *= p[dep];
    coP *= p[dep]-1;
    for(int i=1; i<=lim; ++i) {
        if(cur>=ans) {
            return;
        }
        dfs(dep+1, cur, coP, i);
        cur *= p[dep];
        coP *= p[dep];
    }
}

int main() {
    dfs(0, 1, 1, 60);
    cout<<ans<<endl;
    return 0;
}
