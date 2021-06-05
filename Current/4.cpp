#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;typedef long double ld;typedef pair<int,int> pii;
#define F first
#define S second
#define PB push_back
#define MP make_pair
const ll mod = 1e9+7, N = 2e6+7, M = 2e6+7, INF = INT_MAX/10;
ll powe(ll x, ll y){ x = x%mod, y=y%(mod-1);ll ans = 1;while(y>0){if (y&1){ans = (1ll * x * ans)%mod;}y>>=1;x = (1ll * x * x)%mod;}return ans;}


int fastPow(long long a, long long b){
    int ans=1,n=1000000007;
    while(b>0){
        if((b&1)!=0){
            ans = (ans*(a%n))%n;
        }
            a=((a%n)*(a%n))%n;
            b = b>>1; 
    }
    return ans;

}

void solve(){
	int n,m;
    cin>>n>>m;
    int res;
    res = fastPow(2,n);
    res = res - 1;
    res = fastPow(res,m);
    cout<<res<<endl;

}




signed main(){
    fast;
    int t = 1;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
