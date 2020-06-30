////////////////////////////////////////////////////////////////
// Name:  김하연
// Student ID   :   20191580
// Program ID   :   HW4 Doubly Linked List
// Description  :   Doubly Linked List 의 여러 함수들을 테스트 해본다.            
// Algorithm    :  
//   1) insertAfter   :  새로운 노드 temp를 생성하고 current -> prev 에 링크해준다.
//                       리스트가 비어있으면 head에 temp를 넣어준다.
//   2) insertBefore  :  새로운 노드 temp를 생성하고 current -> next 에 링크해준다.
//                       리스트가 비어있으면 head에 temp를 넣어준다.
//   3) insertFirst   :  새로운 노드 temp를 생성하고 head -> prev 에 링크해준다. head는 temp로 바꿔준다.
//                       리스트가 비어있으면 head에 temp를 넣어준다.
//   4) insertLast    :  새로운 노드 temp, p를 생성하고 temp에는 입력 받은 값을, p에는 head를 넣어준다.
//                       p가 마지막 노드가 될 때 까지 p -> next 해준 뒤 p -> next에 temp를 링크해준다.
//                       리스트가 비어있으면 head에 temp를 넣어준다.
//   5) deleteCurrent :  current 위치를 확인하고 current가 head이면 head에 current -> prev를 넣어주고 current 노드는 삭제한다.
//                       current가 마지막에 있으면 current -> prev -> next를 0으로 해주고 current는 삭제한다.
//                       current가 중간에 있으면 current 앞의 노드와 뒤의 노드를 서로 링크해준 뒤 current는 삭제한다.     
//   6) LocateCurrent :  입력 받은 위치값 N이 list의 길이보다 크지 않을 때 새로운 노드 p를 만들어 주고 p를 이동시키면서 count를 세어준다.
//                       count값이 N과 같아지면 current에 p를 넣어주고 출력해준다.             
//   7) updateCurrent :  current -> data 에 입력받은 숫자를 넣어준다.    
//   8) displayCurrent:  current에 위치한 데이터를 출력해준다.        
//   9) displayList   :  리스트 전체를 출력해준다.
// Variables:
//   temp = 입력받은 숫자를 데이터값으로 갖는 새로운 노드
//   int sz   = list의 길이를 세어준다.
//   class Node = 총 세개의 필드를 가지고 있다. data값과 앞에 노드를 링크하기 위한 prev,
//                뒤의 노드를 링크하기 위한 next 가 있다.
//   class List = 여러가지 함수를 가지고 있다.
//                head는 가장 앞의 노드를, current는 현재 위치하고 있는 노드를 나타낸다.
//   void insertAfter(int)  = current 노드 뒤에 insert
//   void insertBefore(int  = current 노드 앞에 insert
//   void insertFirst(int)  = 리스트 맨 앞에 insert
//   void insertLast(int)   = 리스트 맨 뒤에 insert
//   void deleteCurrent()   = current 노드 삭제
//   void LocateCurrent(int)= 위치를 입력받고 해당 데이터를 출력
//   void updateCurrent(int)= current 노드의 데이터값 교체   
//   void displayCurrent()  = current 노드의 데이터값 출력     
//   void displayList()     = 전체 리스트 출력
//   ~List()                = 리스트 클리어
//   bool isEmpty()         = 리스트가 비어있는지 확인
//   int listLength()       = 리스트 길이를 리턴           
/////////////////////////////////////////////////////////////////
#include<iostream>

using namespace std;
int sz = 0;
class Node{
    private:
        int data;  //데이터값
        Node *next;//뒤의 노드 링크
        Node *prev;//앞의 노드 링크
        Node(int num){data = num; prev = 0; next = 0;}
    friend class List;
};

class List{
    private:
        Node *head; //맨앞 노드
        Node *current;  //현재 노드
    public:
        List();
        void insertAfter(int);      //case 1
        void insertBefore(int);     //case 2
        void insertFirst(int);      //case 3
        void insertLast(int);       //case 4
        void deleteCurrent();       //case 5
        void LocateCurrent(int);    //case 6
        void updateCurrent(int);    //case 7
        void displayCurrent();      //case 8
        void displayList();         //case 9
        ~List();                    //case 10
        bool isEmpty();
        int listLength();

};

List::List(){
    head = 0; 
    current = 0;
}
int List::listLength(){
    return sz; //리스트 길이 리턴
}

bool List::isEmpty(){ // 리스트가 비었는지 확인
    if(head == 0) return true;
    else return false; 
}
////////////////////////////////////////////////////////////////
// Function    : insertAfter
// Description : current노드 뒤에 insert 해주는 함수
// Variables:   temp = 입력 받은 숫자를 데이터값으로 갖는 새로운 노드
/////////////////////////////////////////////////////////////////
void List::insertAfter(int num){
    Node *temp = new Node(num); //새로운 노드 생성
    if(isEmpty()) head = temp; //리스트가 비어있으면 temp가 head가 됨
    else if(current -> next != 0){ //current가 마지막 노드가 아니면
        temp -> prev = current; 
        temp -> next = current -> next; 
        current -> next -> prev = temp; 
        current -> next = temp; 
    }
    else{ // current가 마지막 노드일 때
        current -> next = temp; 
        temp -> prev = current; 
        
    }
    current = temp; //insert 된 노드가 current
    sz++; //리스트 길이 +1

}
////////////////////////////////////////////////////////////////
// Function    : insertBefore
// Description : current노드 앞에 insert 해주는 함수
// Variables:  temp = 입력 받은 숫자를 데이터값으로 갖는 새로운 노드
/////////////////////////////////////////////////////////////////
void List::insertBefore(int num){
    Node *temp = new Node(num);

    if(isEmpty()) head = temp;
    else if(current == head){ //current가 맨 처음 노드일 때
        temp -> next = current; 
        current -> prev = temp; 
        head = temp; // head는 temp로 바뀐다
    }
    else{ //current가 맨 처음 노드가 아닐 때
        current -> prev -> next = temp; 
        current -> prev = temp;
        temp -> next = current;
        temp -> prev = current -> prev;
    }
    current = temp; // insert 된 노드가 current
    sz++;
}
////////////////////////////////////////////////////////////////
// Function    : insertFirst
// Description : 리스트 맨 앞에 insert 해주는 함수
// Variables:  temp = 입력 받은 숫자를 데이터값으로 갖는 새로운 노드
/////////////////////////////////////////////////////////////////
void List::insertFirst(int num){
    Node *temp = new Node(num);
    if(isEmpty()) head = temp;
    else{
        head -> prev = temp;
        temp -> next = head;
        head = temp;
    }
    current = temp;
    sz++;
}
////////////////////////////////////////////////////////////////
// Function    : insertLast
// Description : 리스트 맨뒤에 insert 해주는 함수
// Variables:   temp = 입력 받은 숫자를 데이터값으로 갖는 새로운 노드
//              p = 리스트를 이동하며 마지막을 찾아내기 위한 노드
/////////////////////////////////////////////////////////////////
void List::insertLast(int num){
    Node *temp = new Node(num);
    Node *p = head; //p는 head부터 시작
    temp -> data = num;
    if(isEmpty()) head = temp;
    else if(current -> next == 0){ //current가 마지막 노드일 때
        current -> next = temp;
        temp -> prev = current;
    }
    else{
        while(p-> next != 0){ //마지막 노드가 아니면
            p = p -> next; //다음 노드로 이동
        }
        p -> next = temp; // temp가 마지막 노드
        temp -> prev = p; 
    }
    current = temp;
    sz++;
}
////////////////////////////////////////////////////////////////
// Function    : deleteCurrent
// Description : current 노드 삭제해주는 함수
// Variables:   p = 삭제할 노드
/////////////////////////////////////////////////////////////////
void List::deleteCurrent(){
    Node *p;
    if(isEmpty()) return;
    else if(current == head) { //current가 head일 때
        if(listLength()==1){
            head = 0;
            current = 0;
            delete current;
            sz--;
            return;
        }
        p = head;
        head = head -> next; //head 다음 노드가 head 됨 
        head -> prev = 0; 
        current = current -> next; 
        sz--; //리스트 길이 -1
        delete p;
    }
    else if(current -> next == 0){ //current가 마지막 노드일 때
        p = current;
        current -> prev -> next = 0;
        current = head;
        sz--;
        delete p;
    }
    else{ 
        p = current;
        current -> prev -> next = current -> next;
        current -> next -> prev = current -> prev;
        current = current -> next;
        sz--;
        delete p;
    }
}
////////////////////////////////////////////////////////////////
// Function    : LocateCurrent
// Description : 위치를 입력받고 해당 데이터를 출력
// Variables:   p = current 찾아내기 위한 노드
/////////////////////////////////////////////////////////////////
void List::LocateCurrent(int N){
    Node *p = head;
    if(isEmpty()) cout << "List Empty!\n";
    else if (N <= listLength()){ // 위치값이 리스트 길이보다 길지 않을 때
        int count = 1;
        while(count<N){ //current노드에 이를때 까자
            p = p -> next; //p를 다음 노드로 이동시켜줌
            count++;
        }
        cout << N << "  *  " << p -> data << endl;
        current = p;
    }
    else{  //위치값이 리스트 길이보다 클 때
        cout << "No such a line\n";
    }
}
////////////////////////////////////////////////////////////////
// Function    : updateCurrent
// Description : current의 data값을 바꿔주는 함수
/////////////////////////////////////////////////////////////////
void List::updateCurrent(int num){
    if(isEmpty()) return;
    else current -> data = num;
}
////////////////////////////////////////////////////////////////
// Function    : displayCurrent
// Description : current노드의 데이터값을 보여주는 함수
// Variables:   p = current 찾아내기 위한 노드
/////////////////////////////////////////////////////////////////
void List::displayCurrent(){
    Node *p;
    int cnt = 1; //head부터 current까지 몇개의 노드가 있는지 세어준다
    if(isEmpty()) cout << "List Empty!\n";
    else {
        p = head;
        while(p != current){
            p = p -> next;
            cnt++;
        }
        cout << cnt << "  *  " << current -> data << endl;
    }
    
}
////////////////////////////////////////////////////////////////
// Function    : displayList
// Description : 전체 리스트를 출력
// Variables:   p = current 찾아내기 위한 노드
//              c = 리스트의 순서를 나타내기 위함
/////////////////////////////////////////////////////////////////
void List::displayList(){
    Node *p;
    if(isEmpty()) cout << "List Empty!\n";
    else{
        cout << "--List--" << endl;
        p = head;
        int c = listLength(); 
        while(c){ 
            for(int i=1; i<=listLength(); i++){
                if(p == current){ //current에는 * 표시를 해준다
                    cout << i << "  *  " << p -> data << endl;
                    c--;
                }
                else{
                    cout << i << "  :  " << p -> data << endl;
                    c--;
                }
                p = p -> next;
            }

        }
    }

}

List::~List(){ // 리스트 클리어
    Node *p;
	while (!isEmpty()) {
		p = head;
		head = head->next;
		delete p;
	}
}

int main(){
    List L;
    int a;
    while (1) {
        cout << "1.Insert-After   2.Insert-Before   3.Insert-First   4.Insert-Last   5.Delete-Current" << endl;
        cout << "6.Locate-Current   7.Update-Current   8.Display-Current   9.Display-List   10.Quit\n==> ";
		cin >> a;
		switch (a) {
		case 1: {
            cout << "Enter a data to insert => ";
            int num;
            cin >> num;
            L.insertAfter(num);
            L.displayList();
			break;
		}
		case 2: {
            cout << "Enter a data to insert => ";
            int num;
            cin >> num;
            L.insertBefore(num);
            L.displayList();
            break;
		}
		case 3: {
            cout << "Enter a data to insert => ";
            int num;
            cin >> num;
            L.insertFirst(num);
            L.displayList();
			break;
		}
		case 4: {
			cout << "Enter a data to insert => ";
            int num;
            cin >> num;
            L.insertLast(num);
            L.displayList();
			break;
		}
		case 5: {
			L.deleteCurrent();
            L.displayList();
			break;
		}
		case 6: {
            cout << "Enter a position to locate => ";
            int N;
            cin >> N;
            L.LocateCurrent(N);
			break;
		}
		case 7: {
            cout << "Enter a data to update => ";
            int num;
            cin >> num;
            L.updateCurrent(num);
            L.displayList();
			break;
		}
        case 8: {
            L.displayCurrent();
			break;
		}
        case 9: {
            L.displayList();
			break;
		}
        case 10: {
            L.~List();
			return 0;
		}
	}
}
}

