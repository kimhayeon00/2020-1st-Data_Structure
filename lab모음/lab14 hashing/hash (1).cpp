#include <iostream>
using namespace std;

const int SIZE = 7;
const int divi = 7;
class Node{
    private:
        int data;
        Node *link;
        friend class Htable;
};

class Htable{
    private:
        Node *head[SIZE];
    public: 
        Htable();
        int findKey(int);
        void insertKey(int);
        void deleteKey(int);
        void printTable();
};

Htable::Htable(){
	
    for (int i = 0; i < SIZE; i++)
        head[i] = NULL;

}

int Htable::findKey(int key){
    int idx = key % divi;
    Node *p = new Node();
    if(head[idx] != NULL){
        p = head[idx];
        while(p -> link != NULL && p -> data != key)
            p = p -> link;
        if(p -> data == key) {
             cout << key << "is found" << endl;
            return 1;
        }
           
    }
    cout << key << "is not found" << endl;
    return 0;
}

void Htable::insertKey(int key){
    Node *p = new Node();
    Node *q = new Node();
    p -> data = key;
    int idx = key % divi;
    
    if( head[idx]==NULL) head[idx] = p;
    else{
        q = head[idx];
        while(q -> link != NULL){
            q = q -> link;
        }
        q -> link = p;
    }
}

void Htable::deleteKey(int key){
    if(findKey(key)){
        int idx = key % divi;
        Node *p =  new Node();
        Node *q = new Node();
        p = head[idx];
        if (head[idx]->data == key){
            if(head[idx]->link !=NULL)
                head[idx] = head[idx]->link;
            else head[idx] = NULL;
            delete p;
        }
        else{
            while (p != NULL && p->data != key)
            {
                q = p;
                p = p->link;
            }
            if (p != NULL)
            {
                q->link = p->link;
                delete p;
            }
            else if (p == NULL) {
                delete q;
            }
            else	
                cout << key << "EMPTY" << endl;
        }
    }
    
}

void Htable::printTable(){
    Node *p = new Node();
    for (int i = 0; i < SIZE; i++) {
        cout << "Htable[" << i << "] : ";
        if (head[i] != NULL) {
            p = head[i];
            while (p != NULL) {
                cout << p->data << " ";
                p = p->link;
            }
        }
        else
            cout << "";
        cout << "\t";
    }
    cout << endl;
}

int main() {
	Htable h;

	int num = 0;
	int input;
	while (1) {
		cout << "1.Insert  2.Delete  3.Find  4.Quit" << endl;
		cin >> input;
		if (input == 1) {
			cout << "Insert Num: ";
			cin >> num;
			h.insertKey(num);
			h.printTable();
		}
		else if (input == 2) {
			cout << "Delete Num : ";
			cin >> num;
			h.deleteKey(num);
			h.printTable();
		}
		else if (input == 3) {
			cout << "Find Num : ";
			cin >> num;
			h.findKey(num);
		}
		else if (input == 4) {
			break;
		}
		
	}
	return 0;
}