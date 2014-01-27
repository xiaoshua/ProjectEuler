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

const int N = 9;
char s[N<<2];
int belongGrid[N][N];
int maskX[N], maskY[N], maskG[N];
int ans[N][N];
int bin[N<<1];
vector<pair<int,int> > vp;
bool f;
void dfs(int dep) {
    if(dep==vp.size() || f) {
        f=true;
        return;
    }
    int x=vp[dep].first, y=vp[dep].second, mask;
    mask = maskX[x] | maskY[y] | maskG[belongGrid[x][y]];
    for(int i=1; i<=N; ++i) {
        if(mask&bin[i]) continue;
        maskX[x] ^= bin[i];
        maskY[y] ^= bin[i];
        maskG[belongGrid[x][y]] ^= bin[i];
        ans[x][y]=i;
        dfs(dep+1);
        if(f) return;
        maskX[x] ^= bin[i];
        maskY[y] ^= bin[i];
        maskG[belongGrid[x][y]] ^= bin[i];
    }
}
void display() {
    int i, j;
    for(i=0; i<N; ++i) {
        for(j=0; j<N; ++j) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main() {
    int i, j, k, ed=0, sx, sy, x, y;
    for(i=0; i<(N<<1); ++i) bin[i]= 1<<i;

    for(i=0; i<9; i += 3) {
        for(j=0; j<9; j += 3) {
            for(x=i; x<i+3; ++x) {
                for(y=j; y<j+3; ++y) {
                    belongGrid[x][y]=ed;
                }
            }
            ++ed;
        }
    }

    freopen("sudoku", "r", stdin);
    char foo[100];
    int cnt=0, res=0;
    while(scanf("%s", foo)!=EOF) {
        scanf("%s", foo);
        vp.clear();
        fill(maskX, maskX+N, 0);
        fill(maskY, maskY+N, 0);
        fill(maskG, maskG+N, 0);
        for(i=0; i<N; ++i) {
            scanf("%s", s);
            for(j=0; j<N; ++j) {
                s[j] -= '0';
                ans[i][j]=s[j];
                if(s[j]==0) {
                    vp.push_back(make_pair(i, j));
                } else {
                    maskX[i] |= bin[s[j]];
                    maskY[j] |= bin[s[j]];
                    maskG[belongGrid[i][j]] |= bin[s[j]];
                }
            }
        }
        f=false;
        dfs(0);
        res += ans[0][0]*100+ans[0][1]*10+ans[0][2];
    }
    cout<<res<<endl;
    return 0;
}

