#include <iostream>
using namespace std;

struct Node{
   char data;
   Node *next;
   Node(char value) {
      data = value;
      next = 0;
   }
};

class linkedStack {
private:
   Node *head;
public:
   linkedStack() { head = 0; }
   ~linkedStack();
   void push(char data);
   char pop();
   int isEmpty();
   void displayStack();


};


linkedStack::~linkedStack() {

}

void linkedStack::push(char data) {
   Node *temp = new Node(data);
   if (head == 0) head = temp;
   else { temp->next = head; head = temp; }
}

char linkedStack::pop() {
   Node *p;
   char num;
   num = head->data;
   p = head;
   head = head->next;
   delete p;
   return num;
}

int linkedStack::isEmpty() {
   if (head == 0) return 1;
   else return 0;
}


void linkedStack::displayStack() {
   Node *p;
   if (!isEmpty()) {
      p = head;
      while (p) {
         cout << p->data<<" "; p = p->next;
      }
   }
   else { cout << "Stack empty"; }
}

class linkedQueue {
private:
   Node *front;
   Node *rear;
public:
   linkedQueue() { front = 0; rear = 0; }
   ~linkedQueue();
   void enqueue(char data);
   char dequeue();
   int isEmpty();
   void displayQueue();

};
linkedQueue::~linkedQueue() {
   Node *p;
   while (rear != 0) {
      p = front;
      front = front->next;
      delete p;
   }
}

int linkedQueue::isEmpty() {
   if (front == 0) return 1;
   else return 0;
}

void linkedQueue::enqueue(char data) {
   Node *temp = new Node(data);
   if (front == 0) {
      front = temp;
      rear = temp;
   }
   else {
      rear->next = temp;
      rear = temp;
   }
}

char linkedQueue::dequeue() {
   Node *p; char num;
   num = front->data;
   p = front;

   if (front == rear) {
      front = 0;
      rear = 0;
   }
   else front = front->next;

   delete p;
   return num;
}

void linkedQueue::displayQueue() {
   Node *p;

   if (!isEmpty()) {
      p = front;
      while (p) {
         cout << p->data<<" ";
         p = p->next;
      }
      cout << endl;
   }
   else cout << "Queue is empty!\n";
}
class List {
private:
   Node *head;
public:
   List() { head = NULL; }
   bool isEmpty();
   void InsertNode(char data);
   void traverse();
   void concentenation(linkedStack &a, linkedQueue &b);
   void invert();
   ~List();

};
List::~List(){
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

void List::InsertNode(char data) {
   Node *temp = new Node(data);
   Node *p, *q;
   p = q = NULL;

   if (head == NULL) {
      temp->data = data;
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
void List::concentenation(linkedStack &a, linkedQueue &b) {
  
   while (!a.isEmpty())
   {
      InsertNode(a.pop());
   }
   while (!b.isEmpty())
   {
      InsertNode(b.dequeue());
   }

}

void List::invert() {
    Node *p = head, *q = 0, *r;
   while (p) {
      r = q;
      q = p;
      p = p->next;
      q->next = r;
   }
   head = q;
}


void List::traverse() {
   Node *p;
   if (!isEmpty()) {
      p = head;
      while (p) {
         cout << p->data << " ";
         p = p->next;
      }
      cout << endl;
   }
   else
      cout << "List is empty!\n";
}

int main() {
   linkedStack List1;
   linkedQueue List2;
   List List3;
   while (1) {
       int a;
		cout << "1.push   2.pop   3.printST  4.enqueue   5.dequeue  6.printQ 7.Merge  8.invert  9.PrintList   10. quit => ";
		cin >> a;
		switch (a) {
		case 1: {
			char data;
			cout << "Enter an integer to push : ";
			cin >> data;
			List1.push(data);
			break;
		}
		case 2: {
			if(List1.isEmpty()){cout << "List is Empty"<<endl; break;}
			else{
				cout << List1.pop() << "  ==>  is popped!";
                cout <<endl;
				break;
			}
		}
		case 3: {
			if(List1.isEmpty()){cout << "List is Empty"<<endl;break;}
			else{
                cout <<"Stack : ";
				   List1.displayStack();
                cout << endl;
				break;
			}
		}
		case 4: {
			char data;
			cout << "Enter an integer to enque : ";
			cin >> data;
			List2.enqueue(data);
			break;
		}
		case 5: {
            if(List2.isEmpty()){cout << "List is Empty"<<endl; break;}
			else{
				cout << List2.dequeue() << "  ==>  is dequed!";
                cout << endl;
				break;
			}
			
			
		}
		case 6: {
			if(List2.isEmpty()){cout << "List is Empty"<<endl;break;}
			else{
                cout <<"Queue : ";
				List2.displayQueue();
                cout << endl;
				break;
			}
		}
        case 7:{
            cout << "List:  ";
            List3.concentenation(List1,List2);
            List3.traverse();
            break;
        }

        case 8:{
            cout << "List:  ";
            List3.invert();
            List3.traverse();
            break;
        }

        case 9:{
            cout << "List:  " ;
            List3.traverse();
            break;
        }

		case 10: {
			List1.~linkedStack();
            List2.~linkedQueue();
            List3.~List();
			return 0;
		}

	    }
    }
}
   


