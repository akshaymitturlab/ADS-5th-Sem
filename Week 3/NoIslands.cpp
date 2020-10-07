#include<bits/stdc++.h>
using namespace std;

class Union {
	vector<int> parent;

	public:
	int count;
	Union (int n) {
		for(int i = 0; i < n; i++) parent.push_back(i);
		count = 0;
	}

	int find (int x){
		if(parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}

	void connect(int x, int y){
		int rootx = find(x);
		int rooty = find(y);
		if(rootx != rooty){
			parent[rootx] = rooty;
			count--;
		}
		
	}
	void setCount(int n){
		count = n;
	}

};

int Islands(vector<vector<int> > arr) {
	int count = 0;
	int m = arr.size();
	int n = arr[0].size();
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j]) count++;
		}
	}
	Union *uf = new Union(m * n);
	uf -> setCount(count);

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(arr[i][j]){
				if(i > 0 && arr[i - 1][j]) uf -> connect(n * i + j, n * (i - 1) + j);

				if(i < m - 1 && arr[i + 1][j]) uf -> connect(n * i + j, n * (i + 1) + j);

				if(j > 0 && arr[i][j - 1]) uf -> connect(n * i + j, n * i + j - 1);

				if(j < n - 1 && arr[i][j + 1]) uf -> connect(n * i + j, n * i + j + 1);

				if(i > 0 && j > 0 && arr[i - 1][j - 1]) uf -> connect(n * i + j, n * (i - 1) + j - 1);

				if(i < m - 1 && j < n - 1 && arr[i + 1][j + 1])uf -> connect(n * i + j, n * (i + 1) + j + 1);

				if(i>0 && j<n-1 && arr[i-1][j+1]) uf -> connect(n * i + j, n * (i - 1) + j + 1);

				if(i < m - 1 && j > 0 && arr[i + 1][j - 1]) uf -> connect(n * i + j, n * (i + 1) + j - 1);
			}
				
		}
	}
	return uf -> count;
}

int main(){
	int m, n, val;
	cin >> m >> n;
  vector<vector<int> > arr(m , vector<int> (n, 0));

	cout << "Enter the Adjacency Matrix" << endl;
	for(int i = 0;i < m; i++){
		for(int j = 0; j < n; j++){
			cin >> val;
			arr[i][j] = val;
		}
	}

	cout<<"Number of Islands: "<< Islands(arr) << endl;
	return 0;
}