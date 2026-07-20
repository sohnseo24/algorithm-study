#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    for(int i=0; i<number.size(); i++){
        while(k>0 && !answer.empty() && answer.back()<number[i]){
            answer.pop_back();
            k--;
        }
        answer.push_back(number[i]);
    }
    if(k>0){//예외적인 상황 처리 
        answer=answer.substr(0,answer.size()-k);
    }
    return answer;
}