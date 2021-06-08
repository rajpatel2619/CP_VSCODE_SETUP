#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int sumNum(int N, int A[]) {
    
    //this is default OUTPUT. You can change it.
    int result;
    
    //write your Logic here:
    int a[N];
    for(int i=0;i<N;i++) {
        a[i]=A[i];
    }
    sort(A,A+N);
    for(int i=0;i<N;i++){
        cout<<a[i]<<" "<<A[i]<<endl;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(a[i]==A[j]){
                if(j==0) result=A[j+1];
                else if(j==N-1) result=A[j-1];
                else{
                    result= A[j-1] + A[j+1];
                }
            }
        }
    }
    return result;
}
int main(void) {
    //INPUT [uncomment & modify only if required]
    int N,i;
    cin>>N;
    int A[N];
    for(i=0;i<N;i++){
        int temp;
        cin>>temp;
        A[i]=temp;
    }
    
    //OUTPUT [uncomment & modify only if required]
    // cout<<sumNum(N,A);
    sumNum(N,A);
    return 0;
}