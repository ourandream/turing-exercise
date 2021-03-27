#include<iostream>
#include<queue>

using namespace std;
class heap{
private:
    typedef struct TreeNode{
        int item;
        struct TreeNode* left;
        struct TreeNode* right;
    }TreeNode;
    TreeNode *root;
    int heapSize;
public:
    heap();
    heap(const int *arr,int len);
    int size(){return heapSize;}
    void showItem();
};

heap::heap(){
    root=nullptr;
    heapSize=0;
}

heap::heap(const int *arr,int len){
    if(!len){
        heap();
        return;
    }
    heapSize=len;
    queue<TreeNode*> TreeQ;
    root=new TreeNode;
    root->item=arr[0];
    TreeQ.push(root);

    int t=1;
    while(t<len){
        TreeNode* temp=TreeQ.front();
        temp->left=new TreeNode;
        temp->left->item=arr[t++];
        temp->left->left=temp->left->right=nullptr;
        TreeQ.push(temp->left);
        if(t>=len){
            break;
        }
        temp->right=new TreeNode;
        temp->right->item=arr[t++];
        temp->right->left=temp->right->right=nullptr;
        if(t>=len){
            break;
        }
        TreeQ.pop();
    }
}

void heap::showItem(){
    if(heapSize==0){
        return;
    }
    queue<TreeNode*> t;
    if(root->left!=nullptr){
        t.push(root->left);
    }
    if(root->right!=nullptr){
        t.push(root->right);
    }
    cout.setf(ios::left);
    cout.width(5);
    cout<<root->item;

    while(t.size()!=0){
        TreeNode *tN=t.front();
        cout.width(5);
        cout<<tN->item;
        if(tN->left!=nullptr){
            t.push(tN->left);
        }
        if(tN->right!=nullptr){
            t.push(tN->right);
        }
        t.pop();
    }
}

int main(){
    int a[5]={1,2,3,4,5};
    heap b(a,5);
    cout<<b.size()<<endl;
    b.showItem();
    
    return 0;
}