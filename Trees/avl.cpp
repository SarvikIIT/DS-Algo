	#include<bits/stdc++.h>
	using namespace std;

	struct TreeNode{
		int val;
		TreeNode* left;
		TreeNode* right;

		TreeNode(int v):val(v),left(NULL),right(NULL){}
	};

	TreeNode* SearchNode(TreeNode* root,int val){
		if(root==NULL)return NULL;
		else if(root->val==val)return root;
		else if(root->val>val)return SearchNode(root->left,val);
		else return SearchNode(root->right,val);
	}

	int FindHeight(TreeNode* root,int h){
		if(root==NULL){
			if(maxh<h)maxh=h;
			return maxh;
		}
		FindHeight(root->left,h+1);
		FindHeight(root->right,h+1);
		return maxh;
	}

	int FindBalanceFactor(TreeNode* root){
		return FindHeight(root->left,0)-FindHeight(root->right,0);
	}

	void FindCriticalNode(TreeNode*root){

		if(root==NULL)return;

		if(FindBalanceFactor(root)>1||FindBalanceFactor(root)<-1){
			int h=FindHeight(root);

			if(CriticalNode.second<h)CriticalNode={root,h};
		}

		FindCriticalNode(root->left);

		FindCriticalNode(root->right);
	}


	void InsertNode(TreeNode* &root,val){
		if(root==NULL){
			root=CreateNode(val);
		}
		if(root->val>val)InsertNode(root->left,val);
		else InsertNode(root->right,val);
	}
	TreeNode* FindParent(TreeNode* root, TreeNode* target) {
		if (root == NULL || root == target) {
			return NULL;
		}
		if ((root->left != NULL && root->left == target) || (root->right != NULL && root->right == target)) {
			return root;
		}
		if (target->val < root->val) {
			return FindParent(root->left, target);
		} else {
			return FindParent(root->right, target);
		}
	}
	void LLRotation(TreeNode* &root) {
		TreeNode* leftChild = root->left;
		root->left = leftChild->right;
		leftChild->right = root;
		root = leftChild;
	}

	void RRRotation(TreeNode* &root){
		TreeNode* rightChild = root->right;
		root->right= rightChild->left;
		rightChild->left=root;
		root=rightChild;
	}
	void LRRotation(TreeNode* &root){
		TreeNode* leftChild = root->left;
		TreeNode* nodeOfChange = leftChild->right;

		leftChild->right = nodeOfChange->left;

		root->left = nodeOfChange->right;

		nodeOfChange->left = leftChild;
		nodeOfChange->right = root;

   
		root = nodeOfChange;
	}
	void RLRotation(TreeNode* &root) {
		TreeNode* rightChild = root->right;
		TreeNode* nodeOfChange = rightChild->left;

		rightChild->left = nodeOfChange->right;
		nodeOfChange->right = rightChild;

		root->right = nodeOfChange->left;
		nodeOfChange->left = root;

		root = nodeOfChange;
	}

	void IndetifyndFixTree(TreeNode* &root){
		TreeNode* CriticalNode = FindCriticalNode(root);
		if(FindHeight(CriticalNode->left)>FindHeight(CriticalNode->right)){
		//LL or LR Rotation


		}

		if(FindHeight(CriticalNode->left)<FindHeight(CriticalNode->right)){
		//RR or RL Rotation


		}
	}


	int main(){

		int maxh=0;
		pair<TreeNode*,int>CriticalNode={NULL,INT_MAX};
		return 0;
	}