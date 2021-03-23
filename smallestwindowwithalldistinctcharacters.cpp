
string findSubString(string str)
{
    int n=str.length();
    unordered_map<char, int> f;
    set<char> s;
    
    for(int i=0; i<n; i++){
       s.insert(str[i]); 
    }
    
    int siz = s.size();
    int i=0; 
    int j=1;
    int count=0;
    
    f[str[i]]++;
    count++;
    
    int ans=INT_MAX;
    
    while(i<=j && j<n){
        if(count <siz){
            if(f[str[j]]==0) count++;
            f[str[j]]++;
            j++;
        }else if(count == siz){
            ans= min(ans, j-i);
            
            if(f[str[i]]==1) count--;
            f[str[i]]--;
            i++;
        }
        
        
    }
    while(count==siz){
        ans= min(ans, j-i);
        if(f[str[i]]==1) count--;
        f[str[i]]--;
        i++;
    }
    string res;
    for(int i=0; i<ans; i++){
        res+='a';
    }
    return res;
    
}