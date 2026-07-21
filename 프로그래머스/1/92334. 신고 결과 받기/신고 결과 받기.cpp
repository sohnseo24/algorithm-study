#include <string>
#include <vector>
#include <sstream> 
#include<unordered_map>
#include<unordered_set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    unordered_map<string, unordered_set<string>> singo;
    unordered_map<string, int> count; 
    unordered_map<string, int> mail_count;//여기에서 id별 인덱스 위치를 저장하고, 각 ID별로 결과메일 수를 몇개 받았는지 저장할 것임 
    for(int i=0; i<report.size(); i++){
        stringstream ss(report[i]);
        string reporter, reported;
        ss>> reporter>> reported; 
        
        singo[reporter].insert(reported);
        //count[reported]+=1;//얘를 여기서 더하면 중복해서 들어갈 수 있겠네.. 차라리 다 된 singo에서 set에서 이름이 등장할 때마다 +1해줘야 하나? 
    }
    for(auto const& pair: singo){//다된 set에서 이름이 등장할 때마다+1하기 
        for(auto const& name: pair.second){//이렇게 set으로 들어가 순회할 수 있구나!
            count[name]+=1;
        }
    }
    for(auto const& pair: singo){
        string reporter=pair.first;
        int num=0;
        for(auto const& reported: pair.second){
            if(count[reported]>=k){
                num++;
            }
            mail_count[reporter]=num;
        }
    }
    for(int i=0; i<id_list.size(); i++){
        answer.push_back(mail_count[id_list[i]]);
    }
    return answer;
}