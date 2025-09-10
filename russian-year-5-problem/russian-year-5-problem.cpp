#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  unordered_map<int,int> umap;

  for(int i = 1; i <= n; i++){
    int a;
    scanf("%d", &a);

    int sisa = 100 - a;
    if(umap.find(sisa) != umap.end()){
      printf("%d\n", umap[sisa]);
      printf("%d\n", i);
      return 0;
    }

    umap[a] = i;
  }
}
