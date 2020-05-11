#include <iostream>
#include <cstdio>

using namespace std;

#define max_num 100001
#define max_k  6


void count_primes(int num_lines){
	bool is_prime[max_num];
	int counts[max_num];
	int kp[max_num][max_k];


	/*Initializations*/
	for (int i=0; i<max_num; i++) is_prime[i] = true;
	for (int i=0; i<max_num; i++) counts[i] = 0;


	for (int p=2; p < max_num; p++){
		if (is_prime[p]){
			counts[p] = 1;
			int j = 2;

			while ((p* j) < max_num){
				is_prime[p*j] = 0;
				counts[p*j]++;
				j++;
			}
		}
	}


	//Create running sum of the counts for the unique prime factors in each num from 2 -> max_num
	for (int i=2; i < max_num; i++){
		for(int j=1; j < max_k; j++)
			kp[i][j] = kp[i-1][j] + (counts[i] == j ? 1 : 0);
	}

	int a, b, k;
	for (int i=0; i < num_lines; i++){
		scanf("%d%d%d",&a,&b,&k);
		printf("%d\n",kp[b][k]-kp[a-1][k]);
	}

}



int main(){
	int t;
	scanf("%d",&t);
	count_primes(t);
	return 0;
}