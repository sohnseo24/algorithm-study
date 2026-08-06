#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1;

    vector<unordered_set<int>> DP(9);

    int temp = 0;
    for (int i = 1; i <= 8; i++) {
        temp = temp * 10 + N;
        DP[i].insert(temp);
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j < i; j++) {
            for (int a : DP[j]) {
                for (int b : DP[i - j]) {
                    DP[i].insert(a + b);
                    DP[i].insert(a - b);
                    DP[i].insert(a * b);
                    
                    if (b != 0) {
                        DP[i].insert(a / b);
                    }
                }
            }
        }
        
        if (DP[i].count(number)) {
            return i;
        }
    }

    return -1;
}