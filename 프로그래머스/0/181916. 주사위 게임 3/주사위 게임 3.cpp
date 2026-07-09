#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer;
    vector<int> arr={a, b, c, d};
    set<int> s={a,b,c,d};
    
    sort(arr.begin(), arr.end());
    
    if(s.size()==1){
        answer=1111*a;
    }
    else if(s.size()==2){
        //CASE1)세 주사위에서 나온 숫자가 같은 경우 
        if(arr[0]==arr[2]){
            answer=pow(10*arr[0]+arr[3],2);
        }
        else if(arr[1]==arr[3]){
            answer=pow(10*arr[3]+arr[0],2);
        }
        //CASE2)두개씩 같은 값이 나온 경우 
        else{
            int p=arr[0];
            int q=arr[2];
            answer=(p+q)*abs(p-q);
        }
    }
    else if(s.size()==3){
        if(arr[0]==arr[1]){answer=arr[2]*arr[3];}
        if(arr[1]==arr[2]){answer=arr[0]*arr[3];}
        if(arr[2]==arr[3]){answer=arr[1]*arr[0];}
            
        }
    else{
        answer=arr[0];
    }
    
    return answer;
}