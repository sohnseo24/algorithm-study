#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for(int i = 0; i < s.length(); i++){
        char c = s[i]; 
        if(c >= 'A' && c <= 'Z'){//대문자
            c = (c - 'A' + n) % 26 + 'A';
        }
        else if(c >= 'a' && c <= 'z'){//소문자
            c = (c - 'a' + n) % 26 + 'a';
        }
        
        answer.push_back(c);
    }
    return answer;
}