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
        if(jt> 0 && kt > 0 ) time = (jt < kt) ? jt : kt;
        else if(jt > 0 && kt == 0) time =jt;
        else if(kt > 0 && jt== 0) time=kt;
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
