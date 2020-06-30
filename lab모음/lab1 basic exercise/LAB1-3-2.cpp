//2)스트링 크기비교
#include <iostream>
#include <string>

using namespace std;

int mystrcmp(char s1[], char s2[]){
    int i = 0;
    while(s1[i]==s2[i]&&s1[i]!='\0'&&s2[i]!='\0'){
        i++;
    }
    if(s1[i]>s2[i]){
        return 1;

    }
    else if (s1[i]<s2[i]){
        return -1;
    }
    else{
        return 0;
    }

}

int main(){
    char mystr1[80],mystr2[80];
    cin >> mystr1;
    cin >> mystr2;
    
    int result=mystrcmp(mystr1,mystr2);
    cout << result;
    return 0;
}