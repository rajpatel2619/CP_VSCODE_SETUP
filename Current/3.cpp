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

    int solution[n];
    int mx = INT_MAX;
    solution[0] = 0;
    for(int i=1;i<n;i++){
        if(a[i]!=0) solution[i]=0;
        else solution[i] = mx;
    }

    // traversing for train 1
    int right = -1;
    for(int i=0;i<n;i++){
        if(a[i]==1) 
            right = i;

        if( right != -1)
            if(a[i]==0)
                solution[i] = min(solution[i],i-right);
        
    }
    


    // traversing for train 2
    int left = -1;
    for(int i=n-1;i>=0;i--){
        if(a[i]==2) 
            left = i;

        if( left != -1)
            if(a[i]==0)
                solution[i] = min(solution[i],left-i);
        
    }
       
    for(int i=0;i<m;i++){
        int man = b[i] -1 ;
        if(solution[man]!=mx) cout<<solution[man]<<" ";
        else cout<<-1<<" ";     
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
