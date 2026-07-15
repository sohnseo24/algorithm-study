#include <string>
#include <vector>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> v;
    for(int i=1; i<=number; i++){
        int count=0;
        for(int j=1; j*j<=i; j++){
            if(i%j==0){
                if(j==i/j){
                    count+=1;
                }
                else{
                    count+=2;
                }
            }
        }
        v.push_back(count);
    }
    for(int i=0; i<v.size(); i++){
        if(v[i]>limit){
            answer+=power;
        }
        else{
            answer+=v[i];
        }
    }
    return answer;
}