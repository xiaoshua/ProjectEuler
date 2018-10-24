#include <cmath>
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (a && b) {
        if (a > b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a + b;
}
/*
 * https://github.com/nayuki/Project-Euler-solutions/blob/master/java/p139.java
 * Pythagorean triples theorem:
 *   Every primitive Pythagorean triple with a odd and b even can be expressed as
 *   a = st, b = (s^2-t^2)/2, c = (s^2+t^2)/2, where s > t > 0 are coprime odd integers.
 */
//==> c % (b-a) ==0
const int LIMIT = (const int) 1e8;


int main() {

    int answer = 0;
    int MAX_S = (int) (sqrt(1.0 * LIMIT) + 100);
    for (int s = 3; s < MAX_S; s += 2) {
        for (int t = 1; t < s; t += 2) {
            int a = s * t;
            int b = (s * s - t * t) >> 1;
            int c = (s * s + t * t) >> 1;
            int sum = a + b + c;
            if (sum >= LIMIT) {
                break;
            }
            if (gcd(a, b) == 1 && c % (a - b) == 0) {
                cout << a << "," << b << "," << c << endl;
                /**
                 * 3,4,5
                 * 21,20,29
                 * 119,120,169
                 * 697,696,985
                 * 4059,4060,5741
                 * 23661,23660,33461
                 * 137903,137904,195025
                 * 803761,803760,1136689
                 * 4684659,4684660,6625109
                 * 27304197,27304196,38613965
                 * abs(a - b) == 1 always true???
                 */
                answer += (LIMIT - 1) / sum;
            }
        }
    }

    cout << answer << endl;

    return 0;
}
