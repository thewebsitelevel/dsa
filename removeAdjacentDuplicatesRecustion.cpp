 string removeConsecutiveCharacter(string s)
    {
        int n= s.length();
        
        if(n==0){
            return "";
        }
        
        char ch=s[0];
        
        string ans =removeConsecutiveCharacter(s.substr(1));
        
        if(ch == ans[0]) return ans;
      
        return ch+ans;
    }