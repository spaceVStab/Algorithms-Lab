#include <bits/stdc++.h>
using namespace std;

int BFS(vector<vector <int>> & g,int s,int n, int n1, int n2){
	int level[n],t=0;
	bool visit[n];
	queue <int> q;
	q.push(s);
	level[s] = 0;
	visit[s] = true;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		for(int i=0;i<(g[p].size());i++){
			if(visit[(g[p][i])] == false){
				level[(g[p][i])] = level[p] +1;
				t = n1;
				while(t<n1+n2){
					if(g[p][i] == t){
						//cout << "i m here" << level[g[p][i]]<< endl;
						return(level[g[p][i]]);
					}
					else{
						t++;
					}
				}
				q.push(g[p][i]);
				visit[g[p][i]] = true;
			}
			else{
				t = n1;
				while(t<n1+n2){
					if(g[p][i] == t){
						//cout << "i m here" << level[g[p][i]]<< endl;
						return(level[g[p][i]]);
					}
					else{
						t++;
					}
				}
			}
		}
	}
	return(-1);
}

void computedist1(vector< vector <int> > & g,int n,int n1,int n2){
	int temp = 0,min=10000;
	for(int i=0;i<n1;i++){
		temp = BFS(g,i,n,n1,n2);	
		if(temp == -1){
			cout << "BFS-" << i << "  returns INFINITY" << endl;
		}
		else{
			if(min > temp){
				min = temp;
			}
			cout <<"BFS-"<<i<<"  returns "<<temp<<endl;
		}
	}
	cout << endl <<"d(V1,V2) - "<<min<<endl;
	return;
}

int main(){
	int n,m,n1,n2,x,y;
	cin >> n >> m;
	cin >> n1 >> n2;
	vector< vector <int> > adj;
	adj.resize(n);
	for(int i=0;i<m;i++){
 		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		//adj.push_back(temp);
	}
	cout <<endl<< "n " << n <<endl;
	cout << "m " << m <<endl;
	cout << "n1 " << n1 <<endl;
	cout << "n2 " << n2 <<endl;
	for(int i=0;i<n;i++){
		cout <<endl<< "for " << i << " : ";
		for(int j=0;j<adj[i].size();j++){
			cout << adj[i][j] << "  ";
		}
	}
	cout << endl<<endl;
	computedist1(adj, n,n1,n2);
	return 0;
}