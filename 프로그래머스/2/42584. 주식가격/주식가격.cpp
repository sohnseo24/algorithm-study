#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int prices_size=prices.size();
    vector<int> answer(prices_size,0);
    stack<int> st;
    for(int i=0; i<prices_size; i++){
        while(!st.empty() && prices[st.top()]>prices[i]){//가격이 떨어진 경우.while로 처리하여 전부 다 검사할 수 있도록 한다. 
            answer[st.top()]=i-st.top();
            st.pop();
        }
        st.push(i);//가격이 안 떨어진 경우, 그냥 넣는다. 
    }
    while(!st.empty()){//여전히 남아있는 경우= 가격이 떨어진 적이 없는 경우 
        int k=st.top();
        answer[k]=prices_size-1-k;
        st.pop();
    }

    return answer;
}