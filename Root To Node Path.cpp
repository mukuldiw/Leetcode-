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
void rootNodePathHelper(node* root,vector<int> v,vector<int> &ans,int k){
	if(!root)
	return ;
	v.push_back(root->data);
	if(root->data == k){
		ans = v;
		return ;
	}
	rootNodePathHelper(root->left,v,ans,k);
	rootNodePathHelper(root->right,v,ans,k);
	return;
}
void rootNodePath(node* root, int k){
	if(!root)
	return;
	vector<int> v,ans;
	rootNodePathHelper(root,v,ans,k);
	for(int i=0;i<ans.size();i++)
	cout<<ans[i]<<" ";
}
int main(){
	node* root = takeInputLevelWise();
//	print(root);
	rootNodePath(root,7);
}
	
	
	
