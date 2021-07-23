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
int isBSTUtil(node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return 1;
             
    /* false if this node violates
    the min/max constraint */
    if (node->data < min || node->data > max)
        return 0;

    return
        isBSTUtil(node->left, min, node->data-1) && 
        isBSTUtil(node->right, node->data+1, max); 
}
int isBST(node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}


int findSum(node* root){
	if (root == NULL)
        return 0;
    return (root->data + findSum(root->left) + findSum(root->right));
}
void MaxSum(node* root,int &maxSum){
	if(!root)return;
	
	MaxSum(root->left,maxSum);
	cout<<root->data<<" -> "<<isBST(root)<<endl;
//	if( isBST(root) ){		
//		maxSum = max(maxSum,findSum(root));
//	}
	MaxSum(root->right,maxSum);
}


// This code is contributed by shubhamsingh10

int main(){
	node* root = takeInputLevelWise();
	print(root);
	cout<<endl;
	int maxSum = 0;
	MaxSum(root,maxSum);
	cout<<"Max Sum: "<<maxSum;
}
