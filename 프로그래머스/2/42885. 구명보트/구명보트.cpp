#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int count = 0;
    int left=0;
    sort(people.begin(), people.end());
    int right=people.size()-1;
    while(left<=right){
        if(people[left]+people[right]<=limit){
            count++;
            left++;
            right--;
        }
        else{//수가 넘어간다면 그 R포인터가 가리키는 애는 혼자 타야함.그리고 R포인터를 아래로 
            count++;
            right--;
        }
    }
    return count;
}