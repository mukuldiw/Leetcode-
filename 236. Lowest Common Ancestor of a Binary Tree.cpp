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
void LCAhelper(node* root,int x,vector<int> v,vector<vector<int> > &ans){
	if(!root)return;
	v.push_back(root->data);
	if(root->data == x ){
//		v.push_back(root->data);
		ans.push_back(v);
		return;
	}
	
	LCAhelper(root->left,x,v,ans);
	LCAhelper(root->right,x,v,ans);
}
int LCA(node*root,int p,int q){
	vector<int> v;
	vector<vector<int> > ans;
	LCAhelper(root,p,v,ans);
	LCAhelper(root,q,v,ans);
	int i;
    for (i = 0; i < ans[0].size() && i < ans[1].size() ; i++)
        if (ans[0][i] != ans[1][i])
            break;
    return ans[0][i-1];
}
int main(){
	node* root = takeInputLevelWise();
	print(root);
	cout<<endl;
	cout<<"LCA: "<<LCA(root,5,4);
}
//3 5 1 6 2 0 8 -1 -1 7 4 -1 -1 -1 -1 -1 -1 -1
