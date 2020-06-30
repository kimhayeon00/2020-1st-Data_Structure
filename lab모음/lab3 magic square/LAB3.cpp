#include<iostream>

using namespace std;

int main(void){
   int n;
   cout << "Enter number of square : ";
   cin >> n;
   int square1[n][n];
	int i, j;
	int row1, col1;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            square1[i][j] = 0;
        }
    }
    square1[0][n/ 2] = 1; 

    int key = 2; 
    i = 0, j = (n - 1) / 2; 

    while (key <= n * n) {
        
        if (i - 1 < 0) row1 = n - 1; 
        
        else row1 = i - 1; 
        
        if (j-1 < 0 ) col1 = n-1;  
        
        else col1 = j - 1; 
        
        if (square1[row1][col1]) i = (i + 1) % n; 
    
        else {i = row1; j = col1;}
        square1[i][j] = key; 
        key++; 
    }
    
    cout << "magic square size is : " << n <<endl;;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++){
            cout << square1[i][j] << ' ';
        }
        cout << endl;
    }
    int square2[n][n];
	int row2, col2;

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            square2[i][j] = 0;
        }
    }
    square2[0][n / 2] = 1; 

    key = 1; 
    i = 0, j = n / 2; 

    while (key <= n * n) {
        square2[i][j]=key;
        if(key%n==0) i=i+1;

        else {i=i-1; j=j+1;}

        if(i<0) i=n-1;
          
        if(j>n-1) j=0;
        
        key++; 
    }
    cout << "magic square size is : " << n << endl;
    for (i = 0; i <n; i++) {
        for (j = 0; j < n; j++){
            cout << square2[i][j] << ' ';
        }
        cout << endl;
    }
}


