#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    string A= to_string(a)+to_string(b);
    int numB=2*a*b;
    int numA=stoi(A);
    if (numA>=numB){
        return numA;
    }
    else{
        return numB;
    }
}