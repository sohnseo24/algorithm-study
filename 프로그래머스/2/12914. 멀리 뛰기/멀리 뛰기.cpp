#include <string>
#include <vector>

using namespace std;
long long solution(int n) {
    vector<int> dp(n+1); //n번째 칸까지 가는 방법을 세야 하므로 
    dp[0]=0;
    dp[1]=1;//첫번째 칸까지 가는 방법의 수는 1개 
    dp[2]=2;//두번째 칸까지 가는 방법의 수는 2개
    for(int i=3; i<=n; i++){
        dp[i]=(dp[i-1]+dp[i-2])%1234567;
    }
    
    return dp[n];
}