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
	if(!root)
	return 0;
	int l = height(root->left);
	int r = height(root->right);
	return 1 + max(l,r);
}
void deepestLeavesHelper(node* root,int h,vector<int> v,vector<vector<int> > &ans){
	if(!root)return;
	h--;
	v.push_back(root->data);
	if(!root->left && !root->right && h == 0){
		ans.push_back(v);
		return;
	}
	deepestLeavesHelper(root->left,h,v,ans);
	deepestLeavesHelper(root->right,h,v,ans);
}
int lcaDeepestLeaves(node* root){
	int h = height(root);
	vector<int> v;
	vector<vector<int> > ans;
	deepestLeavesHelper(root,h,v,ans);
	int n = ans.size(),m = ans[0].size();
//	cout<<ans[0][2];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
	}
	int x;
	for(int i=m-1;i>=0;i--){
		x=0;
		for(int j=0;j < n-1;j++){
			if(ans[j][i] == ans[j+1][i]){
				x++;
			}
			if(x == n-1)
			return ans[j][i];
		}
//		return ans[x][i];
//		cout<<endl;
	}
	return root->data;
}
int main(){
	node* root = takeInputLevelWise();
	print(root);
	cout<<endl;
	cout<<lcaDeepestLeaves(root);
	
}
