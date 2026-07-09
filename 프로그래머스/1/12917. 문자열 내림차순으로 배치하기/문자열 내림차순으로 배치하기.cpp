#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int n= s.size();
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-1-i; j++){
            if(s[j]<s[j+1]){
                char temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    
    return s;
}