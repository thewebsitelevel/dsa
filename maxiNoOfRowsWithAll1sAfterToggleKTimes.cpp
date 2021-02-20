#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
	int row, col;
    cin>>row>>col;
    int k;
    cin>>k;
    int matrix[row][col];
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin>>matrix[i][j];
        }
    }
    
    unordered_map<string, int> f;
    
    for(int i=0; i<row; i++){
        string tempstring;
        for(int j=0; j<col; j++){
            if(matrix[i][j]== 0){
                tempstring.push_back('0');
            }else{
                tempstring.push_back('1');
            }
        }
        if(f.count(tempstring)>0){
            f[tempstring]++;
        }else{
            f[tempstring]=1;
        }
        tempstring="";
    }
    int ans=0;
    
    for(auto it= f.begin(); it!= f.end(); it++ ){
        int zeros= 0;
        string currstring = it->first;
        
        for(int i=0; i<currstring.length(); i++){
            if(currstring[i]== '0'){
                zeros++;
            }
        }
        if( (k-zeros)%2 == 0 && k>=0 ){
            ans = max(ans, it->second);
        }
        
    }
    cout<<ans<<endl;
}