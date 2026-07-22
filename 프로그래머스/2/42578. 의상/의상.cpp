#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> map;
    for(int i=0; i<clothes.size(); i++){
        map[clothes[i][1]]+=1;
    }
    int sum=1;
    for(auto const& pair: map){
        sum*=(pair.second+1);
    }
    return sum-1;
}