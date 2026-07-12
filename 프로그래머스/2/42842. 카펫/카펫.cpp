#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total=brown+yellow;
    int w,h;
    for(h=3; h<=total; h++){
        if(total%h==0){
            w=total/h;
            if(yellow==(w-2)*(h-2)){
                answer.push_back(w);
                answer.push_back(h);
                return answer;
            }
        }
    }
}