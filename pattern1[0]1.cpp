 int patternCount(string s) 
        { 
            
            int c=0;
            int j;
            int n= s.length();
            if(n<3){
                return c;
            }
            
            for(int i=0; i<n; i++){
                if(s[i]=='1'){
                    int z=0;
                    for( j=i+1; j<n; j++){
                        
                        if(s[j]!='0'){
                            break;
                        }
                        z++;
                    }
                    if(s[j]== '1' && z>0){
                        c++;
                    }
                    i=j-1;
                }
            }
            return c;
        } 