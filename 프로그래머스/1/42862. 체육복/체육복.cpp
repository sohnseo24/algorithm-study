#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> v(n,1);//n개의 1로 채워져있는 벡터 만들기 
    
    for(int j=0; j<lost.size(); j++){//-1빼기
        v[lost[j]-1]-=1;
    }
    for(int j=0; j<reserve.size(); j++){//+1더하기 
        v[reserve[j]-1]+=1;
    }
    for(int i=0; i<v.size(); i++){
        if(v[i]==2){
            if(i > 0 && v[i-1] == 0){
                v[i]-=1;
                v[i-1]+=1;
            }
            else if(i < v.size() - 1 && v[i+1] == 0){
                v[i]-=1;
                v[i+1]+=1;
            }
        }
    }
    //검사하기
    int sum=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]>0){
            sum++;
        }
    }
    return sum;
}