/*
ID: safaand1
PROG: kimbits
LANG: C++11
*/

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");


int vals[33][33];
int N,L;
long long int I;
int res;
void eval(){
    vals[1][1] = 1;
    for(int i=2;i<33;i++)
	for(int j=1;j<=i;j++)
	    vals[i][j] = vals[i-1][j] + vals[i-1][j-1];
}


void find(long long int a){
    if( a == 0) return;
    for(int i=1;i<=N;i++){
	a--;
	if(a <= 0) {
	    res |= 1<<(i-1);
	    return;
	}
	int temp = 0;
	for(int j=2;j<=i && j<=L;j++){
	    temp += vals[i][j];
	    if(a - temp <= 0){
		res |= 1 << (i-1);
		L--;
		find(a);
		return ;
	    }
	    
	}
	a -= temp;
    }
}

void write(int a){
    if(!N) return;
    N--;
    write(a/2); 
    fout << a%2;
}

int main(){
    eval(); 
    fin >> N >> L >> I;
    find(I-1); 
    write(res);
    fout << endl;
    return 0;
}
