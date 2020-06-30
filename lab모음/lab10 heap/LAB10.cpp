#include <iostream>

using namespace std;
#define MAX_SIZE 8

int heap[100];
int tree[MAX_SIZE];
int temp;
int MaxSize = 0;
int n = 0;

void Create(int num) {
    tree[MaxSize++] = num;
}

bool HeapFull(int n) {
    if (n == MAX_SIZE) return true;
    else return false;
}

bool HeapEmpty(int n) {
    if (n == 0) return true;
    else return false;
}

void printheap() {
    for (int i = 1; i <= n; i++)
        cout << heap[i] << " ";
    cout << endl;
}

void printbt() {
    for (int i = 0; i < MaxSize; i++)
        cout << tree[i] << " ";
    cout << endl;
}

int delete_MAXheap() {
    int parent, child;
    int item, temp;

    item = heap[1];
    temp = heap[n--];
    parent = 1;
    child = 2;


    while (child <= n) {
        if ((child < n) && (heap[child] < heap[child + 1]))
            child++;

        if (temp>= heap[child])
            break;

        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return item;
}

void insert_Maxheap(int item) {
    int i;
    if (HeapFull(n)) {
        cout << "Heap is full" << endl;
        return;
    }

    i = ++n;
    while ((i != 1) && (item > heap[i / 2])) {
        heap[i] = heap[i / 2];
        i = i / 2;
    }
    heap[i] = item;
}

int leveltest() {
    return n / 2;
} 

void searchT(int a)
{
    if(HeapEmpty(n))
    {
        cout << "Heap is Empty!" << endl;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(tree[i]==a) 
        {
            cout << a << " is found" << endl;
            return;
        }
        
    }
    cout << a << " is not found"<< endl;
}
int main() {
    
    Create(8); Create(6);Create(4);Create(2);Create(5);Create(3);
    
 
    for (int i = 0; i < 6; i++) {
        insert_Maxheap(tree[i]);
    }
    

    int max_Heap;
    
    while (1) {
        cout << "Enter Command: (1.Insert, " << "2.Delete, " <<"3.search, "<< "4.Print, " << "5.is_Empty, " << "6.is_Full, "
         << "7.Leveltest " << "8.Quit) : ";
        int sel;
        cin >> sel;
        
        switch (sel) {
            case 1:
                cout << "Enter a number to insert : ";
                cin >> max_Heap;
                insert_Maxheap(max_Heap);
                printheap();
                break;
            case 2:
                delete_MAXheap();
                printheap();
                break;
            case 3:
                cout << "Enter a number to search : ";
                int a;
                cin >> a;
                searchT(a);
                break;
            case 4:
                printheap();
                break;
            case 5:
                if (HeapEmpty(n)) 
                    cout << "Heap is Empty" << endl;
                else 
                    cout << "Heap is not Empty" << endl;
                break;
            case 6:
                if (HeapFull(n)) 
                    cout << "Heap is Full" << endl;
                else 
                    cout << "Heap is not Full" << endl;
                break;
            case 7:
                cout << "Level of Heap is "<<leveltest() << endl;
                break;
            case 8:
                return 0;
        }
    }
}