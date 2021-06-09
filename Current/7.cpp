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


void addEdge(vector<int> v[],
             int x,
             int y)
{
    v[x].push_back(y);
    v[y].push_back(x);
}
 
// A function to print the path between
// the given pair of nodes.
void printPath(vector<int> stack)
{
    int i;
    for (i = 0; i < (int)stack.size() - 1;
         i++) {
        cout << stack[i] << " -> ";
    }
    cout << stack[i];
}
 
// An utility function to do
// DFS of graph recursively
// from a given vertex x.
void DFS(vector<int> v[],
         bool vis[],
         int x,
         int y,
         vector<int> stack)
{
    stack.push_back(x);
    if (x == y) {
 
        // print the path and return on
        // reaching the destination node
        printPath(stack);
        return;
    }
    vis[x] = true;
 
    // if backtracking is taking place
    if (!v[x].empty()) {
        for (int j = 0; j < v[x].size(); j++) {
            // if the node is not visited
            if (vis[v[x][j]] == false)
                DFS(v, vis, v[x][j], y, stack);
        }
    }
 
    stack.pop_back();
}
 
// A utility function to initialise
// visited for the node and call
// DFS function for a given vertex x.
void DFSCall(int x,
             int y,
             vector<int> v[],
             int n,
             vector<int> stack)
{
    // visited array
    bool vis[n + 1];
 
    memset(vis, false, sizeof(vis));
 
    // DFS function call
    DFS(v, vis, x, y, stack);
}

void solve()
{
    int n,q;
    cin>>n>>q;

    vector<int> v[n], stack;
	// vector <int> edges[n*n];
    for(int i=1;i<n;i++){
        int u1,v1;
        cin>>u1>>v1;
	    addEdge(v, u1, v1);
    }

    for(int i=0;i<q;i++){
        
        int a,b;
        cin>>a>>b;
        int sum=0;
        for(int j=1;j<=n;j++){
            
            sum+=min(DFSCall(j,a,v,n,stack),DFSCall(j,b,v,n,stack));
        }
        cout<<sum<<"\n";
    }
    // minEdgeBFS(edges, u, v, n);
	
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}

