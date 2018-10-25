#include <cmath>
#include <iostream>

using namespace std;

typedef long long LL;

/**
 *  1. x1 + x2 + x3 + ... + xm = m
 *  2. S(m) = (x1*x2^2*x3^3* ... * xm^m)
 *  =1*2^2*3^3* ... *m^m *(x1 * x2/2*x2/2 * x3/3*x3/3*x3/3 * ... * xm/m*xm/m* ... *xm/m)
 *  let a = 1*2^2*3^3* ...m^m;
 *      b = x1*x2/2*x2/2 * x3/3*x3/3*x3/3 * ... * xm/m*xm/m*xm/m ....
 *  so S(m) = a * b
 * use Inequality of arithmetic and geometric means(https://en.wikipedia.org/wiki/Inequality_of_arithmetic_and_geometric_means)
 *      b^[1/(1+2+3+...+m)] = b^{1/[m*(m+1)/2]} <= (x1 + x2/2 + x2/2 + x3/3 + x3/3 + x3/3 + ... + xm/m + ... +xm/m)/[m*(m+1)/2] = m/[m*(m+1)/2]
 *      let c = m*(m+1)/2
 *      so b <= (m/c)^c
 *      S(m) <= a*(m*2/c)^c
 *
 */
int main() {
    LL sum = 0;
    double a = 1;
    for (int i = 2; i <= 15; ++i) {
        for (int j = 0; j < i; ++j) {
            a *= i;
        }
        double c = i * (i + 1) / 2;
        double sm = a * pow(i / c, c);
        sum += LL(sm + 1e-9);
        if (i == 10) {
            cout << sm << endl;
        }
    }

    cout << sum << endl;
    return 0;
}
