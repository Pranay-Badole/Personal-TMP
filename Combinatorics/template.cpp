
        #include "bits/stdc++.h"
        using namespace std;    

        #define ll                            long long
        #define int                           FO
        #define pb                            push_back
        #define ppb                           pop_back
        #define pf                            push_front
        #define ppf                           pop_front
        #define all(x)                        (x).begin(),(x).end()
        #define uniq(v)                       (v).erase(unique(all(v)),(v).end())
        #define sz(x)                         (ll)((x).size())
        #define fr                            first
        #define sc                            second
        #define pii                           pair<ll,ll>
        #define mkp                           make_pair
        #define rep(i,a,b)                    for(ll i=a;i<b;i++)
        #define rrep(i,a,b)                   for(ll i=a;i>=b;i--)
        #define REP(i,a,b)                    for(ll i=a;i<=b;i++)
        #define mem1(a)                       memset(a,-1,sizeof(a))
        #define mem0(a)                       memset(a,0,sizeof(a))
        #define ppc                           __builtin_popcount
        #define ppcll                         __builtin_popcountll
        #define acc                              accumulate
        #define endl                          '\n'
        #define length(a)                     sizeof(a)/sizeof(a[0])
        #define auv(v)                        for(auto &x:v) cout<<x<<' '; cout<<endl;
        #define auvv(v)                       for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
        #define aump(mp)                      for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl;  
        #define vi                            vector<ll>
        #define vvi                           vector<vector<ll>>
        #define vc                            vector<char>
        #define vvc                           vector<vector<char>>
        #define two(x)                        cout << x.fr << ' ' << x.sc << ' ';
        #define EPS 1e-9

        struct custom_hash {
            static uint64_t splitmix64(uint64_t x) {
                // http://xorshift.di.unimi.it/splitmix64.c
                x += 0x9e3779b97f4a7c15;
                x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
                x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
                return x ^ (x >> 31);
            }
            size_t operator()(uint64_t x) const {
                static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
                return splitmix64(x + FIXED_RANDOM);
            }
        };

        #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            std::cerr << name << " : " << arg1 << endl;
        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ',');std::cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }


        const ll M = 1e9 + 7;
        const ll MM = 998244353;
        const ll N = 2e5;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        ll fact[N];
        ll invfact[N];

        ll power(ll a, ll b) {
            if(b == 0) return 1;
            ll t = power(a, b/2);
            t = (t * t) % M;
            if(b % 2){
                t = (t * a) % M;
            }
            return t;
        }

        void factorial() {
            fact[0] = 1;
            rep(i, 1, N) {
                fact[i] = (fact[i-1] * i) % M;
            }
            invfact[N-1] = power(fact[N-1], M-2);
            
            rrep(i, N-2, 0) {
                invfact[i] = (invfact[i+1] * (i+1)) % M;
            }
        }

        ll ncr(ll n, ll r) {
            if(r > n){ return 0;}
            
            ll ans = (fact[n] * invfact[r]) % M;
            ans = (ans * invfact[n - r]) % M;
            return ans;
        }



        void solve(ll tc = 0) {  
            factorial();

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
            
            cerr << setprecision(15) << fixed;
            cout << setprecision(15) << fixed;
            
            ll t = 1;
            // cin >> t;

            while(t--) {
                solve();
                cout << endl;
            } 
            return 0;
        }   