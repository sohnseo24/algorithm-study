#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    vector<int> answer;
    int k=0;
    while(answer!=arr){
        answer=arr; //여기에 복사해놓는다.
        for(int i=0; i<arr.size(); i++){
            if (arr[i]>=50 && arr[i]%2==0){
                arr[i]=arr[i]/2;
            }
            else if(arr[i]<50 && arr[i]%2!=0){
                arr[i]=arr[i]*2+1;
            }
        }
        k++;
    }
    return k-1;
}