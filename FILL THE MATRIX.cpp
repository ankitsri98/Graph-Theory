#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const int MAXQ = 1000000;

int father[MAXN], diff[MAXN];

int find(int x)
{
    if (x == father[x])//reaching root
    {
        return x;
    }
    //In the following code, tt is xx's original father, and after
    //find(t), diff[t] becomes parity(root) xor parity(t).
    //Now the old diff[x] is equal to parity(x) xor parity(t),
    //and we want the new diff[x] become parity(root) xor parity(x).
    // It’s easy to see diff[x](new) should become diff[x](old) xor diff[t].
    int t = father[x];
    father[x] = find(father[x]);
    diff[x] ^= diff[t];
    return father[x];
}

int main()
{
    int tests;
    int sum_n = 0, sum_q = 0;
    for (assert(scanf("%d", &tests) == 1 && 1 <= tests && tests <= 1000000); tests --; ) {
        int n, q;
        scanf("%d%d", &n, &q);

        sum_n += n;
        sum_q += q;
        bool valid = true;
        for (int i = 0; i < n; ++ i) {
            father[i] = i;
            diff[i] = 0;
        }
        for (int i = 0; i < q; ++ i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            -- a; -- b;
//checking as - inserting an edge is possible or not
            int fa = find(a), fb = find(b);
            if (fa == fb)
            {
                //if they are in the same set, we use
                //diff to check if this edge doesn’t make an odd-weighted cycle
                //The indicator for an odd-weighted cycle is an edge (x,y) with
                // weight w such that parity(u) xor parity(v) xor w=1...next line
                //aur normally bhi dekhe toh to edge add karna hai toh
                //w is the weight of inserted edge so parity(x) xor parity(y)=w;
                if ((c^diff[a] ^ diff[b])==1)//0^1^0=>0^1=0 ^0=1
                {
                    valid = false;
                }
            }
            else
            {
                //For an edge (u,v) with weight w,
                //if u and v are in different sets, we just merge them
                father[fa] = fb;//now root of a is changes to root of b
                //We also have parity(x) xor parity(root_x)=diff[x] and
                //parity(y) xor parity(root_y)=diff[y]. Thus diff[root_x],
                //which should be equal to parity(root_x) xor parity(root_y),
                //can be computed by w xor diff[x] xor diff[y].
                diff[fa] = diff[a] ^ diff[b] ^ c;
            }
        }
        puts(valid ? "yes" : "no");
    }
    return 0;
}
