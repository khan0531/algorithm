#include <bits/stdc++.h>

using namespace std;

int n, w, L; // 트럭수, 다리 길이, 다리 최대 하중
int cnt;
int br[101];
queue<int> q;
int t;

int sum(){
    int sum = 0;
    for (int i = 0; i < w; i++) {
        sum += br[i];
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> w >> L;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;  // 7 4 5 6
        q.push(a);
    }

    while(!q.empty()){
        int temp = sum();
        
        if (temp <= L) {
            temp -= br[w -1];

            for (int i = w; i > 0; i--) {
                br[i] = br[i - 1];
            }
            br[0] = 0;

            if (!q.empty() && temp + q.front() <= L) {
                br[0] = q.front();
                q.pop();
            }
        }

        t++;
    }

    cout << t + w;    
}