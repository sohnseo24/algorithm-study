#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int max_h=0;
    int max_w=0;
    int h;
    int w;
    for(int i=0; i<sizes.size(); i++){
        //가로와 세로를 비교하여 더 큰걸 가로로 저장
        if(sizes[i][0]<sizes[i][1]){
            int w=sizes[i][0];
            int h=sizes[i][1];
            //최대 높이와 너비 구하기  
            if(max_w<=w){ 
                max_w=w;
            }
            if(max_h<=h){
                max_h=h;
            }
        }
        else{
            int w=sizes[i][1];
            int h=sizes[i][0];
            //최대 높이와 너비 구하기  
            if(max_w<=w){ 
                max_w=w;
            }
            if(max_h<=h){
                max_h=h;
            }
        }
    }
    answer=max_h*max_w;
    return answer;
}