
unordered_map<string, int> f;


int solve(string A, vector<string> &B){
    
    if(f.count(A) >0){
        return 1;
    }
    
    for(int i=0; i<A.length(); i++){
        if(f.count(A.substr(0,i)) >0 && solve(A.substr(i), B) ){
            return 1;
        }
    }
    return 0;
}

int wordBreak(string A, vector<string> &B) {
    
    if(A.length() == 0){
        return false;
    }
    
    for(int i=0; i<B.size(); i++){
        f[B[i]]= 1;
    }
    
    if(f.count(A) >0){
        return 1;
    }
    
    return solve(A, B);
    
    
    
    
    return 0;
}