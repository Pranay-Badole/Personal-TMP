// Checked working on leetcode problem 
// Passed successfully


#include "bits/stdc++.h"
using namespace std;

class SGT{
public:
    
    vector<int> t;

    SGT(int n) {
        t.assign(4*n + 5, 0);
    }

    int query(int l, int r, int ql, int qr, int k) {
        if(ql > r || qr < l) return 0;

        if(ql <= l && r <= qr) return t[k];
        
        int ans = 0;
        int mid = l + (r - l)/2;
        
        ans += query(l, mid, ql, qr, 2*k+1);
        ans += query(mid+1, r, ql, qr, 2*k+2);
        
        return ans;
    }

    void update(int l, int r, int qidx, int val, int k) {
        if((l == qidx) && (l == r)) {t[k] = val; return;}
        
        int mid = l + (r - l)/2;
        
        if(qidx <= mid) update(l, mid, qidx, val, 2*k + 1);
        else update(mid+1, r, qidx, val, 2*k + 2);

        t[k] = t[2*k + 1] + t[2*k + 2];
    }
};

void solve(){

    vector<int> v = {2,5,1,4,5,1};
    int n = v.size();

    SGT sgt(n);

    for(int i = 0; i < n; i++) {
        sgt.update(0, n-1, i, v[i], 0);
    }

    for(int i = 0; i < n; i++) {
        for(int l = 0; l+i < n; l++) {
            int r = l + i;
            cout << l << ' ' << r << " ==> ";
            cout << sgt.query(0, n-1, l, r, 0) << endl;
        }
        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        init();
    #endif  
    
    cerr << setprecision(9) << fixed;
    cout << setprecision(9) << fixed;

    int t = 1;
    // cin >> t;

    while(t--) {
        solve();
        // cout << endl;
    } 
    return 0;
}   