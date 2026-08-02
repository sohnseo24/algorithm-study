#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<string,string> in_map;//차번호-들어온 시간 저장용
    unordered_map<string,int> time_map;//차번호-누적시간 계산용 
    unordered_map<string,string> status_map;//차번호-상태(나중에 IN만 있고 OUT이 없는 차들을 걸러내기 위해서)
    for(int i=0; i<records.size(); i++){
        string record=records[i];
        stringstream ss(record);
        string time, car_num, status;
        ss>>time>>car_num>>status;
        
        if(status=="IN"){
            status_map[car_num]="IN";
            in_map[car_num]=time;
        }
        else{
            status_map[car_num]="OUT";
            //누적시간 계산 
            int in_h=stoi(in_map[car_num].substr(0,2));
            int in_m=stoi(in_map[car_num].substr(3,2));
            int out_h=stoi(time.substr(0,2));
            int out_m=stoi(time.substr(3,2));
            int minutes=(out_h-in_h)*60+(out_m-in_m);
            time_map[car_num]+=minutes;
        }        
    }
    //주차 요금 계산 
    //1단계: 번호의 크기 따지기 
    vector<string> cars;//먼저 번호만 벡터에 넣는다 
    for(const auto& pair:in_map){
        cars.push_back(pair.first);
    }
    sort(cars.begin(), cars.end());//그걸 정렬하면 크기 순으로 정렬된다
    //2단계: 아직 IN인 차들 걸러내기(OUT이 되지 않아 아직 누적합에 반영안된것 처리)
    for(int i=0; i<cars.size(); i++){
        if(status_map[cars[i]]=="IN"){
            time_map[cars[i]]+=(23-stoi(in_map[cars[i]].substr(0,2)))*60+(59-stoi(in_map[cars[i]].substr(3,2)));
        }
    }
    //3단계: 계산하기 
    for(int i=0; i<cars.size(); i++){
        if(time_map[cars[i]]<=fees[0]){//기본요금 
            answer.push_back(fees[1]);
        }
        else{//기본시간을 초과 했을 때 
            answer.push_back(fees[1]+ceil((double)(time_map[cars[i]]-fees[0])/fees[2])*fees[3]);
        }
    }
    
    return answer;
}