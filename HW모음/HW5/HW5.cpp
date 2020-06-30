/////////////////////////////////////////////////////////////////////////////////////////////////
//  Name:  김하연
//  Student ID  :   20191580
//  Program ID :   HW5 
//  Description :    MAX HEAP Implementation & HEAP SORT
//  Algorithm : 
//   1) create - heap 배열에 차례대로 값을 넣어준다.
//   2) insert - heap 가득 차있는지 확인하고 그렇지 않으면 맨 뒤에 넣어준다. 
//               이때 부모와 비교하여 넣어준 값이 더 크면 바꾸고 그렇지 않으면 그대로 둔다.
//   3) delete - 먼저 루트를 지워주고 나머지를 힙으로 만들어주어야 한다.
//               맨 뒤에 있는 것을 heap[1]에 넣어주고 자식과 비교하여 자식이 더 크면 바꿔주고
//               그렇지 않으면 그대로 둔다.
//   4) search - heap을 돌면서 찾는 값이 있는지 검사한다.
//   5) adjust - binary tree를 n/2부터 검사하기 시작한다. 자식이 있으면 자식과 비교하여 더 큰 숫자가 있으면 
//               바꾸고 그렇지 않으면 그대로 둔다. 이를 n/2부터 1까지 for문을 돌린다.
//   6) sort - adjust 함수를 이용하여 루트를 출력하고 나머지를 힙으로 만드는것을 힙 크기만큼 반복한다.
//  Variables:
//   1) element heap - 배열을 만들기 위한 구조체이다.
//   2) MAX_SiZE - heap의 최대크기이다.
//   3) void create(int num) - heap 배열에 값 넣어줌
//   4) int isEmpty() - heap이 비어있는지 확인
//   5) int isFull() - heap이 가득 차있는지 확인
//   6) void insertHeap(int item) - 입력 받은 값을 heap에 넣어줌
//   7) void deleteHeap() - 가장 큰 값을 지워줌
//   8) bool searchHeap (int num) - 찾는 값이 있는지 확인
//   9) void leveltest() - 레벨이 몇인지 확인
//   10) void printHeap() - heap 배열 출력
//   11) void adjust(element Heap[],int i ,int n) - binary tree를 maxheap으로 변경 하기 위함
//   12) void makeHeap(element heap[]) - binary tree를 maxheap으로 변경
//   13) void sortHeap(element heap[]) - sort하여 출력
////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>

using namespace std;

typedef struct{
	int key;
}element;

#define MAX_SIZE 11
element heap[MAX_SIZE+1]; // heap 배열

void adjust(element heap[], int, int);
int n = 0;
////////////////////////////////////////////////////////////////
// Function    : create
// Description : 비어있는 heap 배열에 받은 값을 차례대로 넣어준다
// Variables:   key = heap에 들어있는 데이터 값 
//              num = 넣어줄 값
//              n = 현재 heap 크기
/////////////////////////////////////////////////////////////////
void create(int num)
{
    int i = ++n;
    heap[i].key = num;
}
////////////////////////////////////////////////////////////////
// Function    : isEmpty
// Description : 현재 heap의 크기가 0인지 확인해주는 함수
/////////////////////////////////////////////////////////////////
int isEmpty()
{
    if (n == 0) return 1; // n이 0이면 return 1
	else return 0;
}
////////////////////////////////////////////////////////////////
// Function    : isfull
// Description : 현재 heap 크기와 MAX_SIZE인지 확인해주는 함수
// Variables :   MAX_SIZE = 11 (최대 크기)
/////////////////////////////////////////////////////////////////
int isFull()
{
    if (n == MAX_SIZE) return 1; // n이 MAX SIZE이면 return 1
	else return 0;
}
////////////////////////////////////////////////////////////////
// Function    : insertHeap
// Description : max heap에 입력 받은 값을 넣어주는 함수
/////////////////////////////////////////////////////////////////
void insertHeap(int item)
{
    int i;
    if(isFull())
        cout << "Heap is full!" << endl;
    else 
    {
        i = ++n;
        while(i!=1 && item > heap[i/2].key)
        {
            heap[i] = heap[i/2];
            i /= 2;
        }
        heap[i].key = item;
    }
}
////////////////////////////////////////////////////////////////
// Function    : deleteHeap
// Description : 가장 큰 값을 지워주고 나머지를 heap으로 만들어주는 함수
// Variables:   parent = 부모
//              child = 자식
//              item = 루트 저장
//              temp = heap 배열 마지막에 있는 값을 가져옴
/////////////////////////////////////////////////////////////////

void deleteHeap()
{
    int parent, child;
    element item, temp;

    item = heap[1];
    temp = heap[n--]; // 현재 크기는 하나 줄어야함.
    parent = 1;
    child = 2;

    while(child <= n)
    {
        if(child < n && heap[child].key < heap[child+1].key)
            child++;
        if(temp.key >= heap[child].key) break;
        heap[parent] = heap[child];
        parent = child;
        child = child * 2;
    }

    heap[parent] = temp;

}
////////////////////////////////////////////////////////////////
// Function    : searchHeap
// Description : 입력받은 값이 있는지 없는지 확인하는 함수
/////////////////////////////////////////////////////////////////

bool searchHeap (int num)
{
    for(int i=1; i<=n; i++ )
    {
        if(num == heap[i].key)
            return 1;
    }
    return 0;
}
////////////////////////////////////////////////////////////////
// Function    : leveltest
// Description : 지금 heap의 깊이가 얼마나 되는지 알려주는 함수
// Variables:   level = 깊이가 늘어날 때 마다 +
/////////////////////////////////////////////////////////////////

void leveltest() {
    int level = 0;
    for (int i = 1; i <= n; i *= 2)
        level++;

    cout << "Level is " << level << endl;
}
////////////////////////////////////////////////////////////////
// Function    : printHeap
// Description : heap을 출력해주는 함수
/////////////////////////////////////////////////////////////////

void printHeap()
{
    if(isEmpty()) cout << "Heap is empty!!" << endl;
    else
    {
        for(int i=1; i<=n; i++)
        {
            cout << heap[i].key << " ";
        }
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////
// Function    : adjust
// Description : binary tree에서 max heap으로 바꾸어주는 함수
// Variables:   child = 왼쪽자식 오른쪽자식 중 하나를 선택하기 위한 변수
/////////////////////////////////////////////////////////////////

void adjust(element Heap[],int i ,int n)
{
    int child, j;
    child = 2*i;
    element temp = Heap[i];
    while (n >= child) {
        if (n > child && Heap[child].key < Heap[child+1].key)
            child =child+1; //right child 선택
        if(temp.key >= Heap[child].key) break;
        j=child/2;
        Heap[j] = Heap[child];
        child=2*child;
    }
    j=child/2; Heap[j]=temp;
    return; 
}
////////////////////////////////////////////////////////////////
// Function    : makeHeap
// Description : max heap으로 만들어주는 함수
/////////////////////////////////////////////////////////////////

void makeHeap(element heap[])
{
    for(int i=n/2; i>0; i--)
    {
        adjust(heap,i,n);
    }
}
////////////////////////////////////////////////////////////////
// Function    : sortHeap
// Description : heap에 있는 값을 순서대로 정렬해주는 함수
// Variables:   swap(a,b) = a와 b를 바꿔준다.
/////////////////////////////////////////////////////////////////

void sortHeap(element heap[])
{
    for (int i = n / 2; i > 0; i--)
            adjust(heap, i, n);

    for (int i = n - 1; i > 0; i--) {
        swap(heap[1], heap[i + 1]);
        adjust(heap,1, i);
        printHeap();
    }
    cout << "Sort결과 : ";
    printHeap();
    cout << endl;
}




int main() {
    create(26); create(5); create(77); create(1); create(61);create(11); create(59); create(15); create(48); create(19);
    
    printHeap();
    while (1) {
        cout << "Enter Command: (1.Insert, " << "2.Delete, " << "3.search, " << "4.print, " << "5.level test, "
         << "6.heap sort, " <<"7.make heap"<< "8.Quit) : ";
        int sel;
        cin >> sel;
        
        switch (sel) {
            case 1:
                int a;
                cout << "Enter a number to insert : ";
                cin >> a;
                insertHeap(a);
                printHeap();
                break;
            case 2:
                deleteHeap();
                printHeap();
                break;
            case 3:
                if (isEmpty()) 
                    cout << "Heap is Empty" << endl;
                else {
                    cout << "Enter a number to search : ";
                    int a;
                    cin >> a;
                    if(searchHeap(a))
                        cout << a << "is found";
                    else cout << a << " is not found";

                    cout << endl;

                
                }
                    
                break;
            case 4:
                if (isEmpty()) 
                    cout << "Heap is Empty!!" << endl;
                else {
                    printHeap();
                }

                    
                break;
            case 5:
                leveltest();
                break;
            case 6:
                sortHeap(heap);
                break;
            case 7:
                makeHeap(heap);
                printHeap();
                break;
            case 8:
                return 0;
        }
    }
}



