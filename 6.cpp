#include <bits/stdc++.h>
using namespace std;

typedef struct _node{
	struct _node *L;
	struct _node *R;
	int data;
} treenode;

treenode* newNode(int data){
	treenode *temp = (treenode *)malloc(sizeof(treenode));
	temp->data = data;
	temp->L=temp->R=NULL;
	return temp;
}


int binarysearch(int numbers[], int l, int r, int d){
	int mid = (l+r)/2;
	if(numbers[mid]<d){
		if(numbers[mid+1]>d){
			return mid;
		}
		else{
			binarysearch(numbers, mid+1, r,d);
		}

	}
	if(numbers[mid]>d){
		if(numbers[mid-1]<d){
			return mid-1;
		}
		else{
			binarysearch(numbers, l,mid-1,d);
		}
	}
}

treenode* constructTree(int numbers[], int preIndex, int l, int r, int n){
	int le=0, ri=0;
	if(preIndex >= n){
		return NULL;
	}
	if(l>r){
		return NULL;
	}
	treenode* root = NULL;
	treenode* temp = NULL;
	root = newNode(numbers[preIndex]);
	le = binarysearch(numbers, l, r, numbers[preIndex]);
	ri = le+1;
	//cout << le << "\n";
	if(le == l){
		temp = newNode(numbers[l]);
		root->L = temp;
	}
	else{
		root->L = constructTree(numbers, l, l+1, le, n);
	}
	if(ri == r){
		temp = newNode(numbers[r]);
		root->R = temp;
	}
	else{
		root->R = constructTree(numbers, ri, ri+1, r, n);	
	}
	//*preIndex = *preIndex +1;
	return root;
}




treenode *buildBST(int numbers[], int n){
	return constructTree(numbers, 0, 1,n-1,n);

}

void preorder(treenode* root){
	if(root == NULL){
		return;
	}
	cout << root->data << " ";
	preorder(root->L);
	//cout <<  root->data << " ";
	preorder(root->R);
}

int main(){
	int n;
	cin >> n;
	int numbers[n+1];
	for (int i = 0; i < n; ++i)
	{
		cin >> numbers[i];
	}
	treenode *root = buildBST(numbers,n);
	cout << "the preorder printing of the tree\n";
	preorder(root);
	return 0;
}