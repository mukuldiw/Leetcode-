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
void totalNodes(node* root,int &c){
	if(!root)
	return;
	totalNodes(root->left,c);
	c++;
	totalNodes(root->right,c);
}
void helper(node* root,int &count,int m){
        if(!root)
            return;
        if(root->left || root->right){
            m = max(m,root->data);
        }
        if( root->data < m){
            count++;
            return;
        }
        helper(root->left,count,m);
        helper(root->right,count,m);
        return;
    }
int goodNodes(node* root) {
    int count=0,m=0,c;
    totalNodes(root,c);
    helper(root,count,m);
    return c - count;
}
int main(){
	node* root = takeInputLevelWise();
	print(root);
	cout<<endl<<goodNodes(root);
}
	
	
	
