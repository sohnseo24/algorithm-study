#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int n=dungeons.size();
    vector<int> v;//순열을 돌려야 하니까(문자열/벡터)에만 가능 
    for(int i=0; i<n; i++){
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    int max=0;
    do{
        int current_k=k;
        int sum=0;
        for(int i=0; i<n; i++){
            if(current_k>=dungeons[v[i]][0]){
                current_k-=dungeons[v[i]][1];
                sum++;
            }
            else{
                break;
                }
        }
        if(max<=sum){
            max=sum;
        }
    }while(next_permutation(v.begin(), v.end()));
    return max;
}