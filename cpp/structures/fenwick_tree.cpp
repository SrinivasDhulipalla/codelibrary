#include <bits/stdc++.h>

using namespace std;

// https://e-maxx-eng.appspot.com/data_structures/fenwick.html

const int maxn = 200000;
int t[maxn];

void add(int t[], int i, int value) {
    for (; i < maxn; i |= i + 1)
        t[i] += value;
}

// sum[0..i]
int sum(int t[], int i) {
    int res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1)
        res += t[i];
    return res;
}

// Returns min(p | sum[0..p] >= sum)
int lower_bound(int t[], int sum) {
    int pos = 0;
    for (int blockSize = 1 << (31 - __builtin_clz(maxn)); blockSize != 0; blockSize >>= 1) {
        int p = pos + blockSize - 1;
        if (p < maxn && t[p] < sum) {
            sum -= t[p];
            pos += blockSize;
        }
    }
    return pos;
}


// usage example
int main() {
    add(t, 0, 4);
    add(t, 1, 5);
    add(t, 2, 5);
    add(t, 2, 5);

    cout << (4 == sum(t, 0)) << endl;
    cout << (19 == sum(t, 2)) << endl;
    cout << (2 == lower_bound(t, 19)) << endl;
    cout << (maxn == lower_bound(t, 20)) << endl;
}
