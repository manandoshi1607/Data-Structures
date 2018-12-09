#include<stdio.h>
#include<malloc.h>

struct node {
	int data;
	struct node *left;
	struct node *right;
	int ht;
};

int height(struct node *T){
	int lh, rh;
	if (T==NULL){
		return 0;
	}
	
	if (T->left == NULL){
		lh = 0;
	}
	else{
		lh = T->left->ht + 1;
	}
	
	if (T->right == NULL){
		rh = 0;
	}
	else{
		rh = T->right->ht + 1;
	}
	
	if (lh > rh){
		return lh;
	}
	return rh;
}

int BF(struct node *T){
	int lh, rh;
	if (T==NULL){
		return 0;
	}
	
	if (T->left == NULL){
		lh = 0;
	}
	else{
		lh = T->left->ht + 1;
	}
	
	if (T->right == NULL){
		rh = 0;
	}
	else{
		rh = T->right->ht + 1;
	}
	
	return (lh-rh);
}

struct node *rotateright(struct node *x){
	struct node *y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return y;
}

struct node *rotateleft(struct node *x){
	struct node *y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	return y;
}

struct node *RR(struct node *T){
	printf("Rotate Right");
	T = rotateleft(T);
	return T;
}

struct node *LL(struct node *T){
	printf("Rotate Left");
	T = rotateright(T);
	return T;
}

struct node *RL(struct node *T){
	printf("Rotate RightLeft");
	T->right = rotateright(T->right);
	T = rotateleft(T);
	return T;
}

struct node *LR(struct node *T){
	printf("Rotate LeftRight");
	T->left = rotateleft(T->left);
	T = rotateright(T);
	return T;
}

struct node *insert(struct node *T, int x){
	
	if (T==NULL){
		T = (struct node*)malloc(sizeof(struct node));
		T->data = x;
		T->left = NULL;
		T->right = NULL;
		return T;
	}
	else if (x > T->data){
		T->right = insert(T->right,x);
		if (BF(T)==-2){
			if (x > T->right->data){
				T = RR(T);
			}
			else{
				T = RL(T);
			}
		}
	}
	else if (x < T->data){
		T->left = insert(T->left,x);
		if (BF(T)==2){
			if (x < T->left->data){
				T = LL(T);
			}
			else{
				T = LR(T);
			}
		}
	}
	
	T->ht = height(T);
	return T;
}

void printInorder(struct node *T){
	
	if (T==NULL){
		return;
	}
	printInorder(T->left);
	printf("%d ", T->data);
	printInorder(T->right);
}

void printPreorder(struct node *T){
	
	if (T==NULL){
		return;
	}
	printf("%d ", T->data);
	printInorder(T->left);
	printInorder(T->right);
}

void main(){
	
	struct node *T = NULL;
	T = insert(T, 10);
	T = insert(T, 20);
	T = insert(T, 30);
	T = insert(T, 40);
	T = insert(T, 50);
	T = insert(T, 60);
	T = insert(T, 70);
	T = insert(T, 80);
	printPreorder(T);
}
