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
int palin(int a[9],int c){
		for(int i=0;i<9;i++)
            cout<<a[i]<<" ";
        cout<<endl;
//        return 0;
//		cout<<c<<" ";
        int b=1;
        if(c%2 == 0)
            b=0;
        for(int i=0;i<9;i++){
            if(a[i]%2 != 0 && b == 0)
                return 0;
            else if (a[i]%2 != 0 && b == 1){
                b--;
            }
        }
        if(b == 1)
            return 0;
        return 1;
    }
    void helper(node* root,int a[9],int &c,int count){
        if(!root) return;
        a[root->data-1]++;
        count++;
        if(!root->right && !root->left){
        	int x = palin(a,count);
			a[root->data-1]--;
            c = c + x;
            return;
        }
        helper(root->left,a,c,count);
        helper(root->right,a,c,count);
        a[root->data-1]--;
    }
    int pseudoPalindromicPaths(node* root) {
        int a[9]={0};
        int c=0;
        helper(root,a,c,0);
        return c;
    }
int main(){
	node* root = takeInputLevelWise();
	cout<<pseudoPalindromicPaths(root);
//	print(root);
//	rootNodePath(root,7);
}
	
	
	
