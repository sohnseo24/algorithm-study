#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left=1;
    int right=distance;
    
    sort(rocks.begin(), rocks.end());
    while(left<=right){
        int mid=(left+right)/2;
        int remove_count=0;
        int prev=0;
        for(int i=0; i<rocks.size(); i++){
            if(rocks[i]-prev <mid){
                remove_count++;
            }
            else{
                prev=rocks[i];
            }
        }
        if(distance-prev<mid){
            remove_count++;
        }
        
        if(remove_count<=n){
            answer=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }
    return answer;
}