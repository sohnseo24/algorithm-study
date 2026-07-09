#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int min=*min_element(arr.begin(),arr.end());
    arr.erase(min_element(arr.begin(),arr.end()));
    
    if(arr.size()==0){
        answer.push_back(-1);
    }
    else{
        answer=arr;
    }
    return answer;
}