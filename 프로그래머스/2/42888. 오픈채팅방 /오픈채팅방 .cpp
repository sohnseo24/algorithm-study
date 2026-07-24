#include <string>
#include <vector>
#include <sstream>
#include <unordered_map> 
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> uId;
    vector<pair<string, string>> comeNgo; //이렇게 저장하면 몇번째 순서의 문자열인지 알 수 있을 뿐만 아니라 string에 Enter인지 Leave인지 저장할 수 있어 순서대로 출력 가능할 것.
    
    for(int i=0; i<record.size(); i++){
        //1. 각 문자열 읽기 
        stringstream ss(record[i]);
        string command, id, name;
        ss>> command>> id;
        
        if(command!="Leave"){
            ss>> name;
        }
        //2. 그 문자열에서 Enter, Leave, Change인 경우 분류하기 
        if(command=="Enter"){
            uId[id]=name;
            comeNgo.push_back({id,command});//출입정보 저장 
        }
        else if(command=="Change"){
            uId[id]=name;
        }
        else{//Leave의 경우 
            comeNgo.push_back({id,command});//출입정보 저장 
        }
    }
    //3. for문으로 record를 다 돌았으니 이제 출력을 한다. 
    for(int i=0; i<comeNgo.size(); i++){
        string id= comeNgo[i].first;
        string name=uId[id];
        string command=comeNgo[i].second;
        if(command=="Enter"){
            answer.push_back(name+"님이 들어왔습니다.");
        }
        else{
            answer.push_back(name+"님이 나갔습니다.");
        }
    }
    return answer;
}