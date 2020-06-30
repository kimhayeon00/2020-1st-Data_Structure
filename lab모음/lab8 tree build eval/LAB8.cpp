#include <iostream>
#include <cctype>
using namespace std;

const int prec[4][2] = {'*',2,'/',2,'+',1,'-',1};

class Node{
	private:
		char data;
		int prio;
		Node *left;
		Node *right;
		Node(char chr){ data = chr; left = 0; right = 0; prio = 5;}
	friend class Tree;
};

class Tree{
	private:
		Node *root;
	public:
		Tree(){root = 0;}
		void build(char input);
		void Operand(Node *temp);
		void Operator(Node *temp);
		void Inorder(Node *p);
		void Preorder(Node *p);
		void Postorder(Node *p);
		void LPR(){Inorder(root);}
		void PLR(){Preorder(root);}
		void LRP(){Postorder(root);}
		int eval(Node *p);
		void evalTree(){cout << eval(root);}
		~Tree();
		void delTree(Node* p);
};
Tree::~Tree(){
	delTree(root);
}
void::Tree::delTree(Node* p){
	if(p){
		delTree(p->left);
		delTree(p->right);
		delete p;
	}
}

void Tree::build(char input){
	if(input != 0){
		Node *temp = new Node(input);
		for(int i=0; i<4; i++){
			if(temp->data == prec[i][0]){
				temp->prio = prec[i][1];
				Operator(temp);
				return;
			}
		}
		Operand(temp);
	}
}

void Tree::Operand(Node *temp){
	Node *p;
	if(root == NULL){
		root = temp;
		return;
	}
	p = root;
	while(p->right != NULL){
		p = p->right;
	}
	p->right = temp;
}

void Tree::Operator(Node *temp){
	if(root->prio >= temp->prio){
		temp->left = root;
		root = temp;
	}
	else{
		temp->left = root->right;
		root->right = temp;

	}
}

void Tree::Inorder(Node *p){
	if(p){
		Inorder(p->left);
		cout << p->data << " ";
		Inorder(p->right);
	}
}

void Tree::Preorder(Node *p){
	if(p){
		cout << p->data << " ";
		Preorder(p->left);
		Preorder(p->right);
	}
}

void Tree::Postorder(Node *p){
	if(p){
		Postorder(p->left);
		Postorder(p->right);
		cout << p->data << " ";
	}
}



int Tree::eval(Node *p){
	int value, left, right;
	if(p){
		if(isdigit(p->data)){
			value = p->data -'0';
		}
		else{
			left = eval(p->left);
			right = eval(p->right);
			switch(p->data){
				case '+': value = left+right; break;
				case '-': value = left-right; break;
				case '*': value = left*right; break;
				case '/': value = left/right; break;

			}
		}
	}
	return value;
}


int main(){
	
	int  i=1;
	while(1){
		Tree tree;
		cout <<"Infix Expression"<<i++<<" : ";
		char str[100]; 

		int a = 0;
		cin >> str;
		while (str[a] != 0) {
			tree.build(str[a]);
			a++;
		}
		cout << endl;
		
		cout << "inorder : ";
		tree.LPR();
		cout <<endl;
			
			
		cout << "postorder : ";
		tree.LRP();
		cout << endl;
		
		cout << "preorder : ";
		tree.PLR();
		cout << endl;

	
		
		
		if(isdigit(str[0])){
			cout << "eval : ";
			tree.evalTree();
		}	
		cout << endl << endl;
	}
}