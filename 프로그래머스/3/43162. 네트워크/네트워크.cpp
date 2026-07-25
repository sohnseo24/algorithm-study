#include <string>
#include <vector>

using namespace std;
void dfs(int node, int n, vector<vector<int>>& computers, vector<int>& v){
    v[node]=0;//현재 노드를 0으로 만들기
    for(int next_node=0; next_node<n; next_node++){
        if(computers[node][next_node]==1 && v[next_node]==1){
            //연결되어있고(1) && 나자신이 아닌동시에(위에서 현재노드0으로 만들었으니 1이면 다른노드) 아직 다른 네트워크에 포함되지 않은 노드 => dfs를 통해 그 노드에 대해서 탐색!
            dfs(next_node, n, computers, v);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer=0;
    vector<int> v(n,1);
    for(int i=0; i<n; i++){
        if(v[i]==1){//새로운 네트워크 발견 
            answer++;
            dfs(i,n,computers,v);
        }
    }
    return answer;
}