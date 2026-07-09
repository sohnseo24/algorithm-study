#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    for(int i=0; i<numbers.size(); i++){
        for(int j=0; j<numbers.size(); j++){
            if(i!=j){//i와 j가 같지 않은 경우에만 수행해야 함.서로 다른 인덱스여야 하기 때문
                int sum= numbers[i]+numbers[j];
                
                int flag=true;
                for(int k=0; k<answer.size(); k++){
                    if(sum==answer[k]){
                        flag=false;
                    }
                }
                if(flag==true){
                    answer.push_back(sum);
                }
            }
        }
    }
    sort(answer.begin(), answer.end());//오름차순 정렬 
    return answer;
}