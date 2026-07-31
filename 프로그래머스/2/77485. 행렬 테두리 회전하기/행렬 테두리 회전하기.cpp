#include <string>
#include <vector>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    //행렬 만들기 
    vector<vector<int>> matrix(rows+1, vector<int>(columns+1, 0)); 
    int num=1;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            matrix[i][j]=num++;
        }
    }
    //회전시키기
    for(int i=0; i<queries.size(); i++){
        int a=queries[i][0];
        int b=queries[i][1];
        int c=queries[i][2];
        int d=queries[i][3];
        
        int temp=matrix[a][b];//맨 첫값 백업 
        int min_val=temp;//최솟값 
        //왼쪽 변
        for(int j=a; j<c; j++){
            matrix[j][b]=matrix[j+1][b];
            min_val=min(min_val, matrix[j][b]);
        }
        //아래쪽 변 
        for(int j=b; j<d; j++){
            matrix[c][j]=matrix[c][j+1];
            min_val=min(min_val, matrix[c][j]);
        }
        //오른쪽 변
        for(int j=c; j>a; j--){
            matrix[j][d]=matrix[j-1][d];
            min_val=min(min_val, matrix[j][d]);
        }
        //위쪽 변
        for(int j=d; j>b; j--){
            matrix[a][j]=matrix[a][j-1];
            min_val=min(min_val, matrix[a][j]);
        }
        matrix[a][b+1]=temp;
        //그 안에서 가장 작은 수 찾아 벡터에 저장하기 
        answer.push_back(min_val);
    }
    return answer;
}