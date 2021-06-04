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




void solve(){
    int n , m;
    cin>>n>>m;
    int a[n];
    int b[m];
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];

    for(int i=0;i<m;i++){
        if(b[i]==1){
            cout<<0<<" ";
            continue;
        }else{

        int ts = b[i]-1;
        int jt=0,kt=0;
        for(int j=ts,k=ts;j>=0||k<n;j--,k++){
            if(j>=0 && a[j] == 1){
                jt = ts - j ; 
                break;
            }
            else if(k<n && a[k] == 2){
                 kt = k-ts;
                 break;
            }
        }
        int time=-1;
        if(jt> 0 && kt > 0 ) time = min(jt,kt);
        else if(jt > 0 && kt == 0) time =jt;
        else if(kt > 0 && jt== 0) time=kt;
        cout<<time<<" ";
        }
    }
    cout<<"\n";

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
