#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());
    
    long long left = 1; 
    long long right = (long long)times.back() * n;
    
    long long answer = right;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        
        long long total_people = 0; 
        for (int time : times) {
            total_people += mid / time;
        }
        
        if (total_people >= n) {
            answer = mid;
            right = mid - 1;
        } 
        else {
            left = mid + 1; 
        }
    }
    
    return answer;
}