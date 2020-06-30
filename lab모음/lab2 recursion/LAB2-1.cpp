#include <iostream>

using namespace std;
int BS(int lst[], int n, int un , int ln );
int RS(int lst[], int n, int un , int ln );
int main(){
    int lst[]={10,20,30,40,50,60,70,80,90,100};
    int n=0;
    int a=0;    
    int un=9;
    int ln=0;
    while (true) {
          
        cout << "Enter method of search: (1. Bin-search 2.Recursive search 3.Exit): ";
        cin >> a;
        cout << endl;
        

    if(a==1){
        cout << "Enter an integer to search: ";
        cin >> n; 
        cout << endl;
        int bsnum = BS(lst, n, un, ln );
        if (bsnum==-1){
            cout << n << " is not found."<<endl;
        }
        else {
            cout << n << " is at position "<<bsnum+1<< "."<<endl;
        }
        
        }
    else if(a==2){
        cout << "Enter an integer to search: ";
        cin >> n; 
        cout << endl;

        int rsnum = RS(lst, n, un, ln );
        if(rsnum==-1){
            cout << n << " is not found."<<endl;
        }
        else{
            cout << n << " is at position "<<rsnum+1<< "."<<endl;
        }
        
    }
    else{
        break;
    }

    }
  
    return 0;
}


int BS(int lst[], int n, int un , int ln ){

    
    while(un>=ln){
        int midnum = (un+ln)/2;

        if (lst[midnum]>n){
            un = midnum-1;
        }
        else if (lst[midnum]<n){
            ln = midnum+1;

        }
        else{
            return midnum;
            
        } 
    }
    return -1;
}
int RS(int lst[], int n, int un, int ln ){
    
    if(ln==un){
        return -1;
    }

    int mid = (un+ln)/2;
    if (lst[mid]==n){
        return mid;

    }
    else if (lst[mid]>n){
        un= un-1;
        return RS(lst, n, un, ln );
        
    }
    else{
        ln=ln+1;
        return RS(lst, n, un, ln );
    }
   
}