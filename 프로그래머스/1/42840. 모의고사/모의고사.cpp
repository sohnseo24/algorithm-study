#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> p1 = {1, 2, 3, 4, 5}; // 길이 5
    vector<int> p2 = {2, 1, 2, 3, 2, 4, 2, 5}; // 길이 8
    vector<int> p3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}; // 길이 10
    int s1=0;
    int s2=0;
    int s3=0;
    for(int i=0; i<answers.size(); i++){
        if(answers[i]==p1[i%p1.size()]){s1++;}
        if(answers[i]==p2[i%p2.size()]){s2++;}
        if(answers[i]==p3[i%p3.size()]){s3++;}
    }
    int max_score=max({s1,s2,s3});
    if(max_score==s1){answer.push_back(1);}
    if(max_score==s2){answer.push_back(2);}
    if(max_score==s3){answer.push_back(3);}
    return answer;
}