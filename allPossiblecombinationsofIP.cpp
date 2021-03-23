  bool isvalid(string test){
        if(test.length()> 3){
            return false;
        }
        if(test.length()>1 && test[0] =='0'){
            return false;
        }
       if(test.length()>0){
            int val= stoi(test);
        
            return val>=0 && val<=255;
       }
        return false;
    }
    
    vector<string> restoreIpAddresses(string s) {
        
        vector<string> res;
        
        for(int i=1; i<=3; i++){
            string first= s.substr(0,i);
            if(isvalid(first)){
                for(int j=1; j<=3 && i+j<s.length(); j++){
                    string second = s.substr(i, j);
                    if(isvalid(second)){
                        for(int k=1; k<=3 &&  i+j+k<s.length(); k++){
                            string third= s.substr(i+j, k);
                            string fourth = s.substr(i+j+k);

                            if(isvalid(third ) && isvalid(fourth)){
                                res.emplace_back(first+"."+ second+"."+third+"."+fourth);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }