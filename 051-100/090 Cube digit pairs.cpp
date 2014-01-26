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

const int N = 6;
typedef vector<int> VI;
vector<VI> comb;

VI cur;
void genComb(int dep, int last) {
    if(dep==N) {
        comb.push_back(cur);
        return;
    }

    for(int i=last+1; i<10; ++i) {
        cur[dep]=i;
        genComb(dep+1, i);
    }

}
int x, y, z;
bool ok[111];
bool isOk(VI a, VI b) {
    memset(ok, 0, sizeof(ok));
    if(binary_search(a.begin(), a.end(), 6)) {
        a.push_back(9);
    }
    if(a.back()==9) {
        a.push_back(6);
    }
    if(binary_search(b.begin(), b.end(), 6)) {
        b.push_back(9);
    }
    if(b.back()==9) {
        b.push_back(6);
    }
    VI::iterator i, j;
    for(i=a.begin(); i!=a.end(); ++i) {
        for(j=b.begin(); j!=b.end(); ++j) {
            ok[(*i)*10+(*j)]=true;
            ok[(*j)*10+(*i)]=true;
        }
    }
    bool ret=true;
    for(int in=1; in<10; ++in) {
        if(!ok[in*in]) {
            ret=false;
        }
    }
    return ret;
}
void getAns() {
    int i, j;
    for(i=0; i<comb.size(); ++i) {
        VI &a = comb[i];
        for(j=0; j<comb.size(); ++j) {
            VI &b = comb[j];
            if(isOk(a, b)) {
                ++x;
                if(j>=i) {
                    ++y;
                }
            }
        }
    }
}
int main() {

    cur.resize(N);
    genComb(0, -1);
    getAns();
    cout<<x<<" "<<y<<endl;
    return 0;
}
