	#include "bits/stdc++.h"
	using namespace std;	
	#define int              long long 

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
	#define mkp 				  make_pair
	#define rep(i,a,b)        for(int i=a;i<b;i++)
	#define rrep(i,a,b)       for(int i=a;i>=b;i--)
	#define REP(i,a,b)        for(int i=a;i<=b;i++)
	#define mem1(a)           memset(a,-1,sizeof(a))
	#define mem0(a)           memset(a,0,sizeof(a))
	#define ppc               __builtin_popcount
	#define ppcll             __builtin_popcountll
	#define acc				  accumulate
	#define endl			  '\n'
	#define length(a)		  sizeof(a)/sizeof(a[0])
	#define auv(v)		      for(auto x:v) cout<<x<<' '; 
	#define aump(mp)	      for(auto x:mp) cout<<x.fr<<' '<<x.sc<<endl; 
	

const int N=1e6+1;
const int M=1e9+7;

int power(int x,int y,int m){
	if(y==0)return 1;
	int temp=power(x,y/2,m)%m;
		temp= (temp*temp)%m;
	if(y%2){
		temp=x*temp%m;
	}
	return temp;
}	

int fact[N];
void factorial(){
	fact[0]=1;	
	rep(i,1,N){
	fact[i]=(fact[i-1]*i)%M;
	}
}

int inverse(int n){
	return power(n,M-2,M);
}
int alpha[26];

void solve(){
	string s;
	cin>>s;
	factorial();
	rep(i,0,sz(s)){
	alpha[s[i]-'a']++;
	}
	int ans=fact[sz(s)];

	rep(i,0,26){
		if(alpha[i]==0){continue;}
		ans=(ans*inverse(fact[alpha[i]]))%M;
	}
		cout<<ans<<' ';

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

		int t=1;
		// cin>>t;
		while(t--) solve();
		return 0;
	}