#include <bits/stdc++.h>
using namespace std;

extern int registerme ( int );
extern void startsort ( );
extern int compareballs ( int, int );
extern void verifysort ( int * );
extern void startmatch ( int );
extern int fitsin ( int i, int j );
extern void verifymatch ( int * );

void merge(int *S, int l, int m, int r){
	int *L,*R;
	int i,j,k;
	int n1 = m-l+1;
	int n2 = r-m;
	L = (int *)malloc(n1*sizeof(int));
	R = (int *)malloc(n2*sizeof(int));
	// int L[n1+1], R[n2+1];
	for(i=0;i<n1;i++){
		L[i] = S[l+i];
	}
	for(j=0;j<n2;j++){
		R[j] = S[m+1+j];
	}
	i=0;j=0;k=l;
	while(i<n1 && j<n2){
		if(compareballs(L[i],R[j]) == 1){
			S[k] = R[j];
			j++;
		}
		else if(compareballs(L[i],R[j]) == -1){
			S[k] = L[i];
			i++;
		}
		k++;
	}
	while(i<n1){
		S[k] = L[i];
		i++;
		k++;
	}
	while(j<n2){
		S[k] = R[j];
		j++;
		k++;
	}
	free(L);
	free(R);
}

void mergesort(int *S, int l, int r){
	if(l<r){
		int m = (l+r)/2;
		mergesort(S,l,m);
		mergesort(S,m+1,r);
		merge(S,l,m,r);
	}
}

int binarysort(int *S,int l, int r, int pivot){
	if (r >= l)
	   {
	        int mid = l + (r - l)/2;
	 
	        // If the element is present at the middle 
	        // itself
	        int temp = fitsin(S[mid],pivot);
	        if (temp==0)  
	            return mid;
	        if (temp == -1) 
	            return binarysort(S, l, mid-1, pivot);
	        return binarysort(S, mid+1, r, pivot);
	   }
}

int partition(int *M, int *S, int l, int r){
	int pivot = M[r];
	int index = binarysort(S,l,r,pivot);
	int i = l-1,temp=0;
	for (int j = l; j <= r- 1; j++)
	    {
	        if (fitsin(S[index],M[j]) == -1)
	        {
	            i++;  
	            temp = M[i];
	            M[i] = M[j];
	            M[j] = temp;
	        }
	    }
	    //swap(&M[i + 1], &M[r]);
	    temp = M[i+1];
	    M[i+1] = M[r];
	    M[r] = temp;
	    return (i + 1);
}

void quicksort(int *M,int *S, int l, int r){
	// if(l<r){
	// 	int pi = partition(M,S,l,r);
	// 	quicksort(M,S,l,pi-1);
	// 	quicksort(M,S,pi+1,r);
	// }

	int n = r+1;

	for(int i=0;i<n;i++){
		int idx = binarysort(S,0, n-1,i);
		M[S[idx]] = i;
	}
}


int main(){
	int n,flag =1;
	cin >> n;
	int *S,*M;
	S = (int *)malloc((n+1)*sizeof(int));
	M = (int *)malloc((n+1)*sizeof(int));
	//int S[n+1],M[n+1];
	for(int i=0;i<n;i++){
		S[i] = i;
		M[i] = i;
	}
	registerme(n);

	cout << "\n Sorting the balls\n"<<endl;
	startsort();
	mergesort(S,0,n-1);
	verifysort(S);

	cout << "\n Starting the match\n\n"<<endl;
	startmatch(flag);
	quicksort(M,S,0,n-1);
	verifymatch(M);
	return 0;
}