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
int helper(node* root,map<int,int> &m){
	if(!root)return 0;
	
	int l = helper(root->left,m);
	int r = helper(root->right,m);
//	cout<<root->data<<" -> "<<l+r+root->data<<endl;
	m[l+r+root->data]++;
	return l + r + root->data;
//	sum = sum + root->data;
	
}
void findFrequentTreeSum(node* root){
	map<int,int> m;
	helper(root,m);
	map<int,int>::iterator it;
	int sum = INT_MIN;
	for(it = m.begin();it!=m.end();++it){
		sum = max(sum,it->second);
	}
	vector<int> v;
	for(it = m.begin();it!=m.end();++it){
		if(it->second == sum){
			v.push_back(it->first);
		}
	}
	for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}
int main(){
	node* root = takeInputLevelWise();
	print(root);
	findFrequentTreeSum(root);
}
