#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0; i<commands.size(); i++){//commands의 명령에 순서대로 돌입 
        
        int start=commands[i][0]-1;
        int end=commands[i][1];
        int k=commands[i][2]-1;
        
        vector<int> temp(array.begin()+start, array.begin()+end);
        //정렬
        sort(temp.begin(), temp.end());
        
        //이 array에서 원하는 인덱스의 숫자 뽑아 answer에 삽입
        answer.push_back(temp[k]);
    }
    return answer;
}