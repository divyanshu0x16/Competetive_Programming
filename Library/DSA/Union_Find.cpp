#include <bits/stdc++.h>

using namespace std;

int n;
int parent[1000000];
int size[1000000];
void make_seat(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(v==parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b ){
    a= find_set(a);
    b = find_set(b);
    if(a!=b){
        if(size[a] < size[b])
            swap(a,b);
        parent[b] = a;
        size[a] += size[b];
    }
}

int main(){
    return 0;
}