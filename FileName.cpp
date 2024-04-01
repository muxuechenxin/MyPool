#include<iostream>
#include<string>
using namespace std;
int N, M;
int ne[100010];
void getNext(string n) {
    ne[0] = 0;
    int j = 0;
    for (int i = 1; i < N; i++) {
        while (j > 0 && n[i] != n[j]) j = ne[j - 1];
        if (n[i] == n[j]) j++;
        ne[i] = j;
    }
}
int main() {
    string n, m;
    cin >> N >> n >> M >> m;
    getNext(n);
    for (int i = 0, j = 0; i < M; i++) {
        while (j > 0 && m[i] != n[j]) j = ne[j - 1];
        if (m[i] == n[j]) j++;
        if (j == N) {
            j = ne[j - 1];
            cout << i - N + 1 << " ";
        }
    }
}