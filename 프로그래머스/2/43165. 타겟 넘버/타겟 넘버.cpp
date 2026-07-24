#include <string>
#include <vector>
using namespace std;
int answer = 0;
void dfs(const vector<int>& numbers, int target, int index, int sum){
    if(index==numbers.size()){//종료조건 
        if(sum==target){
            answer++;
        }
        return;
    }
    //다음단계 호출(두단계 갈라치기)
    dfs(numbers, target, index+1, sum+numbers[index]);//더하는 경우 
    dfs(numbers, target, index+1, sum-numbers[index]);//빼는 경우 
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    dfs(numbers, target, 0, 0);
    return answer;
}