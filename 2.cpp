#include<iostream>
#include<vector>
using namespace std;

// tree
// 1, Tinh chieu cao cua cay

// 2, Dem cac node theo dieu kien
// Đếm số lượng node có giá trị lớn hơn một giá trị ngưỡng X.
// Đếm số lượng node có giá trị nhỏ hơn một giá trị ngưỡng X.
// Đếm số lượng node có giá trị chẵn.
// Đếm số lượng node có giá trị lẻ.
// Đếm số lượng node có độ sâu lớn hơn hoặc bằng một giá trị ngưỡng K.
// Đếm số lượng node có độ sâu nhỏ hơn một giá trị ngưỡng K.
// Đếm số lượng node có số lượng con bằng 0 (là các lá của cây).
// Đếm số lượng node có ít nhất một con trái và không có con phải.
// Đếm số lượng node có giá trị nằm trong khoảng từ A đến B (A và B là hai giá trị ngưỡng).
// Đếm số lượng node có tổng giá trị tất cả các nút con bằng một giá trị ngưỡng X.

// 3,
// Tính tổng các node có giá trị lớn hơn một giá trị ngưỡng X.
// Tính tổng các node có giá trị nhỏ hơn một giá trị ngưỡng X.
// Tính tổng các node có giá trị chẵn.
// Tính tổng các node có giá trị lẻ.
// Tính tổng các node có độ sâu lớn hơn hoặc bằng một giá trị ngưỡng K.
// Tính tổng các node có độ sâu nhỏ hơn một giá trị ngưỡng K.
// Tính tổng các node có số lượng con bằng 0 (là các lá của cây).
// Tính tổng các node có ít nhất một con trái và không có con phải.
// Tính tổng các node có giá trị nằm trong khoảng từ A đến B (A và B là hai giá trị ngưỡng).
// Tính tổng các node có tổng giá trị tất cả các nút con bằng một giá trị ngưỡng X.

// 4,  Xuất các node trên bậc K
// 5, Đếm các node trên tầng K
// 6, Tính tổng các node trên tầng 







struct node{
	int val;
	node *left;
	node *right;
};typedef node* nd;

void inTree(nd &a){
	a = NULL;
}

void insertTree(nd &a,int x){
	nd insert = new node;
	insert->val = x;
	insert->left = NULL;
	insert->right = NULL;
	if(a==NULL) a = insert;
	else{
		nd p = a;
		while(p!=NULL){
			if(p->val==x) return;
			else{
				if(p->val < x){
					if(p->right!=NULL) p = p->right;
					else p->right = insert;
				}
				else
				{
					if(p->left!=NULL) p = p->left;
					else p->left = insert;
				}
			}
		}
	}
}

bool search(nd a,int x){
	nd p = a;
	while(p!=NULL){
		if(p->val==x) return true;
		else{
			if(p->val < x) p = p->right;
			else p = p->left;
		}
	}
	return false;
}

void searchStandFor(nd &p,nd &q){
	if(q->left==NULL){
		p->val = q->val;
		p = q;
		q = q->right;
	}
	else searchStandFor(p,q->left);
}

int deleteNode(nd &a,int x){
	if(a==NULL) return 0;
	if(a->val==x){
		nd p = a;
		if(a->left==NULL){
			a = a->right;
		}
		else if(a->right==NULL){
			a = a->left;
		}
		else searchStandFor(p,a->right);
		delete p;
		return 1;
	}
	else if(a->val < x) return deleteNode(a->right,x);
	else return deleteNode(a->left,x);
}

struct stack{
	nd val;
	stack *next;
};typedef stack* st;

void inStack(st &a){
	a = NULL;
}

void pushStack(st &a,nd x){
	st insert = new stack;
	insert->val = x;
	insert->next = a;
	a = insert;
}

void popStack(st &a){
	st p = a;
	a = a->next;
	delete p;
}

nd topStack(st a){
	return a->val;
}

bool emptyStack(st a){
	if(a==NULL) return true;
	else return false;
}



int sizeStack(st a){
	st p = a;
	int count = 0;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	return count;
}

void NLR(nd a){
	st stk = new stack;inStack(stk);
	nd curr = a;
	nd lastVisited = NULL;
	while(!emptyStack(stk)||curr){
		if(curr){
			cout << curr->val << " ";
			pushStack(stk,curr);
			curr = curr->left;
		}
		else{
			nd topNode = topStack(stk);
			if(topNode->right && lastVisited!=topNode->right){
				curr = topNode->right;
			}
			else{
				lastVisited = topNode;
				popStack(stk);
			}
		}
	}
	cout << endl;
}

void LNR(nd a){
	st stk = new stack;inStack(stk);
	nd curr = a;
	while(!emptyStack(stk) || curr){
		while(curr){
			pushStack(stk,curr);
			curr = curr -> left;
		}
		curr = topStack(stk);
		popStack(stk);
		cout << curr->val << " ";
		curr = curr -> right;
	}
	cout << endl;
}
 
struct queue{
	nd val;
	queue* next;
};typedef queue* qu;

void inQueue(qu &a){
	a = NULL;
}

void push(qu &a,nd x){
	qu insert = new queue;
	insert->val = x;
	insert->next = NULL;
	if(a==NULL) a = insert;
	else{
		qu p = a;
		while(p->next != NULL){
			p = p->next;
		}
		p->next = insert;
	}
}

int sizeQueue(qu a){
	qu p = a;
	int count = 0;
	while(p!=NULL){
		count++;
		p = p->next;
	}
	return count;
}

void pop(qu &a){
	qu p = a;
	a = a->next;
	delete p;
}


nd front(qu a){
	return a->val;
}

bool emptyQueue(qu a){
	if(a==NULL) return true;
	return false;
}

void LRN(nd a){
	qu que = new queue;inQueue(que);
	st stk = new stack;inStack(stk);
	st newStack = new stack;inStack(newStack);
	pushStack(stk,a);
	while(!emptyStack(stk)){
		nd curr = topStack(stk);
		push(que,curr);
		popStack(stk);
		if(curr->left!=NULL){
			pushStack(stk,curr->left);
		}
		if(curr->right!=NULL){
			pushStack(stk,curr->right);
		}
	}
	while(!emptyQueue(que)){
		pushStack(newStack,front(que));
		pop(que);
	}
	while(!emptyStack(newStack)){
		cout << newStack->val->val << " ";
		popStack(newStack);
	}
} 

// chieu cao cua cay
int heightOfTree(nd a){
	 if(a==NULL) return -1;
	 else{
	 	int lheight = heightOfTree(a->left);
	 	int rheight = heightOfTree(a->right);
	 	if(lheight > rheight){
	 		return (lheight + 1);
	 	}
	 	else return rheight + 1;
	 }
}

int heightOfTreeIterative(nd a){
	if(a==NULL) return -1;
	qu q = new queue;inQueue(q);
	push(q,a);
	int height = 0;
	while(true){
		int size = sizeQueue(q);
		if(size==0) break;

		while(size>0){
			nd frnt = front(q);
			pop(q);
			if(frnt->left) push(q,frnt->left);
			if(frnt->right) push(q,frnt->right);
			size--;
		}
		height++;
	}
	return height;
}

//Đếm số lượng node có giá trị lớn hơn một giá trị ngưỡng X.
int countNodeIterative(nd a){
	if(a==NULL) return 0;
	qu q = new queue;inQueue(q);
	push(q,a);
	int count = 0;
	while(true){
		int size = sizeQueue(q);
		count+=size;
		if(size == 0) break;

		while(size>0){
			nd t = front(q);
			pop(q);
			if(t->left) push(q,t->left);
			if(t->right) push(q,t->right);
			size--;
		}
	}
	return count;
}

int countNodeRecursive(nd a){
	if(a==NULL) return 0;
	return countNodeRecursive(a->left) + countNodeRecursive(a->right) + 1;
}

int largerThanK(nd a,int k){
	if(a==NULL) return 0;
	else{
		if(k < a->val) return 1 + largerThanK(a->right,k) + largerThanK(a->left,k);
		else return largerThanK(a->right,k);
	}
}


int smallerThanK(nd a,int k){
	if(a==NULL) return 0;
	else{
		if(k > a->val) return 1 + smallerThanK(a->left,k) + smallerThanK(a->right,k);
		else return smallerThanK(a->left,k);
	}
}

int evenNode(nd a){
	if(a==NULL) return 0;
	else{
		if(a->val%2==0) return 1 + evenNode(a->left) + evenNode(a->right);
		else return evenNode(a->left) || evenNode(a->right);
	}
}

int countLeafNode(nd a){
	if(a==NULL) return 0;
	else{
		if(a->left==NULL && a->right==NULL) return 1 + countLeafNode(a->left) + countLeafNode(a->right);
		else return countLeafNode(a->left) || countLeafNode(a->right);
	}
}

int main(){
	nd root = new node;inTree(root);
	std::vector<int> v = {4,2,6,1,3,5,7,8};
	for(auto x : v){
		insertTree(root,x);
	}
	NLR(root);
	LNR(root);
	LRN(root);
	cout << endl;
	cout << "Height of the tree : " << heightOfTreeIterative(root) << endl;
	cout << "Number of node : " << countNodeIterative(root) << endl;
	cout << "Number of node : " << countNodeRecursive(root) << endl;
	cout << "Number of node larger than 3 is : " << largerThanK(root,3) << endl;
	cout << "Number of node smaller than 3 is : " << smallerThanK(root,3) << endl;
	cout << "Number of node is even is : " << evenNode(root) << endl;
	cout << "Number of leaf node is : " << countLeafNode(root) << endl;
	return 0;
}