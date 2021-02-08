#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define d 256

void sc(string txt, string pat, int q){
    int i,j;
    int m= pat.length();
    int n= txt.length();
    int h= 1;
    int t=0;
    int p=0;
    
    for( i=0; i<m-1; i++){
        h = (h*d)%q;
    }
    
    for(i=0 ; i<m; i++){
        t= (t*d + txt[i])%q;
        p= (p*d + pat[i])%q;
    }
    
    for( i=0; i<=n-m; i++){
        
        if(t==p){
            for(j=0; j<m; j++){
                if(txt[i+j]!= pat[j]){
                    break;
                }
            }
            if(j== m){
            	cout<<"IS!"<<endl;
        	}
        }
        
        if(i<n-m){
            t= (d* (t-txt[i]*h) + txt[i+m])%q;
            if(t<0){
                t+=q;
                
            }
        }
        
    }
}

int main()
{
	string s,t;
    getline(cin, s);
   // cin.ignore();
    cin>>t;
    int q= 101;
    
    sc(s,t, q);
    return 0;
}