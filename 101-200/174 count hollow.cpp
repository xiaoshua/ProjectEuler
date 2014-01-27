#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 1000000;
int dp[N+1];
int test;
int main() {
    long long i, j, used;
    for(i=3; i<N; ++i) {
        for(j=i-2; j>0; j -= 2) {
            used = (i*i-j*j);
            if(used>=N) break;
            ++dp[used];
        }
    }
    int ans=0;
    for(i=1; i<=N; ++i) {
        if(dp[i]>=1 && dp[i]<=10) {
            ++ans;
        } else if(dp[i]==15) {
            ++test;
        }
    }
    cout<<ans<<" "<<test<<endl;
    return 0;
}
