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
int bin[20];
vector<int> v;
int primeCnt[1 << 10];
int getVal() {
    int r = 0, i;

    for(i = 0; i < v.size(); ++i) {
        r = r * 10 + v[i];
    }

    return r;
}

bool isPrime(int n) {
    if(n == 1) {
        return false;
    } else if(n == 2) {
        return true;
    } else if(n % 2 == 0) {
        return false;
    }

    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}
vector<int> primes;
LL dp[1 << 9];
int main() {

    int i , j, k;

    for(i = 0; i < 20; ++i) {
        bin[i] = 1 << i;
    }

    int cnt = 0;

    for(i = 1; i < bin[9]; ++i) {
        v.clear();
        int sum = 0;

        for(j = 0; j < 9; ++j) {
            if(i & bin[j]) {
                sum += j + 1;
                v.push_back(j + 1);
            }
        }


        do {
            int val = getVal();
            primeCnt[i] += isPrime(val);
        } while(next_permutation(v.begin(), v.end()));

        if(primeCnt[i] != 0) {
            ++cnt;
            primes.push_back(i);
        }
    }

    dp[0] = 1;

    for(i = 0; i < bin[9]; ++i) {
        if(dp[i] == 0) {
            continue;
        }

        for(j = 0; j < 9; ++j) {
            if(!(i & bin[j])) {
                break;
            }
        }

        if(j == 9) {
            continue;
        }

        for(k = 0; k < primes.size(); ++k) {
            if((primes[k]&bin[j]) && !(i & primes[k])) {
                dp[i | primes[k]] += dp[i] * primeCnt[primes[k]];
            }
        }
    }

    cout << dp[bin[9] - 1] << endl;

    return 0;
}


