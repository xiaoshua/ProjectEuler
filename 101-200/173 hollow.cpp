#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N = 1000000;

int main() {
    long long left, right, mid, mi, i;
    long long ans=0;
    for(i=3; ; ++i) {
        left=1;
        right=i-1;
        mi=-1;
        while(left<=right) {
            mid=(left+right)>>1;
            if(i*i-mid*mid<=N) {
                right=mid-1;
                mi=mid;
            } else {
                left=mid+1;
            }
        }
        if(mi==-1) break;
        if((i^mi)&1) ++mi;
        ans += (i-mi)/2;
    }
    cout<<ans<<endl;
    return 0;
}

