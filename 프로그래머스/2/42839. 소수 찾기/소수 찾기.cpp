#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
using namespace std;
bool isPrime(int n){
    bool isPrime=true;
    if(n<2){isPrime=false;}
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0){
            isPrime=false;
        }
    }
    return isPrime;
}
int solution(string numbers){
    vector<int> answer;
    sort(numbers.begin(), numbers.end());
    do{
        for(int i=1; i<=numbers.size(); i++){
            int k=stoi(numbers.substr(0, i)); 
            if(isPrime(k)){
                answer.push_back(k);
            }
        }
        
    }while(next_permutation(numbers.begin(), numbers.end()));
           
    set<int> set_answer(answer.begin(), answer.end());
              
    return set_answer.size();
}