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
typedef long long LL;
int cnt[1 << 20];
int main() {

    int limit = 1e6;
    int wantCnt = 10;
    LL d, x;

    for(d = 1; d <= limit; ++d) {
        for(x = 2 * d + 1; x < 3 * d; ++x) {
            LL val = -(x - d) * (x - 5 * d);

            if(val > limit) {
                break;
            }

            ++cnt[val];
        }

        for(x = 5 * d - 1; x >= 3 * d; --x) {
            LL val = -(x - d) * (x - 5 * d);

            if(val > limit) {
                break;
            }

            ++cnt[val];
        }
    }

    int ans = 0;

    for(int i = 1; i < limit; ++i) {
        if(cnt[i] == wantCnt) {
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}

