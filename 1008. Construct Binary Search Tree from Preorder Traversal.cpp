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
node* PreOrderToBST(vector<int> a){
	int n = a.size();
	node* root = new node(a[0]);
	stack<node*> s;
	s.push(root);
	int i = 1;
	
	while(i < n){
		node* r = s.top();
		node* p  = r;
		while(p->data < a[i] && s.size()){
			r = s.top();
			s.pop();
			if(s.size())
			p = s.top();
		}
		if(r->data < a[i]){
			node* x = new node(a[i]);
			r->right = x;
			s.push(x);
			i++;
			continue;
		}
		else if (r->data > a[i]){
			node* x = new node(a[i]);
			r->left = x;
			s.push(x);
			i++;
		}
	}
	return root;
}
int main(){
//	node* root = takeInputLevelWise();
//	print(root);
	vector<int> v;
	v.push_back(10);
	v.push_back(5);
	v.push_back(1);
	v.push_back(7);
	v.push_back(40);
	v.push_back(52);
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
	cout<<endl;
	node* root1 = PreOrderToBST(v);
	print(root1);
}

















