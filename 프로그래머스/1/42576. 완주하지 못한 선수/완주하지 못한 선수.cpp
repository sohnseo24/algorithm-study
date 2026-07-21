#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> m;
    for(int i=0; i<completion.size(); i++){
        m[completion[i]]+=1; //=1이 아니라 +=1로 해야 동명이인도 또 한번 카운트가 됨. 
    }
    for(int i=0; i<participant.size(); i++){
        m[participant[i]]-=1;//여기서 장점이 드러나는구나: m에 그 이름이 없어도 이렇게 하면 0으로 초기화 된 후 자동으로 -1처리가 되네 
    }
    for(auto const& pair : m){
        if(pair.second<0){
            return pair.first;
        }
    }
}