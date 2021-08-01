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

void helper(node* root,string &s,vector<string> &v){
	if(!root)return;
	char ch = root->data + 48;
	s = s + ch;
	if(!root->left && !root->right){
//		v.push_back(path);
		v.push_back(s);
		s = s.substr(0,s.length()-1);
//		s = "";
		return;
	}
	helper(root->left,s,v);
//	s = s.substr(0,s.length()-1);
	helper(root->right,s,v);
	s = s.substr(0,s.length()-1);
}

int sumNumbers(node* root){
	vector<string> v;
	string x = "";
	helper(root,x,v);
	int sum = 0;
	for(int i=0;i<v.size();i++){
		stringstream ss(v[i]);
		int t = 0;
		ss >> t;
		sum = sum + t;
	}
	return sum;
}
int main(){
	node* root = takeInputLevelWise();
	cout<<"Sum of all nodes: "<<sumNumbers(root);
}
