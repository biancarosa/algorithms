#define MAX 1000
#include <iostream>
 
using namespace std;
 
void init(int n) {
    for (int i = 1; i <= n; ++i) uptree[i] = i;
}
 
int find(int p) {
    if (uptree[p] != p) {
        uptree[p] = find(uptree[p]);
    }
    return uptree[p];
}
 
 
void Union(int p, int q) {
    find(p); find(q);
    if (uptree[p] > uptree[q]) {
        uptree[uptree[p]] = uptree[q];
    } else {
        uptree[uptree[q]] = uptree[p];
    }
}
 
 
int main() {
    int n, m, c, u, v;
     
    cin >> n >> m;
     
    init(n);
 
    for(int i = 1; i <= m; ++i) {
        cin >> u >> v;
        Union(u,v);
    }
    for(int i = 1; i <= n; ++i) find(i);
 
    return 0;
}
