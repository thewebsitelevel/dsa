

vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    int n= string_list.size();
    
    vector<vector<string>> res;
    int m=0;
    
    unordered_map<string, int> f;
    
    for(int i=0; i<n; i++){
        string curr=string_list[i];
        sort(curr.begin(), curr.end());
        
        if(f.count(curr) >0 ){
            res[f[curr]].push_back(string_list[i]);
            
        }else{
            vector<string> temp;
            temp.push_back(string_list[i]);
            res.push_back(temp);
            f[curr]=m;
            m++;
        }
    }
    //reverse(res.begin(), res.end());
    return res;
    
}