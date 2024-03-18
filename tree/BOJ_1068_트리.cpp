#include <iostream>
#include <vector>
using namespace std;

vector<int> children[51]; // 각 노드의 자식 노드들을 저장할 벡터 배열
bool deleted[51]; // 노드가 삭제되었는지 여부를 저장할 배열
int n, delNode, root, leafCount = 0;

void dfs(int node) {
    if (deleted[node]) return; // 삭제된 노드는 탐색하지 않음
    if (children[node].empty() || (children[node].size() == 1 && deleted[children[node][0]])) {
        // 리프 노드인 경우, 또는 유일한 자식 노드가 삭제된 경우
        leafCount++;
        return;
    }
    for (int child : children[node]) {
        dfs(child);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int parent;
        cin >> parent;
        if (parent == -1) {
            root = i; // 루트 노드 설정
        } else {
            children[parent].push_back(i); // 부모 노드에 자식 노드 추가
        }
    }
    cin >> delNode;
    deleted[delNode] = true; // 삭제할 노드 표시
    
    // 삭제할 노드가 루트 노드인 경우를 대비한 처리
    if (delNode == root) {
        cout << 0 << endl;
        return 0;
    }

    dfs(root); // 루트 노드부터 DFS 탐색 시작
    cout << leafCount << endl; // 리프 노드의 개수 출력
    return 0;
}
