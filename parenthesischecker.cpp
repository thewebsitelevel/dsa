#include<bits/stdc++.h>


bool ispar(string s)
{
    stack<char> p;
    
    for(int i=0; i<s.length(); i++){
        if(s[i]== '{'){
            p.push('{');
        }else if(s[i]== '('){
            p.push('(');
        }else if(s[i]== '['){
            p.push('[');
        }else if(s[i]== '}'){
            if(p.size() != 0 && p.top() == '{'){
                p.pop();
            }else{
                return false;
            }
        }else if(s[i]== ')'){
            if(p.size() !=0 && p.top() == '('){
                p.pop();
            }else{
                return false;
            }
        }else if(s[i]== ']'){
            if(p.size() !=0 && p.top() == '['){
                p.pop();
            }else{
                return false;
            }
        }
        
    }
    if(p.size() != 0){
        return false;
    }else{
        return true;
    }
}
