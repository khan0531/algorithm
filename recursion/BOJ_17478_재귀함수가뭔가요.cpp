#include <bits/stdc++.h>

using namespace std;

vector<string> rec = {
    "\"재귀함수가 뭔가요?\"",
    "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.",
    "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.",
    "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\""
};
string ans = "라고 답변하였지.";
vector<string> s = {
    "____\"재귀함수가 뭔가요?\"",
    "____\"재귀함수는 자기 자신을 호출하는 함수라네\"",
    "____라고 답변하였지."
};

vector<string> func(int N){
    vector<string> v;
    if (N == 1){
        for (string str : rec){
            v.push_back(str);
        }

        for (string str : s){
            v.push_back(str);
        }
        
        v.push_back(ans);

        return v;
    }
    
    for (string str : rec){
        v.push_back(str);
    }

    for (string str : func(N - 1)){
        v.push_back("____" + str);
    }

    v.push_back(ans);

    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;

    cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다." << '\n';
    
    for (string str : func(N)) {
        cout << str << '\n';
    }
}
