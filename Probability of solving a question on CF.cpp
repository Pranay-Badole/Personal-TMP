#include "bits/stdc++.h"
	using namespace std;	
 
	#define int               long long 
	#define pb                push_back
	#define ppb               pop_back
	#define pf                push_front
	#define ppf               pop_front
	#define all(x)            (x).begin(),(x).end()
	#define uniq(v)           (v).erase(unique(all(v)),(v).end())
	#define sz(x)             (int)((x).size())
	#define fr                first
	#define sc                second
	#define pii               pair<int,int>
	#define mkp				  			make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)        for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  			accumulate
	#define endl			  			'\n'
	#define length(a)		  		sizeof(a)/sizeof(a[0])
	#define auv(v)		    	  for(auto &x:v) cout<<x<<' '; cout<<endl;
	#define auvv(v)			  		for(auto &x:v){for(auto &y:x)cout<<y<<' ';cout<<endl;}
	#define aump(mp)	    	  for(auto &x:mp) cout<<x.fr<<' '<<x.sc<<endl;  
	#define vi 				  			vector<int>
	#define vvi 			  			vector<vector<int>>
	#define vc 				  			vector<char>
	#define vvc 			  			vector<vector<char>>
	#define EPS 1e-6

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

	const int M9 = 998244353;
	const int M7 = 1e9 + 7;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
// https://codeforces.com/blog/entry/62865
	
	const ll user_current_rating = 1325;
	const ll problem_rating = 1500;

	void solve(int tc = 0) {

		double dif = (user_current_rating - problem_rating);
		double p = (dif * 1.0) / 400;

		double dem = 1 + pow(10, p);
		
		double ans = 1.0 / dem;
		
		cout << ans;
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
 	
		cout << setprecision(15) << fixed;

		int t = 1;
		// cin >> t;

		while(t--) {
			solve();
			cout << endl;
		} 
		return 0;
	}