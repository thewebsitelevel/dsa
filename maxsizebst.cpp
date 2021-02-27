#include<bits/stdc++.h>

struct info{
    bool isbst;
    int mini;
    int maxi;
    int ans;
    int sz;
};
    

struct info find(Node *root){
    struct info temp;
    if(!root){
        temp.isbst= true;
        temp.mini= INT_MAX;
        temp.maxi= INT_MIN;
        temp.sz =0;
        temp.ans= 0;
        return temp;
    }
    
    if(!root->left && !root->right){
        temp.isbst= true;
        temp.mini= root->data;
        temp.maxi= root->data;
        temp.sz =1;
        temp.ans= 1;
        return temp;
    }
    
    struct info ltemp = find(root->left);
    struct info rtemp = find(root->right);
    
    temp.sz = 1+rtemp.sz+ ltemp.sz;
    
    temp.isbst = (root->data > ltemp.maxi) && (root->data <rtemp.mini) && ltemp.isbst && rtemp.isbst;
    
    // cout<<temp.isbst<<"this"<<endl;
    temp.maxi= max(root->data, max(ltemp.maxi, rtemp.maxi));
    temp.mini= min(root->data, min(ltemp.mini, rtemp.mini));
    if(temp.isbst){
        temp.ans = temp.sz;
        
        return temp;
    }
    
    temp.ans= max(ltemp.ans,rtemp.ans);
    temp.isbst=false;
    

    return temp;
    
}

int largestBst(Node *root)
{
	
	struct info res = find(root);
	
	return res.ans;
	
	
}