#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 vector<int> solve(int l, int r) {
   vector<int> res;
   for (int i = l ; i <= r ; i++) { 
        int num = i; 
        bool visited[10] = {false}; 
        while (num){ 
            if (visited[num % 10]) break; 
            visited[num % 10] = true; 
            num = num / 10; 
        } 
        if (num == 0) {
          cout << i << " "; 
          res.push_back(i);
        }
    }
    return res;
 }

int main() {
  int l ,r;
  cin >> l >> r;
  solve(l, r);

  return 0;
}