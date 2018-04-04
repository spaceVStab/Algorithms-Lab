#include <bits/stdc++.h>
using namespace std;

typedef struct _node {
	struct _node *L; /* Left child pointer */
	struct _node *R; /* Right child pointer */
	struct _node *P; /* Parent pointer */
} treenode;
 
 //utility to make a new bst node
treenode *newNode(){
	treenode *temp = (treenode *)malloc(sizeof(treenode));
	temp->L = temp->R = temp->P = NULL;
	return temp;
}


treenode *buildtree1(string str, int n){
	treenode *root = NULL;
	treenode *currNode;
	root = newNode();
	currNode = root;
	for(int i=0;i<(2*(n-1));i++){
		if(str[i] == '0'){   //it is a left child
			//create a left child;
			treenode *leftchild;
			leftchild = newNode();
			leftchild->P = currNode;
			currNode->L = leftchild;
			currNode = leftchild;
		}
		if(str[i] == '1'){
			// this is a right child
			treenode *rightchild;
			rightchild = newNode();
			rightchild->P = currNode;
			currNode->R = rightchild;
			currNode = rightchild;
		}
		if(str[i] == '2'){
			currNode = currNode->P;
		}
	}
	return root;
}

treenode *buildtree2(string str, int n){
	treenode *root = NULL;
	treenode *currNode;
	root = newNode();
	currNode = root;
}

void printtree(treenode *root, int level){
	int i;
	//cout << "    ";
	if(level == 0){
		cout << "    ";
	}
	if(level >0){
		for(int i=0;i<level;i++){
			cout<<"    ";
		}
		cout << "+---";
	}
	if(root){
		cout <<"X\n";
		printtree(root->L, level+1);
		printtree(root->R, level+1);
	}
	else{
		cout<<"|\n";
	}

}

void genenc1(treenode *root){
	if(root->L!=NULL){
		cout<<"0";
		genenc1(root->L);
		cout<<"2";
	}
	if(root->R!=NULL){
		cout<<"1";
		genenc1(root->R);
		cout << "2";
	}
}
void destroytree(treenode *root){
	if(root == NULL){
		return;
	}
	if(root->L!=NULL){
		destroytree(root->L);
	}
	if(root->R!=NULL){
		destroytree(root->R);
	}
	if((root->L==NULL) && (root->R==NULL)){
		free(root);
	}
}

int main()
{
	// take the user input for the ternary tree
	int n,len;
	cin >> n;
	string str;
	treenode *root;
	while(1){
		cin >> str;
		len = str.length();
		if(len<(2*(n-1))){
			cout << "invalid input\ninput again\n" << endl;
		}
		else break;
	}
	cout << n << endl;
	cout << "Encoding 1" << endl;
	root = buildtree1(str,n);
	cout << "The binary tree is \n";
	printtree(root,0);
	cout << "original Encoding : "<<str<<endl;
	cout << "final Encoding : ";
	genenc1(root);
	destroytree(root);
	// cout << "\n enter the binary encoding"<<endl;
	// while(1){
	// 	cin >> str;
	// 	len = str.length();
	// 	if(len<(2*(n-1))){
	// 		cout << "invalid input\ninput again\n" << endl;
	// 	}
	// 	else break;
	// }
	return 0;

}