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
node* construct(){
	int data;
	cin>>data;
	if(data == -1)
	return NULL;
	node* root = new node(data);
	node* leftChild= construct();
	node* rightChild = construct();
	root->left = leftChild;
	root->right = rightChild;
	return root;
}
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
void insert(node* root,int d){
	if(!root)return;
	if(!root->left && !root->right){
		node* r1 = new node(d);
		if(root->data > d){
			root->left = r1;
		}
		else root->right = r1;
		return;
	}
	if(root->data > d)insert(root->left,d);
	else insert(root->right,d);
}
int main(){
	node* root = takeInputLevelWise();
	print(root);
	insert(root,40);
	cout<<endl;
	print(root);
}
