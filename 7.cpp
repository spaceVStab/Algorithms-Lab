#include <bits/stdc++.h>
using namespace std;

int recur_sel(int *values, int t, int temp_sum, int level, int n){
	level+=1;
	if(level>n){
		return(temp_sum);
	}
	int l = temp_sum;
	int r = temp_sum + values[level-1];
	//cout << "before level l r"<< level<<l<<r<<endl;
	l=recur_sel(values, t, l,level,n);
	r=recur_sel(values, t, r,level,n);
	//cout << "after level l r"<< level<<l<<r<<endl;
	if(l<=t && r<=t){
		return(max(l,r));
	}
	if(l>t){
		return(r);
	}
	if(r>t){
		return(l);
	}
	return(0);
}

int exhs(int *values, int t, int n){
	int temp_sum = 0, level = 0;
	int sum = recur_sel(values, t, temp_sum, level,n);
	return(sum);
}

int** htinit(int s){
	int **temp;
	temp = (int **)malloc(sizeof(int *) * s);
	while(s--){
		temp[s] = NULL;
	}
	return(temp);



	// int temp[s][3];
	// for(int i=0;i<s;i++){
	// 	for(int j=0;j<3;j++){
	// 		temp[i][j] = -1;
	// 	}
	// }
	// return(temp);
}

int htsearch(int **hash, int i, int sig,int s){
	int temp = (100003*i+103*sig)%s;
	if(hash[temp] == NULL){
		//null hash row
		return(-1);
	}
	else{
		return(temp+1);
	}
}

void htinsert(int ** hash, int i, int sig, int flag, int s){
	int temp = (100003*i+103*sig)%s;
	int ind = 1;
	while(ind){
		if(hash[temp] == NULL){
			hash[temp] = (int *)malloc(sizeof(int) * 3);
			hash[temp][0] = i;
			hash[temp][1] = sig;
			hash[temp][2] = flag;
			ind = 0;
		}
		else{
			temp++;
		}
	}
	return;
}

int h_algo(int **hash, int level, int sig, int s, int *values, int t){
	// hs = htsearch(hash, level,sig,s);
	// if(hs != -1){

	// }
	// e = h_algo()
	int val=0;
	int e = htsearch(hash, level, sig,s);
	int i = htsearch(hash, level, sig+values[level],s);
	if(e != -1){
		val = hash[e-1][1];
		return(val);	
	}
	else{
		htinsert(hash, level, sig, 0,s);
		e = h_algo(hash, level+1,sig,s,values,t);
	}
	if(i != -1){
		val = hash[i-1][1];
		return(val);
	}
	else{
		htinsert(hash, level, sig+values[level], 1,s);
		i = h_algo(hash, level+1, sig+values[level],s,values, t);
	}
	if(e<=t && i<=t){
		return(max(e,i));
	}
	if(e>t){
		return(i);
	}
	if(i>t){
		return(e);
	}
	return(0);
}



int hashs(int ** hash,int *values,int t,int n,int s){
	int level = 0;
	int sig = 0;
	return(h_algo(hash, level, sig,s,values,t));
}

int main(){
	int n=0;
	cin >> n;
	int values[n+1], sum=0;
	for(int i=0;i<n;i++){
		cin >> values[i];
		sum+=values[i];
	}
	int t = floor(sum/2);
	//cout <<"s "<< s << endl;
	//cout <<"t "<< t <<endl;
	int res = exhs(values, t,n);
	cout << "exhaustive search "<<res << endl;
	int s = n*t;
	int ** hash;
	hash = htinit(s);
	// for(int i=0;i<n;i++){
	// 	htinsert(hash, i, values[i],1);
	// }
	int r = hashs(hash,values,t,n,s);
	cout << "hash "<<r<<endl;
	return(0);
}