#include <cmath>
#include <iostream>

using namespace std;

//const int LIMIT = 100;
const int LIMIT = 50 * 1000 * 1000;

int cnt[LIMIT];

/**
 * x = y+d, z = y-d>0
 * (y+d)^2-y^2-(y-d)^2=n
 * 4dy-y^2=n
 * y(4d-y)=n
 */
int main() {
    for (int y = 1; y < LIMIT; ++y) {
        int maxI = 3 * y;
        for (int i = -y & 3; i < maxI; i += 4) {
            // d = (i+y)/4;
            // z = y - d > 0
            // y - (i+y)/4>0
            // 3y -i > 0
            // i < 3y
            int n = y * i;
            if (n >= LIMIT) {
                break;
            }
            ++cnt[n];
        }
    }

    int answer = 0;
    for (int i = 0; i < LIMIT; ++i) {
        if (cnt[i] == 1) {
            ++answer;
        }
    }

    cout << answer << endl;

    return 0;
}
