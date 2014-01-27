#include<set>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef vector<double> VD;
typedef VD::iterator VDIT;
const int N = 101;
const double eps = 1e-8;

inline bool zero(double d) {
    return fabs(d)<eps;
}

inline int isInt(double n) {
    if(n<=-eps) return 0;
    int t = int(n+eps);
    if(!zero(t-n)) t=0;
    if(t>=N) t=0;
    return t;
}
bool exist[N];

void dfs(VD v) {
    if(v.size()==1) {
        exist[isInt(v[0])]=true;
        return;
    }
    VDIT i, j, k;
    for(VDIT i=v.begin(); i<v.end(); ++i) {
        for(VDIT j=v.begin(); j<v.end(); ++j) {
            if(i==j) continue;
            VD b;
            for(k=v.begin(); k<v.end(); ++k) {
                if(k!=i && k!=j) {
                    b.push_back(*k);
                }
            }
            b.push_back((*i)-(*j));
            dfs(b);
            if(!zero(*j)) {
                b.back()=(*i)/(*j);
                dfs(b);
            }
            if(i<j) {
                b.back()=(*i)+(*j);
                dfs(b);
                b.back()=(*i)*(*j);
                dfs(b);
            }
        }
    }
}

int main() {
    int a, b, c, d, ans, mx=-1, i;
    VD v;
    v.resize(4);
    for(a=1; a<10; ++a) {
        v[0]=a;
        for(b=a+1; b<10; ++b) {
            v[1]=b;
            for(c=b+1; c<10; ++c) {
                v[2]=c;
                for(d=c+1; d<10; ++d) {
                    memset(exist, 0, sizeof(exist));
                    v[3]=d;
                    dfs(v);
                    for(i=0; exist[i+1]; ++i) ;
                    if(i>mx) {
                        mx=i;
                        ans=d+c*10+b*100+a*1000;
                    }
                }
            }
        }
    }
    cout<<ans<<" "<<mx<<endl;
    return 0;
}

