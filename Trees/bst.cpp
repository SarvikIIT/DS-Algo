#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v):val(v),left(NULL),right(NULL){}
};


void InOrderTraversal(TreeNode* root){
    if(root==NULL)return;

    InOrderTraversal(root->left);
    cout<<root->val<<" ";
    InOrderTraversal(root->right);
}

TreeNode* InOrderPredecessor(TreeNode* root){

    //Largest Value in Left Subtree

    if(root==NULL)return NULL;

    if(root->left==NULL)return NULL;

    TreeNode* temp=root->left;

    while(temp->right!=NULL)temp=temp->right;

    return temp;
}


TreeNode* CreateNode(int val){
    TreeNode* node = new TreeNode(val);
    return node;
}

TreeNode* SearchNode(TreeNode* root,int val){
    if(root==NULL) return NULL;
    if(root->val < val)
        return SearchNode(root->right,val);
    else if(root->val > val)
        return SearchNode(root->left,val);
    else
        return root;
}

void InsertNode(TreeNode* &root, int val){
    if(root==NULL){
        root=CreateNode(val);
        return;
    }
    if(root->val > val) InsertNode(root->left,val);
    else InsertNode(root->right,val);
}

TreeNode* SearchParent(TreeNode* root, int val){
    if(root==NULL) return NULL;
    else if(root->val > val){
        if(root->left && root->left->val == val)
            return root;
        else
            return SearchParent(root->left,val);
    } else {
        if(root->right && root->right->val == val)
            return root;
        else
            return SearchParent(root->right,val);
    }
}
void DeleteNode(TreeNode* &root, int val) {
    if (root == NULL) return;

    // If root itself is the node to delete
    if (root->val == val) {
        // Case 1: Leaf node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            root = NULL;
            return;
        }

        // Case 2: One child
        if (root->left == NULL) {
            TreeNode* temp = root;
            root = root->right;
            delete temp;
            return;
        } 
        else if (root->right == NULL) {
            TreeNode* temp = root;
            root = root->left;
            delete temp;
            return;
        }

        // Case 3: Two children
        TreeNode* pred = InOrderPredecessor(root);
        root->val = pred->val;
        DeleteNode(root->left, pred->val);
        return;
    }

    // Otherwise, find the parent of the node to delete
    TreeNode* target = SearchParent(root, val);
    if (target == NULL) return;

    TreeNode* child = nullptr;
    if (target->left && target->left->val == val) child = target->left;
    else if (target->right && target->right->val == val) child = target->right;
    else return;

    // Case 1: Leaf node
    if (child->left == NULL && child->right == NULL) {
        delete child;
        if (target->left == child) target->left = NULL;
        else target->right = NULL;
        return;
    }

    // Case 2: One child
    if (child->left == NULL) {
        if (target->left == child) target->left = child->right;
        else target->right = child->right;
        delete child;
        return;
    } 
    else if (child->right == NULL) {
        if (target->left == child) target->left = child->left;
        else target->right = child->left;
        delete child;
        return;
    }

    // Case 3: Two children
    TreeNode* pred = InOrderPredecessor(child);
    child->val = pred->val;
    DeleteNode(child->left, pred->val);
}

int main() {
    TreeNode* root = NULL;

    // Insert nodes
    InsertNode(root, 50);
    InsertNode(root, 30);
    InsertNode(root, 70);
    InsertNode(root, 20);
    InsertNode(root, 40);
    InsertNode(root, 60);
    InsertNode(root, 80);

    cout << "Initial tree (inorder): ";
    InOrderTraversal(root);
    cout << "\n";

    // Delete leaf node (20)
    DeleteNode(root, 20);
    cout << "After deleting leaf (20): ";
    InOrderTraversal(root);
    cout << "\n";

    // Delete node with one child (30)
    DeleteNode(root, 30);
    cout << "After deleting node with one child (30): ";
    InOrderTraversal(root);
    cout << "\n";

    // Delete node with two children (50, the root)
    DeleteNode(root, 50);
    cout << "After deleting node with two children (50): ";
    InOrderTraversal(root);
    cout << "\n";

    return 0;
}
