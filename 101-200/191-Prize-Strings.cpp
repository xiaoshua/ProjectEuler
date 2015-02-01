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
const int N = 2e5 + 9;
const int DAY = 30;
const int TRIE_NUM = 3;
const int LATE_NUM = 2;
LL dp[DAY + 1][TRIE_NUM][LATE_NUM];
int main() {
    dp[0][0][0] = 1;

    for(int day = 0; day < DAY; ++day) {
        for(int trieStatus = 0; trieStatus < TRIE_NUM; ++trieStatus) {
            for(int lateStatus = 0; lateStatus < LATE_NUM; ++lateStatus) {
                for(int nextAlp = 0; nextAlp < 3; ++nextAlp) {

                    int nextTrieStatus;
                    int nextLateStatus;

                    // 0 on time
                    if(nextAlp == 0) {
                        nextTrieStatus = 0;
                        nextLateStatus = lateStatus;

                    } else
                        if(nextAlp == 1) { // 1 late
                            nextTrieStatus = 0;
                            nextLateStatus = lateStatus + 1;
                        } else { // 2 Absent
                            nextTrieStatus = trieStatus + 1;
                            nextLateStatus = lateStatus;
                        }

                    if(nextTrieStatus == TRIE_NUM || nextLateStatus == LATE_NUM) {
                        continue;
                    }

                    dp[day + 1][nextTrieStatus][nextLateStatus] += dp[day][trieStatus][lateStatus];
                }
            }
        }
    }

    LL ans = 0;

    for(int trieStatus = 0; trieStatus < TRIE_NUM; ++trieStatus) {
        for(int lateStatus = 0; lateStatus < LATE_NUM; ++lateStatus) {
            ans += dp[DAY][trieStatus][lateStatus];
        }
    }

    cout << ans << endl;

    return 0;
}
