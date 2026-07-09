#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for(int i=l; i<=r; i++){
        bool flag=true;//깃발변수는 루프 내에 있어야 함 
        string str=to_string(i);
        for(char v: str){
            if(v!='0' && v!='5'){
                flag=false;
                break;//여기서 break를 하지 않으면 15일 때 5에서 다시 true가 된다.
            }
        }
        //검사가 끝난 후 넣을 수 있음
        if(flag==true){
            answer.push_back(i);
        }
    }
    
    if(answer.size()>0){
        sort(answer.begin(),answer.end());
    }
    else{
        answer.push_back(-1);
    }
    return answer;
}