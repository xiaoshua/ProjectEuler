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


class Disjoint {
private:
    vector<int> parent;
public:
    void init(int n) {
        parent.resize(n);
        fill(parent.begin(), parent.end(), -1);
    }

    int find(int x) {
        return parent[x] < 0 ? x : parent[x] = find(parent[x]);
    }

    int getSubSetSize(int x) {
        int root = find(x);
        return -parent[root];
    }

    void merge(int a, int b) {
        int x = find(a), y = find(b);
        if (x != y) {
            parent[x] += parent[y];
            parent[y] = x;
        }
    }
};

vector<int> s;
const int mod = (int) 1e6;

int getS(int idx) {
    if (idx <= 55) {
        return (int) ((100003 - 200003 * idx + 300007LL * idx * idx * idx) % mod);
    } else {
        return (s[idx - 24] + s[idx - 55]) % mod;
    }
}

int main() {

    clock_t begin = clock();
    Disjoint disjoint;
    disjoint.init(mod);
    s.resize(1);
    int targetUid = 524287;
    int targetSize = 990000;
    int callCount = 0;
    for (int i = 1; ; i += 2) {
        int caller = getS(i);
        int called = getS(i + 1);
        s.push_back(caller);
        s.push_back(called);
        if (caller == called) {
            continue;
        }
        ++callCount;
        disjoint.merge(caller, called);
        if (disjoint.getSubSetSize(targetUid) >= targetSize) {
            break;
        }

    }

    clock_t end = clock();
    cout << "time cost:" << 1.0 * (end - begin) / CLOCKS_PER_SEC << "S, answer:" << callCount << endl;

    return 0;
}
