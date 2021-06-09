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


int minEdgeBFS(vector <int> edges[], int u, int v, int n)
{
	vector<bool> visited(n, 0);

	vector<int> distance(n, 0);
	queue <int> Q;
	distance[u] = 0;

	Q.push(u);
	visited[u] = true;
	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int i=0; i<edges[x].size(); i++)
		{
			if (visited[edges[x][i]])
				continue;

			// update distance for i
			distance[edges[x][i]] = distance[x] + 1;
			Q.push(edges[x][i]);
			visited[edges[x][i]] = 1;
		}
	}
	return distance[v];
}

// function for addition of edge
void addEdge(vector <int> edges[], int u, int v)
{
edges[u].push_back(v);
edges[v].push_back(u);
}


void solve()
{
    int n,q;
    cin>>n>>q;
	vector <int> edges[n*n];
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
	    addEdge(edges, u, v);
    }

    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;
        int sum=0;
        for(int j=1;j<=n;j++){
            
            sum+=min(minEdgeBFS(edges,j,a,n),minEdgeBFS(edges,j,b,n));
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
    	// solve here
		
		solve();
    }
    return 0;
}

