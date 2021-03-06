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
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l,r);
}
void helper(node* root,int h,int &max_h,vector<int> &v){
	if(!root)return;
	
	h--;
	helper(root->left,h,max_h,v);
//	cout<<root->data<<" -> "<<h<<endl;
	v[max_h - h-1] += root->data;
	
	helper(root->right,h,max_h,v);
}
int maxLevelSum(node* root){
	int max_h = height(root);
	vector<int> v(max_h,0);
	cout<<max_h;
	int res = INT_MIN,ans_h=1;
	helper(root,max_h,max_h,v);
	for(int i=0;i<v.size();i++){
//		cout<<v[i]<<" ";
		if(v[i] > res){
			res = v[i];
			ans_h = i+1;
//			break;
		}
	}
	return ans_h;
}

int main(){
	node* root = takeInputLevelWise();
	print(root);
	cout<<endl;
	cout<<"Max Sum Height: "<<maxLevelSum(root);
}
