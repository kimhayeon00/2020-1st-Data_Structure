#include<iostream>
using namespace std;

#define stackSize  2
#define queueSize  3

class Stack{
    private:
    char stack[stackSize];
    int top ;
    public:
    Stack(){top = -1;}
    void PUSH(char str);
    char POP();
    bool StackFull();
    bool StackEmpty();
    void DisplayStack();
};

void Stack::PUSH(char str){
    if (StackFull())cout << "StackFull\n";
    else  stack[++top] = str;
}

char Stack::POP(){
    if (StackEmpty()) {cout << "StackEmpty\n"; return 0;}
    else return stack[top--];
}

bool Stack::StackFull(){
    if(top == stackSize-1) return true;
    else return false;
}

bool Stack::StackEmpty(){
    if(top == -1) return true;
    else return false;
}

void Stack::DisplayStack(){
    if(!StackEmpty()){
        cout << "Stack: ";
        for(int i = top; i >= 0; i--){
            cout << stack[i] << " ";
        }
        cout << endl;
    }
    else cout << "StackEmpty\n";
}

class Queue{
    private:
    char queue[queueSize];
    int front;
    int rear;
    int flag;
    public:
    Queue();
    void ENQUEUE(char str);
    char DEQUE();
    bool QueueFull();
    bool QueueEmpty();
    void DisplayQ();
    void CEnque(char str);
    char CDeque();
    void DisplayCQ();
};
Queue::Queue() {
	front = -1;
	rear = -1;
}

void Queue::ENQUEUE(char str){
    if(QueueFull()) cout << "QueueFull\n";
    else queue[++rear] = str;
   
}

char Queue::DEQUE(){
    if(QueueEmpty()) cout << "QueueEmpty\n"; 
    else return queue[++front];
    return 0;
}

bool Queue::QueueFull(){
    if(rear == queueSize - 1) return true;
    else return false;
}

bool Queue::QueueEmpty(){
    if(front == rear) return true;
    else return false;
}

void Queue::DisplayQ(){
    if(QueueEmpty()){
        cout << "QueueEmpty\n";
    }
    else{
    cout << "Queue: ";
        for(int i = front+1; i <= rear; i++){
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

    

void Queue::CEnque(char str){
    if ((front == rear) && (flag == 1)) {
		cout << "QueueFull\n";
	}
	else {
		queue[rear] = str;
        rear = (rear + 1) % queueSize;
        flag = 1;
	}
     
}

char Queue::CDeque(){
    if ((front == rear)&&(flag == 0)) {
		cout << "QueueEmpty\n";
        exit(-1);
    }
	else {
		front = (front + 1) % queueSize;
        flag = 0;
        return queue[front];
	}
    
    return 0;
     
}

void Queue::DisplayCQ(){
    int tmp=0;
    for (int i = front; tmp<queueSize ; i = (i+1)%queueSize){
        cout << queue[i] << " ";
            tmp++;
    }
	cout << endl;
	
}

int main(){
    Stack s = Stack();
    Queue q1 = Queue();
    Queue q2 = Queue();
    cout << "1) [push 'a' , enque 'b' , enque 'c' , enque 'd' , push 'e' ]\n";
    s.PUSH('a'); q1.ENQUEUE('b'); q1.ENQUEUE('c'); q1.ENQUEUE('d'); s.PUSH('e');
    cout << "2) [push ‘F’ , enque ‘G’ ]\n";
    s.PUSH('F'); q1.ENQUEUE('G');
    cout << "3) display-Stack\n";
    s.DisplayStack();
    cout << "4) display-Queue\n";
    q1.DisplayQ();
    cout << "5) [pop, deque , deque, deque, pop]\n";
    cout << "Output: ";
    cout << s.POP() << q1.DEQUE() << q1.DEQUE() << q1.DEQUE() << s.POP();
    cout << endl;
    cout << "6) [pop, deque]\n";
    s.POP(); q1.DEQUE();
    cout << "7) C-Enque 'A' , C-Enque 'B', C-Enque 'C', C-Deque, C-Enque ‘D’\n";
    q2.CEnque('A'); q2.CEnque('B'); q2.CEnque('C'); q2.CDeque(); q2.CEnque('D');
    cout << "8) Display CircularQueue\n";
    q2.DisplayCQ();
    cout << "9) C-Deque, C-Deque, C-Deque, C-Deque\n";
    q2.CDeque(); q2.CDeque(); q2.CDeque(); q2.CDeque();

    return 0;
}


        
