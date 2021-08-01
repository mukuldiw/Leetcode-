#include <bits/stdc++.h> 
#include<queue>
#include<vector>
using namespace std;

class node{
	public:
	int data;
	node* left;
	node* right;
		node(int data){
			this->data=data;
			left=NULL;
			right=NULL;
		}
		~node(){
			delete left;
			delete right;
		}
};

node* takeInputLevelWise() {
	int rootData;
	cout << "Enter root data" << endl;
	cin >> rootData;
	if (rootData == -1) {
		return NULL;
	}

	node* root = new node(rootData);

	queue<node*> pendingNodes;
	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		node* front = pendingNodes.front();
		pendingNodes.pop();
		cout << "Enter left child of " << front->data << endl;
		int leftChildData;
		cin >> leftChildData;
		if (leftChildData != -1) {
			node* child = new node(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}
		cout << "Enter right child of " << front->data << endl;
		int rightChildData;
		cin >> rightChildData;
		if (rightChildData != -1) {
			node* child = new node(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}
	return root;
}

void print(node* root){
	if(root == NULL)
	return;
	cout<<root->data;
	if(root->left)
	cout<<"L"<<root->left->data;
	if(root->right)
	cout<<"R"<<root->right->data;
	cout<<endl;
	print(root->left);
	print(root->right);
}
int height(node* root){
	if(!root)return 0;
	return 1 + max(height(root->left),height(root->right));
}
void helper(node* root,int val,int depth,int h,int max_h){
	if(!root)return;
	h++;
	helper(root->left,val,depth,h,max_h);
	if(h == depth-1){
		node* r = new node(val);
		node* l = new node(val);
		l->left = root->left;
		r->right = root->right;
		root->left = l;
		root->right = r;
		return;
	}
//	cout<<root->data<<" -> "<<h<<endl;
	helper(root->right,val,depth,h,max_h);
}
node* addOneRow(node* root,int val,int depth){
	int h = 0;
	int max_h = height(root);
	
	if(depth == 1){
		node* r = new node(val);
		r->left = root;
		return r;
	}
	helper(root,val,depth,h,max_h);
	return root;
}
int main(){
	node* root = takeInputLevelWise();
	int val = 1, depth = 2;
	node* r = addOneRow(root,val,depth);
	print(r);
}
