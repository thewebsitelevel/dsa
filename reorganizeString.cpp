#include<bits/stdc++.h>

typedef pair<char, int> pd;


class comp{
    public:
        bool operator()(const pd &a, const pd &b){
            return a.second<b.second;
        }
};


class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> f;
        priority_queue<pd, vector<pd>, comp> pq;
        
        for(int i=0; i<s.length(); i++){
            f[s[i]]++;
        }
        
        for(auto it=f.begin(); it!= f.end(); it++){
            pd temp;
            temp.first = it->first;
            temp.second= it->second;
            pq.push(temp);
        }
        string res;
        while(pq.size()>1){
            pd tf= pq.top();
            pq.pop();
            pd ts = pq.top();
            pq.pop();
            res.push_back(tf.first);
            res.push_back(ts.first);
            tf.second--;
            ts.second--;
            if(tf.second>0){
                pq.push(tf);
            }
            if(ts.second>0){
                pq.push(ts);
            }
        }
        if(!pq.empty() ){
            pd r= pq.top();
            if(r.second>1){
                return "";
            }
            res.push_back(r.first);
        }
        
        return res;
    }
};