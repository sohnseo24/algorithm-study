#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int sum=0; 
    for(int i=0; i<10; i++){
        bool flag=false;
        for(int j=0; j<numbers.size(); j++){
            if(numbers[j]==i){
                flag=true;
            }
        }
        if(flag==false){
            sum+=i;
        }
    }
    return sum;
}