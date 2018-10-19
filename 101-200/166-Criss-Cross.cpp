#include<string>
#include<iostream>

using namespace std;

typedef pair<int, int> PII;
const int N = 4;
int arr[N][N];


int sum;


PII range_by_row(int x, int y) {
    int remSum = sum;
    for (int i = 0; i < y; ++i) {
        remSum -= arr[x][i];
    }
    int remGrid = 3 - y;

    return make_pair(remSum - remGrid * 9, remSum);
}


PII range_by_column(int x, int y) {
    int remSum = sum;
    for (int i = 0; i < x; ++i) {
        remSum -= arr[i][y];
    }
    int remGrid = 3 - x;

    return make_pair(remSum - remGrid * 9, remSum);

}


PII range_by_diagonal1(int x, int y) {

    if (x != y) {
        return make_pair(0, 9);
    }

    int remSum = sum;
    int usedGrid = min(x, y);
    for (int i = 0; i < usedGrid; ++i) {
        remSum -= arr[i][i];
    }
    int remGrid = 3 - usedGrid;

    return make_pair(remSum - remGrid * 9, remSum);
}


bool check() {
    arr[3][3] = sum - arr[3][0] - arr[3][1] - arr[3][2];

    if (arr[3][3] < 0 || arr[3][3] > 9) {
        return false;
    }

    int sx[4] = {0}, sy[4] = {0}, d1 = 0, d2 = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            sx[i] += arr[i][j];
            sy[j] += arr[i][j];
            if (i == j) {
                d1 += arr[i][j];
            }
            if (i + j == 3) {
                d2 += arr[i][j];
            }
        }
    }

    if (sum != d1 || sum != d2) {
        return false;
    }

    for (int k = 0; k < 4; ++k) {
        if (sx[k] != sum || sy[k] != sum) {
            return false;
        }
    }
    return true;

}


int dfs(int dep) {
    if (dep == 15) {
        return check() ? 1 : 0;
    }

    int x = dep >> 2;
    int y = dep & 3;

    int ret = 0;

    if (dep < 4) {
        int tmpSum = 0;
        if (dep == 3) {
            for (int i = 0; i < 3; ++i) {
                tmpSum += arr[0][i];
            }
        }
        for (int i = 0; i < 10; ++i) {
            arr[x][y] = i;
            if (dep == 3) {
                sum = tmpSum + i;
            }
            ret += dfs(dep + 1);
        }
    } else if (y == 3) {
        arr[x][y] = sum - arr[x][0] - arr[x][1] - arr[x][2];
        if (arr[x][y] < 0 || arr[x][y] > 9) {
            return 0;
        }
        return dfs(dep + 1);
    } else if (x == 3) {
        arr[x][y] = sum - arr[0][y] - arr[1][y] - arr[2][y];
        if (arr[x][y] < 0 || arr[x][y] > 9) {
            return 0;
        }
        return dfs(dep + 1);
    } else if (x == 2 && y == 1) {
        arr[3][0] = sum - arr[0][0] - arr[1][0] - arr[2][0];
        arr[2][1] = sum - arr[0][3] - arr[1][2] - arr[3][0];
        if (arr[2][1] < 0 || arr[2][1] > 9 || arr[3][0] < 0 || arr[0][3] > 9) {
            return 0;
        }
        return dfs(dep + 1);
    } else {
        PII r1 = range_by_row(x, y);
        PII r2 = range_by_column(x, y);
        PII r3 = range_by_diagonal1(x, y);
        int start = max(0, max(r1.first, max(r2.first, r3.first)));
        int end = min(9, min(r1.second, min(r2.second, r3.second)));

        for (int i = start; i <= end; ++i) {
            arr[x][y] = i;
            ret += dfs(dep + 1);
        }
    }

    return ret;
}


int main() {
    cout << dfs(0) << endl;
    return 0;
}
