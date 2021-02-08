#include <bits/stdc++.h>
#include <iostream>
using namespace std;

unordered_map<string, bool> mp;



bool solve2(string s1, string s2){
    if(s1.compare(s2)== 0){
        return true;
    }
    if(s1.length() <=0){
        return false;
    }
    
    int n=s1.length();
    
    bool flag= false;
    
    string temp = s1;
    temp.push_back(' ');
    temp.append(s2);
    
    if(mp.find(temp) != mp.end()){
        return mp[temp];
    }
    
    for(int i=1; i<=n-1; i++){
        if( (solve2( s1.substr(0, i), s2.substr(0, i) ) && solve2( s1.substr(i,n-i), s2.substr(i, n-i))) || 
           	(solve2(s1.substr(0, i), s2.substr(n-i, i)) && solve2(s1.substr(i, n-i), s2.substr(0, n-i))) ){
            flag = true;
            break;
        }
    }
    mp[temp]= flag;
    return flag;
}

bool solve(string s1, string s2){
    
    if(s1.length() != s2.length()){
        return false;
    }
    
    if(s1.length() ==0 && s2.length()==0){
        return true;
    }
    
    return solve2(s1, s2);
}

int main()
{
	string s1, s2;
    cin>>s1;
    cin.ignore();
    cin>>s2;
    
    cout<<solve(s1, s2);
	return 0;
}