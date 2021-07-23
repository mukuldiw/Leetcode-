#include <bits/stdc++.h> 
#include<queue>
#include<vector>
using namespace std;
class node{
	public:
	int data;
	int height;
	node* left;
	node* right;
		node(int data){
			this->data=data;
			left=NULL;
			right=NULL;
			this->height = 0;
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
	return root->height;
}
void printHeights(node* root){
	if(!root)return;
	printHeights(root->left);
	cout<<root->data<<" -> "<<root->height<<endl;
	printHeights(root->right);
}
void inorder(node* root){
	if(!root)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void insert(node* root,int d){
	if (root == NULL){
		return ;
	}
	if(!root->left && !root->right){
		node* r =new node(d);
		if(root->data < d)root->right = r;
		else root->left = r;
		return;
	}
 
    if (d < root->data)
        insert(root->left, d);
    else if (d > root->data)
        insert(root->right, d);
    else 
        return ;
 
    root->height = 1 + max((root->left->height),(root->right->height));	
	
}
int main(){
	node* root = takeInputLevelWise();
	print(root);
	insert(root,20);
	printHeights(root);
}
