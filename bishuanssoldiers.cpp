#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int powers[n];
    for(int i=0; i<n; i++){
        cin>>powers[i];
    }
    int rounds;
    cin>>rounds;
    int roundpow[rounds];
    for(int i=0; i<rounds; i++){
        cin>>roundpow[i];
        int oppopow=0;
        int oppo=0;
        for(int j=0; j<n; j++){
            if(roundpow[i]>= powers[j] ){
                oppopow+=powers[j];
                oppo++;
            }
        }
        cout<<oppo<<" "<<oppopow<<endl;;
    }
    
    
}