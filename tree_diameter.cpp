#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;
typedef struct node{
	int data;
	struct node *left;
	struct node * right;
}ND;

int max_dia=0;
ND * crtNd(int data){
	ND *temp= (ND *) malloc(sizeof(ND));
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}

int getDia(ND *node){
	if(node->left==NULL && node->right==NULL){
		 if(max_dia<1) max_dia=0;
		 return 0;
	 }
	else if(node->left==NULL) {
		int dia=1+getDia(node->right);
		if(dia>max_dia) max_dia=dia;
		return dia;
	}
	else if(node->right==NULL) {
		int dia=1+getDia(node->left);
		if(dia>max_dia) max_dia=dia;
		return dia;
	}
	else{
		int l=getDia(node->left);
		int r=getDia(node->right);
		if(l+r+2>max_dia) {
			max_dia=l+r+2;			
		}
		return max(l,r)+1;
	}
	
}

int main(){
	ND * root=crtNd(1);
	root->left=crtNd(1);
	root->right=crtNd(1);
	root->left->left=crtNd(1);
	root->left->right=crtNd(1);
	root->left->right->right=crtNd(1);
	root->left->right->left=crtNd(1);
	root->right->right=crtNd(1);
	getDia(root);	
	cout<<max_dia<<endl;
	return 0;
}
