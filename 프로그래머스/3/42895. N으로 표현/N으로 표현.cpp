#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    unordered_set<int> DP[9];//주머니 만들기
    for(int i=1; i<9; i++){
        //이어붙인 숫자 넣기 
        int num=0;
        for(int j=0; j<i; j++){
            num=num*10+N;
        }
        DP[i].insert(num);
        //사칙 연산 하기
        for(int j=1; j<i; j++){
                for(int a: DP[j]){
                    for(int b: DP[i-j]){
                        if(b!=0){
                            DP[i].insert(a/b);
                        }
                        DP[i].insert(a*b);
                        DP[i].insert(a+b);
                        DP[i].insert(a-b);
                    }
                }
            }
        
        //검사하기 
        if(DP[i].count(number)){
            return i;
        }
    }
    return -1;
}