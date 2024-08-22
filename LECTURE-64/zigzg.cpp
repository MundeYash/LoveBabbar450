#include<iostream>
#include<queue>
using namespace std   ; 
// creation of class name node for every new node of tree 
class node{
public: 
int data ; 
node* left ; 
node* right ; 

// default constructor creation 
node(int d){
	data =d  ; 
	left= right = NULL ;
}
} ; 
// function of creation of tree and taking input in preOrder traversal 
node* createTree(){
	// bc 

	// rc 
	int data ; 
	cin>> data ;
	bool result ; 
	cin>> result ; 
	if (result == false  ){
		return NULL;

	} 
	node* root = new node(data) ; // node 
	root ->left = createTree() ; //left subtree creation 
	root ->right = createTree() ; // Right subtree creation 

	return root ;



}
// function for zig -zag printing of level order traversal 
void levelOrder ( node* root ){
	queue<node* > q  ;
	q.push(root ) ; 
	q.push(NULL) ;
	int count =1 ; 

	while (!q.empty()){
		node* f = q.front() ; 
		q.pop() ; 
		// printing left to right for odd 
		if (count%2 !=0){
		if (f != NULL){
			cout<<f->data<<" ";
			if (f->left){
				q.push(f->left	) ;
			}
			if (f->right){
				q.push(f->right) ;
			}
		}
		else {// means one level completed 
		cout<<endl;
		count++ ; 
		if (!q.empty()){
			q.push(NULL) ;
		}

		}
	}
	if (count%2 == 0){
		if (f!= NULL){
			cout<<f->data<<" ";
			if (f->right){
				q.push(f->right) ;
			}
			if (f->left){
				q.push(f->left	) ;
			}
			
		}
		else {// means one level completed 
		cout<<endl;
		count ++ ;
		if (!q.empty()){
			q.push(NULL) ;
		}

		}
	}


	}

}
int main() {
	node* root  = createTree() ; 
	levelOrder(root);
	return 0;
}