#include <string>
#include <vector>
#include <queue>
using namespace std;
bool isSimillar(string w1, string w2){//두개의 글자가 한글자 제외 다 같은지 판별
    int diff_count=0;
    for(int i=0; i<w1.size(); i++){
        if(w1[i]!=w2[i]){
            diff_count++;
        }
    }
    return diff_count==1;
}

int solution(string begin, string target, vector<string> words) {
    int n=words.size();
    int i=0;
    //target이 words에 없는 경우 걸러내기 
    bool flag=false;
    while(i<n){
        if(target==words[i]){
            flag=true;
            break;
        }
        i++;
    }
    if(flag==false){
        return 0;
    }
    //BFS구현 
    queue<pair<string,int>> q;//BFS구현용
    vector<int> visited(n,1);//방문체크용
    q.push({begin,0});
    while(!q.empty()){
        if(q.front().first==target){//만약 내가 찾는 값이 나오면 
            return q.front().second;//그때의 카운트를 반환 
        }
    
        for(int i=0; i<n; i++){
            if(isSimillar(q.front().first,words[i])==true && visited[i]!=0){
                q.push({words[i],q.front().second+1});
                visited[i]=0;
            }
        }
        q.pop();
    }
}