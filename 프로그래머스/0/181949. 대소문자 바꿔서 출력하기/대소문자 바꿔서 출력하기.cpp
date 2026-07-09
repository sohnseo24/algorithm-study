#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    
    for(int i=0; i<str.length(); i++){
        if (islower(str[i])){
            str[i]=(char)toupper(str[i]);
        }
        else{
            str[i]=(char)tolower(str[i]);
        }
        cout<<str[i];
    }
    
    return 0;
}