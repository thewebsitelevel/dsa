bool areIsomorphic(string str1, string str2)
    {
        int m1[256]={0};
        int m2[256]={0};
        
        if(str1.length() != str2.length()){
            return false;
        }
        
        for(int i=0; i<str1.length(); i++){
            if(!m1[str1[i]] && !m2[str2[i]]){
                m1[str1[i]]= str2[i];
                m2[str2[i]]= str1[i];
            }else if(m1[str1[i]] != str2[i]){
                    return false;
            }
            
        }
        return true;
    }