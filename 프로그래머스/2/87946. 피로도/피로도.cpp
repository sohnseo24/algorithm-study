#include <string>
#include <vector>
using namespace std;
int answer=0;//전역변수로 최댓값 저장 
void dfs(int n, int k, vector<int>& v, const vector<vector<int>>& dungeons,int count){
    answer=max(answer,count);//매 재귀마다 현재까지 탐색한 던전수로 최댓값 갱신 
    for(int i=0; i<n; i++){
        if(v[i]==1 && k>=dungeons[i][0]){//아직 방문하지 않았고 갈 수 있는 던전이라면  
            v[i]=0;//방문처리
            dfs(n, k-dungeons[i][1], v, dungeons, count+1);//재귀호출
            v[i]=1;//원상복구(백트레킹)
        }
        
    }
}
int solution(int k, vector<vector<int>> dungeons) {
    answer=0;//전역변수 초기화를 해주어야 함!
    int n=dungeons.size();
    vector<int> visited(n,1);
    dfs(n, k, visited, dungeons, 0);//0으로 시작 
    return answer;//최종 최댓값 반환 
}