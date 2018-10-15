#include<string>
#include<vector>
#include<iostream>

using namespace std;

const int N = 1000 * 10000 + 1;

vector<int> fac[N];

//assume 0 < a < n,
//a*a%n==a%n
// -> a*(a-1)%n==0
// a and a-1 both contain a fac of n

void init() {
    for (int i = 1; i < N; ++i) {
        for (int j = i; j < N; j += i) {
            fac[j].push_back(i);
        }
    }
}

int answer[N];

int main() {

    init();
    //1 must fix the condition
    fill(answer, answer + N, 1);
    answer[1] = 0;
    for (int a = 2; a < N; ++a) {
        for (int f1 : fac[a]) {
            for (int f2 : fac[a - 1]) {
                long long facMulti = 1LL * f1 * f2;
                if (facMulti >= N) {
                    break;
                }
                if (facMulti > a) {
                    answer[facMulti] = max(answer[facMulti], a);
                }
            }
        }
    }

    long long sum = 0;

    for (int i = 1; i < N; ++i) {
        sum += answer[i];
    }

    cout << sum << endl;
    return 0;
}
