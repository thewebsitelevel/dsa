#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    string s;
	    cin>>s;
	    int level =-1;
	    int sum=0;
	    for(int i=0; i<s.length(); i++){
	        if(s[i] == '('){
	            level++;
	        }else if(s[i]== ')'){
	            level--;
	        }else if(level == k){
	            int t=0;
	            int j=i;
	            while(s[j] != ')' && s[j] != '('){
	                t= t*10 + (s[j]-'0');
	                j++;
	            }
	            i=j-1;
	            sum+= t;
	        }
	    }
	    cout<<sum<<endl;
	}
	
	return 0;
}