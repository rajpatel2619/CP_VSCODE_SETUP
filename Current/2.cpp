#include <bits/stdc++.h>
using namespace std;



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
            int time = -1;
            int ts = b[i] - 1;
            int res=INT_MAX;
            for(int j=0;j<n;j++){
                if(j<=ts && a[j]==1 ){
                    res = ts-j;
                }else if(j>ts && a[j] == 2){
                    if((j-ts)>res) break;
                    else res = (j-ts);
                }
            }
            if(res<INT_MAX) time =res;
            cout<<time<<" ";
        }
    }
    cout<<"\n";

}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int t ;
    cin >> t;
    while(t--){
    	solve();
    }
    return 0;
}
