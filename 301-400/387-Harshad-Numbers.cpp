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
typedef pair<LL, int> Harshad;
const LL INF = 100000LL * 100000LL * 10000;

bool isPrime(LL n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if ((n & 1) == 0) {
        return false;
    }
    for (LL i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}


queue<Harshad> normal;
queue<LL> strong;

int main() {
    clock_t begin = clock();
    LL sum = 0;
    int harshadCount = 0;
    for (int i = 1; i < 10; ++i) {
        normal.push(make_pair(i * 1LL, i));
        ++harshadCount;
    }
    while (!normal.empty()) {
        auto curElement = normal.front();
        normal.pop();
        LL value = curElement.first;
        int digitSum = curElement.second;
        for (int i = 0; i < 10; ++i) {
            LL newValue = value * 10 + i;
            int newDigitSum = digitSum + i;
            if (newValue >= INF / 10) {
                break;
            }

            if (newValue % newDigitSum == 0) {
                ++harshadCount;
                normal.push(make_pair(newValue, newDigitSum));
                if (isPrime(newValue / newDigitSum)) {
                    strong.push(newValue);
                }
            }
        }
    }

    while (!strong.empty()) {
        LL strongNumber = strong.front();
        strong.pop();
        for (int i = 0; i < 10; ++i) {
            LL newNumber = strongNumber * 10 + i;
            if (newNumber >= INF) {
                break;
            }
            if (isPrime(newNumber)) {
                if (newNumber <= 10000) {
                    cout << "ok:" << newNumber << endl;
                }
                sum += newNumber;
            }
        }
    }

    clock_t end = clock();
    cout << harshadCount << endl;
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << sum << endl;
    return 0;
}
