#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long s1=0;
    long long s2=0; 
    //각 합 구하기 
    for(int i=0; i<queue1.size(); i++){
        s1+=queue1[i];
        s2+=queue2[i];
    }
    //예외처리
    if((s1+s2)%2!=0){
        return -1;
    }
    int count=0;
    int idx1=0;
    int idx2=0; 
    int limit=4*queue1.size();//시간초과-> while문 안에서 할때마다 계산하면 시간초과임-> while문 밖으로 빼서 해결 
    while(s1!=s2){
        if(count>=limit){
            return -1;
        }
        if(s1>s2){
            queue2.push_back(queue1[idx1]); 
            s1-=queue1[idx1];s2+=queue1[idx1];
            count++;
            idx1++;//맨 앞의 원소가 삭제되었으므로 인덱스를 1증가시킨다
        }
        else {
            queue1.push_back(queue2[idx2]);
            s2-=queue2[idx2];s1+=queue2[idx2];
            count++;
            idx2++;
        }
    }
    return count;
}