//from: http://www.mathblog.dk/project-euler-122-efficient-exponentiation/
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

int res[N], path[N];
void dfs(int dep, int val) {
    if(val>=N || dep>res[val]) {
        return;
    }
    res[val]=dep;
    path[dep]=val;
    for(int i=dep; i>=0; --i) {
        dfs(dep+1, val+path[i]);
    }
}
int main() {

    int ans=0, i;
    for(i=0; i<N; ++i) res[i]=111;
    dfs(0, 1);
    for(i=1; i<N; ++i) {
        cout<<i<<" "<<res[i]<<endl;
        ans += res[i];
    }
    cout<<ans<<endl;
    return 0;
}
