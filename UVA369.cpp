#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <stack>
#include <stdio.h>

using namespace std;

vector<int> nn, mm;
int n, m;

int gcd(int x, int y) {
    if(y == 0)
        return x;
    return gcd(y, x%y);
}

int main(void) {
//    freopen("input", "r", stdin);
//    freopen("output", "w", stdout);
    cin >> n >> m;
    while(n != 0) {
        nn = vector<int>(105);
        mm = vector<int>(105);
        int nx = n, mx = m;
        for(int i = 0, k = nx; k != nx-mx; ++i, --k)
            nn[i] = n--;
        for(int i = 0; i < mx; ++i)
            mm[i] = m--;
        
        for(int i = 0; i < nx; ++i) {
            for(int j = 0; j < mx; ++j) {
                int __gcd = gcd(max(nn[i], mm[j]), min(nn[i], mm[j]));
                nn[i] /= __gcd;
                mm[j] /= __gcd;
            }
        }
        
        unsigned long ns = 1, ms = 1;
        
        for(int i = 0; nn[i]; ++i)
            ns *= nn[i];
        
        for(int j = 0; mm[j]; ++j)
            ms *= mm[j];
        
        printf("%d things taken %d at a time is %lu exactly.\n", nx, mx, ns / ms);
        cin >> n >> m;
    }
    
}

