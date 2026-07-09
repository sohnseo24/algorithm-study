#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    string jjak="";
    string hol="";
    for(int i=0; i<num_list.size(); i++){
        if(num_list[i]%2==0){
            jjak+=to_string(num_list[i]);
        }
        else{
            hol+=to_string(num_list[i]);
        }
    }
    int sum=stoi(jjak)+stoi(hol);
    return sum;
}