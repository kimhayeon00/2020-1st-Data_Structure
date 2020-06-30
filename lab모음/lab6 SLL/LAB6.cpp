#include<iostream>

using namespace std;

class Node {
	int data;
	Node *next;

	Node() { this->next = nullptr; }

	Node(const Node *n) {
		Node *p = this;
		while (n) {
			p->data = n->data;

			if (n->next) {
				Node *temp = new Node();
				temp->next = nullptr
					;
				p->next = temp;
				p = p->next;
			}
			n = n->next;
		}
	}
	friend class List;
};

class List {
private:
	Node *head;
public:
	List() { head = NULL; }
	~List();
	bool isEmpty();
	void InsertNode(int num);
	void DeleteNode(int num);
	void traverse(Node *ptr = 0);
	void searchNode(int num);
	void PrintLast();
	void PrintNth(int num);
};
List::~List() {
	Node *p;
	while (head != 0) {
		p = head;
		head = head->next;
		delete p;
	}
}

bool List::isEmpty() {
	if (head == NULL) return true;
	else return false;
}

void List::InsertNode(int num) {
	Node *temp = new Node();
	temp->data = num;
	temp->next = nullptr;
	Node *p, *q;

	if (head == NULL) {
		temp->data = num;
		head = temp;
	}
	else if (temp->data < head->data) {
		temp->next = head;
		head = temp;
	}
	else {
		p = head;
		while (p != NULL && temp->data > p->data) {
			q = p;
			p = p->next;
		}
		if (p != NULL) {
			temp->next = p;
			q->next = temp;
		}
		else {
			q->next = temp;
		}
	}

}

void List::DeleteNode(int num) {
	Node *p, *q;
	if (isEmpty()) {
		cout << "Not found" << endl;
		return;
	}
	if (head->data == num) {
		p = head;
		head = head->next;
		delete p;
	}
	else {
		p = head;
		while (p != NULL && p->data != num) {
			q = p;
			p = p->next;
		}
		if (p != NULL) {
			q->next = p->next;
			delete p;
		}
		else
			cout << num << "is not in the list\n";
	}
}
void List::searchNode(int num) {
	Node *p, *q;
	p = head;
	if (head != 0) {
		while (p != NULL && p->data != num) {
			q = p;
			p = p->next;
		}
		if (p != 0)
			cout << num << " " << "is found" << endl;
		else
			cout << num << " " << "is not found" << endl;
	}
}
void List::traverse(Node *ptr) {
	Node *p;

	if (!isEmpty() || ptr != 0) {
		if (ptr != 0) {
			p = ptr;
		}
		else {
			p = head;
		}
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else {
		cout << "List is empty!\n";
	}
}




void List::PrintLast() {

	Node *p = nullptr;

	if (head != nullptr) {
		p = head;
		while (p != nullptr) {
			if (p->next == nullptr) {
				cout << "last node : " <<p->data << endl;
				return;
			}

			p = p->next;
		}
	}
	else cout << "List empty" << endl;
}

void List::PrintNth(int num) {
	Node *p, *q;
	int count = 0;
	if (!isEmpty()) {
		p = head;
		q = head;
		int i;
		while (p) {
			p = p->next;
			count++;
		}
		for (i = 1; i < count+1 ; i++) {

			if (num != i) {
				q = q->next;
			}
			else if (num == i) {
				cout << "The "<<num <<"th node : "<<q->data << endl;
			}
		}
		if (num > count)
			cout << "Out of boundary" << endl;
	}
	else {
		cout << "List is Empty \n";
	}
}


int main() {
	List L;
	int a;

	while (1) {
		cout << "1.insert   2.delete   3.search  4.print   5.PrintLast  6.printNth 7.Quit => ";
		cin >> a;
		switch (a) {
		case 1: {
			int data;
			cout << "Input a number : ";
			cin >> data;
			L.InsertNode(data);
			break;
		}
		case 2: {
			if(L.isEmpty()){cout << "List is Empty"<<endl; break;}
			else{
				int data;
				cout << "Input a number : ";
				cin >> data;
				L.DeleteNode(data);
				break;
			}
		}
		case 3: {
			if(L.isEmpty()){cout << "List is Empty"<<endl;break;}
			else{
				int data;
				cout << "Enter a number : ";
				cin >> data;
				L.searchNode(data);
				break;
			}
		}
		case 4: {
			L.traverse();
			break;
		}
		case 5: {
			L.PrintLast();
			break;
		}
		case 6: {
			int num;
			cout << "Enter Nth : ";
			cin >> num;
			L.PrintNth(num);
			break;
		}
		case 7: {
			L.~List();
			return 0;
		}

	}
}
}