#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    priority_queue<int> pq;
    for(int i=0; i<priorities.size(); i++){
        pq.push(priorities[i]);
    }
    
    queue<pair<int,int>> qe;
    for(int i=0; i<priorities.size(); i++){
        qe.push({i,priorities[i]});
    }
    
    while(!qe.empty()){
        pair<int,int> front=qe.front();
        qe.pop();
        
        if(front.second<pq.top()){
            qe.push(front);
        }
        else if(front.second==pq.top()){
            pq.pop();
            answer++;
            if(front.first==location){
                return answer; 
            }
        }
    }
    return answer;
}