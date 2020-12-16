#include <iostream>
#include <bits/stdc++.h>
using namespace std;
 
 void solve(vector<int> arr) {
   vector<int> res;
   priority_queue <int, vector<int>, less<int> > heap;
    for (int i = 0; i < (int) arr.size(); ++i) {
      heap.push(arr[i]);
    }
    if (heap.size() <= 2) cout << "Size too small \n";
    else {
      heap.pop();
      heap.pop();
      while (!heap.empty()) {
        res.push_back(heap.top());
        heap.pop();
      }
      sort(res.begin(), res.end());
      for (int i = 0; i < (int) res.size(); ++i) cout << res[i] << " ";
    }
 }

int main() {
  int n;
  cin >> n;
  while (n--) {
    cout << "\n";
    int k;
    cin >> k;
    vector<int> arr;
    for (int i = 0; i < k; ++i) {
      int ele;
      cin >> ele;
      arr.push_back(ele);
    }   
    solve(arr);  
  }
  return 0;
}