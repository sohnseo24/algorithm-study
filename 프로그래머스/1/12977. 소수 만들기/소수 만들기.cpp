#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int count=0;
    //조합 구현하기
    for(int i=0; i<nums.size(); i++){
        for(int j=i+1; j<nums.size(); j++){
            for(int k=j+1; k<nums.size(); k++){
                bool isPrime= true;
                int sum=0;
                sum=nums[i]+nums[j]+nums[k];
                //소수인지 판별하기 
                for(int m=2; m*m<=sum; m++){
                    if(sum%m==0){
                        isPrime=false;
                    }
                }
                if(isPrime==true){
                    count++;
                }
            }
        }
    }
    return count;
}