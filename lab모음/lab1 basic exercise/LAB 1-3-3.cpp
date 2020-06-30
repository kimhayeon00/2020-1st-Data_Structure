//2)스트링 크기비교
#include <iostream>
#include <string>

using namespace std;

void myconcat(string s1,string s2){
    int i =0;
    while(s1[i]!=NULL)i++;
    int j = 0;
    while(s2[j]!=NULL){
        s1[i]=s2[j]; 
        i++;
        j++;
    }
    s1[i]=NULL;
}
int main(){
    string str1,str2;
    cin>> str1;
    cin>> str2;
    myconcat(str1,str2);
    cout << "String Concatenation: "<<str1;
    return 0 ;

}

