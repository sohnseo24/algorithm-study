#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    int N=nums.size();
    unordered_set<int> s(nums.begin(), nums.end());
    int count=s.size();
    if(count<=N/2){
        return count;
    }
    else{
        return N/2;
    }
}