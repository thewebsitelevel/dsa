string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n=strs.size();
        if(n==0)
            return ans;
        int l=strs[0].length();
        for(string s:strs)
            if(l>s.length())
                l=s.length();
        int index=0;
        for(char c:strs[0])
        {
            for(int i=1;i<n;i++)
            {
                if(strs[i][index]!=c||index>l)
                    return ans;
            }
            ans+=c;
            index++;
        }
        return ans;
    }