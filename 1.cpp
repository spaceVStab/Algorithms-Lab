#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
#define N 100000000
using namespace std;

extern void registerme();
extern void startgame(int );
extern int guess(int);
extern void verifysoln(int);

int playgame1(){
	int temp;
	for(int i=0;i<N;i++){
		temp = guess(i);
		if(temp==1){
			return(i);
		}
	}
}

int playgame2(){
	int random =0;
	srand(time(NULL));
	while(1){
		random = (1+rand())%100000000;	
		if(guess(random)==1){
			return(random);
		}
	}
}

int checkgame3(int L, int R, int temp){
	guess(temp);

}

int playgame3(){
	int L,R,p,c;
	L = 1;
	R = 100000000;
	while(1){
		p = guess(L);
		c = guess(R);
		if(p==1){
			return(L);
		}
		if(c==1){
			return(R);
		}
		//cout <<((L+R)/2)<<"  "<< c <<endl;
		if(c==2){
			L = (L+R)/2;
		}
		else if(c==3){
			R = (L+R)/2;
		}
		//cout <<L<<"  "<<R<<"   "<< c <<endl;
	}
}

int playgame4(){
	int L,R,p,c,i=0;
		int flag2=0,flag3=0;
		L = 1;
		R = 100000000;
		p = guess(L);
		c = guess(R);
		while(1){
			i++;
			if(flag2){
				c = guess(L);
				flag2=0;
				flag3 = 0;
				if(c==1){
					return(L);
				}
			}
			else if(flag3){
				c = guess(R);
				flag3=0;
				flag2=0;
				if(c==1){
					return(R);
				}
			}
			if(c==2){
				L = (L+R)/2;
				flag2 = 1;
				flag3 = 0;
			}
			else if(c==3){
				R = (L+R)/2;
				flag3 = 1;
				flag2 = 0;
			}
			//cout <<L<<"  "<<R<<"   "<< c <<"  "<<i<<endl;
		}
}





int main(){
	clock_t c1,c2;
	int a;
	registerme();


	startgame(1);
	c1 = clock();
	a = playgame1();
	c2 = clock();
	cout << "\n+++ Game 1\n   a1 = "<<a<<"\n" <<endl;
	cout << "   Time taken = "<< ((double)(c2-c1)/(double)CLOCKS_PER_SEC) <<"sec\n"<<endl;
	verifysoln(a);

	startgame(2);
	c1 = clock();
	a = playgame2();
	c2 = clock();
	cout << "\n+++ Game 2\n   a2 = "<<a<<"\n" <<endl;
	cout << "   Time taken = "<< ((double)(c2-c1)/(double)CLOCKS_PER_SEC) <<"sec\n"<<endl;
	verifysoln(a);

	startgame(3);
	c1 = clock();
	a = playgame3();
	c2 = clock();
	cout << "\n+++ Game 3\n   a3 = "<<a<<"\n" <<endl;
	cout << "   Time taken = "<< ((double)(c2-c1)/(double)CLOCKS_PER_SEC) <<"sec\n"<<endl;
	verifysoln(a);

	startgame(4);
	c1 = clock();
	a = playgame4();
	c2 = clock();
	cout << "\n+++ Game 4\n   a4 = "<<a<<"\n" <<endl;
	cout << "   Time taken = "<< ((double)(c2-c1)/(double)CLOCKS_PER_SEC) <<"sec\n"<<endl;
	verifysoln(a);

}
