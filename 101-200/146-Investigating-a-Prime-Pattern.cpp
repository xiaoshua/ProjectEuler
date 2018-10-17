#include<string>
#include<iostream>
#include <cmath>
#include <vector>

using namespace std;

const int N = 150000000;
const int M = N + 1000000;

bool notP[M];
vector<int> p;

void init() {
    for (int i = 2; i < M; ++i) {
        if (!notP[i]) {
            p.push_back(i);
            for (int j = i + i; j < M; j += i) {
                notP[j] = true;
            }
        }
    }
}


bool isAllPrime(long long *arr, int len) {

    long long maxValue = arr[len - 1];
    if (maxValue < M) {
        for (int i = 0; i < len; ++i) {
            if (notP[arr[i]]) {
                return false;
            }
        }
        return true;
    }


    int end = (int) sqrt(1.0 * maxValue) + 9;
    int pn = (int) p.size();
    for (int i = 0; i < pn; ++i) {
        for (int j = 0; j < len; ++j) {
            if (arr[j] != p[i] && arr[j] % p[i] == 0) {
                return false;
            }
        }
        if (p[i] > end) {
            break;
        }
    }
    return true;

}

bool isPrime(long long n) {
    return isAllPrime(&n, 1);
}

int addArr[] = {1, 3, 7, 9, 13, 27};
int notInAddArr[] = {5, 11, 15, 17, 19, 21, 23, 25};

bool isConsecutivePrime(int n) {
    long long square = 1LL * n * n;
    long long nowArr[6];
    for (int i = 0; i < 6; ++i) {
        nowArr[i] = square + addArr[i];
    }
    if (!isAllPrime(nowArr, 6)) {
        return false;
    }

    //primes must be consecutive
    for (int a : notInAddArr) {
        if (isPrime(square + a)) {
            return false;
        }
    }
    return true;
}

int main() {

    init();
    long long answer = 0;
    for (int i = 10; i < N; i += 2) {
        if (isConsecutivePrime(i)) {
            answer += i;
        }
    }
    cout << answer << endl;
    return 0;
}
