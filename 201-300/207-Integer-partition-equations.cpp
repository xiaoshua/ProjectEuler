#include <cmath>
#include <iostream>

using namespace std;

typedef long long LL;

static const int den = 12345;

/**
 * 4^t = 2^t + k #4^t, 2^t, k are all positive integers, and (2^t)^=4^t
 * let x = 2^t
 * then x*(x-1)=k # x, k are all positive integers
 *
 */

LL find(LL count, LL perfectCount) {
    LL low = 1, ret = -1;
    LL high = LLONG_MAX >> 2;
    while (low <= high) {
        LL mid = (low + high) >> 1;
        if (perfectCount * den < count + mid) {
            ret = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ret;
}

int main() {
    LL count = 1;
    LL perfectCount = 1;
    LL lastBin = 2;
    LL answer = -1;
    while (true) {
        LL betweenCount = lastBin - 1;
        // perfectCount / count < 1 / 12345 ==> 12345 * perfectCount < count
        if (perfectCount * den < count + betweenCount) {
            LL diff = find(count, perfectCount);
            LL x = lastBin + diff;
            answer = x * (x - 1);
            break;
        }
        count += lastBin;
        lastBin <<= 1;
        ++perfectCount;
    }
    cout << answer << endl;
    return 0;
}
