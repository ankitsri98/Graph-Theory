#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int fen[N];
void update(int i, int add) {
    while (i > 0 && i < N)
    {
        fen[i] += add;
        i += (i & (-i));
    }
}
 
int sum(int i) {
    int s = 0;
    while (i > 0)
    {
        s += fen[i];
        i = i - (i & (-i));
    }
    return s;
}
 
signed main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
 
    fio;
    //srand(time(NULL));
    int T = 1;
    // cin >> T;
 
    while (T--) {
        int n, q;
        cin >> n >> q;
 
        for0(i, n) {
            int num;
            cin >> num;
 
            update(num, 1);
        }
 
        while (q--) {
            int x;
            cin >> x;
 
            if (x > 0)
            {
                update(x, 1);
            }
            else {
                x = -1 * x;
                int low = 0, high = N;
                while (low < high)
                {
                    int mid = (low + high) / 2;
                    int val = sum(mid);
 
                    if (x <= val)
                        high = mid;
                    else
                        low = mid + 1;
                }
                update(low, -1);
            }
        }
 
        int ans = sum(N);
 
        if (!ans) prl(0);
        else {
            int low = 0, high = N;
            while (low < high)
            {
                int mid = (low + high) / 2;
                int val = sum(mid);
 
                if (ans <= val)
                    high = mid;
                else
                    low = mid + 1;
            }
            prl(low);
        }
    }
}

//COMPLEXITY IS N LOG N * LOG N (BS LOGN AND BIT LOG N)
