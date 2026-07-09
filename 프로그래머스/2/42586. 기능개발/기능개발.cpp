#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> qe;
    for(int i=0; i<progresses.size(); i++){
        int remain=100-progresses[i];
        int day=(remain+speeds[i]-1)/speeds[i]; 
        qe.push(day);
    }
    
    while(!qe.empty()){
        int daysum=0;
        int n=qe.front();
        daysum+=1;
        int m=qe.front();
        if(m<=n){
            daysum+=1;
            m=qe.pop();
        }
        answer.push_back(daysum);
    }
    return answer;
}