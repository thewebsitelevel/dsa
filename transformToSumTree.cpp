
int sst(Node *root){
    if(!root){
        return 0;
    }
    
    int rst= sst(root->left);
    int lst= sst(root->right);
    int temp = root->data;
    root->data =  rst + lst;
    return temp+rst+lst;
}

void toSumTree(Node *root)
{
    if(!root){
        return;
    }
    
    int rst = sst(root->left);
    int lst = sst(root->right);
    
    root->data =  lst+ rst;
}
