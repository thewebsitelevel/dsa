#include <bits/stdc++.h>
#include <iostream>
using namespace std;


int editDistance(string s, string t)
		{       int l=s.size();
		        int m= t.size();
		        int table[l+1][m+1];
                for(int i=0; i<l+1; i++){
                    for(int j=0 ; j<m+1; j++){
                        if(i==0){
                            table[i][j]= j;
                        }
                        else if(j==0){
                            table[i][j]=i;
                        }
                    }
                }
                
                for(int i=1; i<l+1; i++){
                    for(int j=1; j<m+1; j++){
                        if(s[i-1]== t[j-1]){
                            table[i][j]= table[i-1][j-1];
                        }else{
                            table[i][j] = 1+ min(table[i-1][j], min(table[i][j-1], table[i-1][j-1]));
                        }
                    }
                }
                return table[l][m];
		}


int main()
{
	string s;
    string t;
    cin>>s;
    cin.ignore();
    cin>>t;
    cout<<editd(s,t, s.length(), t.length());
	return 0;
}