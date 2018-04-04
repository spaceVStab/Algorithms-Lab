#include <bits/stdc++.h>
//#define inf 10000000
using namespace std;

int partition(int efforts[], int low, int high){
	int p = efforts[high],temp = 0, i =0;
	i = low - 1;
	for(int j=low;j<=high-1;j++){
		if(efforts[j]<=p){
			i++;
			temp = efforts[i];
			efforts[i] = efforts[j];
			efforts[j]= temp;
		}
	}
	temp = efforts[i+1];
	efforts[i+1] = efforts[high];
	efforts[high]= temp;
	return(i+1);

}

void quicksort(int efforts[], int low, int high){
	if(low<high){
		int part = partition(efforts, low, high);
		quicksort(efforts, low, part-1);
		quicksort(efforts, part+1, high);
	}
}

void solveGRD(int efforts[], int n, int M){
	quicksort(efforts, 0, n-1);
	int i = 0, sum =0;
	while(efforts[i]+sum <= M){	
		sum += efforts[i];
		i++;
	}
	cout << "\n Part 1 (Greedy) \n\nthe minimum effort will be\n"<<endl;
	cout << "minimum effort "<< sum <<endl;
	for(int j=0;j<i;j++){
		cout << efforts[j] << "  ";
	}
	cout << endl;
	return;

}

void solveDP(int p[],int m[],int n, int M, int P){
	int dpmatrix[n+2][P+2];
	int M0 = 0,M1=0;
	int sumtoi = 0;
	int inf = 100000;
	for(int i=0;i<=n;i++){
		dpmatrix[i][0] = 0;
	}
	for(int i=1;i<=P;i++){
		dpmatrix[0][i] = inf;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=P;j++){
			dpmatrix[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=P;j++){
			//compare the pi with p
			sumtoi = 0;
			// for(int k=0;k<i;k++){
			// 	sumtoi += p[k];
			// }
			// if(!(sumtoi==j)){
			// 	dpmatrix[i][j] = inf;
			// 	//cout << "case1"<<endl;
			// 	continue;
			// }
			if(j<p[i-1]){
				dpmatrix[i][j] = dpmatrix[i-1][j];
				//cout << "case2"<<endl;
			}
			else{
				M0 = dpmatrix[i-1][j];
				M1 = m[i-1] + dpmatrix[i-1][j-(p[i-1])];
				//cout << "MO" << M0 << "M1" << M1;
				if(M1>M){
					dpmatrix[i][j] = M0;
				}
				else{
					if(M0<=M1){
						dpmatrix[i][j] = M0;
					}
					else{
						dpmatrix[i][j] = M1;
					}
				}
			}
			//cout << dpmatrix[i][j];
		}
		//cout << endl;
	}
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=P;j++){
	// 		cout << dpmatrix[i][j] <<" ";
	// 	}
	// 	cout << endl;
	// }
	int max = 0;
	int maxP = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=P;j++){
			if((max < dpmatrix[i][j]) && (dpmatrix[i][j] < inf)){
				max = dpmatrix[i][j];
				maxP = j;
			}
		}
	}
	cout << "min effort " << max<<endl;
	cout << "max point " << maxP << endl; 
}



int main(){
	int n,M;
	cout<<"Enter n and M"<<endl;
	cin>>n>>M;
	int efforts[n+1];
	cout << "Enter the efforts m1,m2,..."<<endl;
	for(int i =0;i<n;i++){
		cin >> efforts[i];
	}
	solveGRD(efforts, n, M);
	int p[n+1], m[n+1],P=0;
	cout << "Part 2 DP solution" <<endl;
	cout << "Enter the points p1, p2,..." <<endl;
	for(int i =0;i<n;i++){
		cin >> p[i];
		P += p[i];
	}
	cout << "Enter the efforts m1,m2,..."<<endl;
	for(int i =0;i<n;i++){
		cin >> m[i];
	}
	solveDP(p,m,n,M,P);
}