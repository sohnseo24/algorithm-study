#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    int n=maps[0].size();//열개수(가로)
    int m=maps.size();//행개수(세로)
    
    queue<pair<int, int>> idx;
    idx.push({0,0});
    
    vector<int> dx={-1,+1,0,0};//좌우
    vector<int> dy={0,0,-1,+1};//상하
    
    while(!idx.empty()){
        int x=idx.front().first;
        int y=idx.front().second;
        idx.pop();
        
        for(int i=0; i<4; i++){//이렇게 하면 상하좌우로 움직이는 좌표를 나타낼 수 있겠구나
            int nx=x+dx[i];
            int ny=y+dy[i];
            
            if(nx>=0&&nx<n && ny>=0&&ny<m && maps[ny][nx]==1){//맵 밖으로 안벗어나고 가본적 없는 곳이면 
                maps[ny][nx]=maps[y][x]+1;
                idx.push({nx,ny});//큐에 새로운 위치 삽입
            }       
        }
    }
    if(maps[m-1][n-1]==1){
        return -1;
    }
    else{
        return maps[m-1][n-1];
    }
}