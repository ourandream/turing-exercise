#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
}TreeNode;

void preOrderTranverse(TreeNode *root){
    if(!root){
        return;
    }
    printf("%d\n",root->val);
    preOrderTranverse(root->left);
    preOrderTranverse(root->right);
}

void inOrderTranverse(TreeNode *root){
    if(!root){
        return;
    }
    inOrderTranverse(root->left);
    printf("%d\n",root->val);
    inOrderTranverse(root->right);
}

void postOrderTranverse(TreeNode *root){
    if(!root){
        return;
    }
    postOrderTranverse(root->left);
    postOrderTranverse(root->right);
    printf("%d\n",root->val);
}

TreeNode *buildTree(int *inorder,int inordersize,int *postorder,int postordersize){
    if(postordersize==0 || inordersize==0){
        return NULL;
    }
    TreeNode *root=(TreeNode *)malloc(sizeof(TreeNode));
    root->val=postorder[postordersize-1];
    int left;
    for(left=0;left<inordersize;++left){
        if(inorder[left]==root->val){
            break;
        }
    }
    int right=inordersize-left-1;

    root->left=buildTree(inorder,left,postorder,left);
    root->right=buildTree(inorder+left+1,right,postorder+left,right);

    return root;
}
int main(){
    int inorder[5]={9,3,15,20,7};
    int postorder[5]={9,15,7,20,3};
    TreeNode *root=buildTree(inorder,5,postorder,5);
    inOrderTranverse(root);
    
    return 0;
}