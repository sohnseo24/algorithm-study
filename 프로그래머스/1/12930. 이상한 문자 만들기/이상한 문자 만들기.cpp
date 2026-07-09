#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int start=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]==' '){
            start=0;//공백을 만나면 시작 인덱스 0으로 초기화 
            answer.push_back(' ');
        }
        else{
            if(start%2==0){
                answer.push_back((char)toupper(s[i]));
            }
            else {
                answer.push_back((char)tolower(s[i]));
            }
            start++;
        }
    }
    return answer;
}