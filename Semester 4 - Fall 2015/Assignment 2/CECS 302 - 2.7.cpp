//Assignment 2: 2.7
//Zachary Shumate
//9-29-2015
//CECS 302-01

#include <iostream>
#include <ctime>

using namespace std;

main(){
	int i;
	int j;
	int k;
	int sum;
	int n;
	clock_t time, final;
	
	cout << "Pick a number for N: " << endl;
	cin >> n;
	
	//1
	time = clock();
	sum = 0;
	for(i=0; i<n; ++i){
		++sum;
	}
	
	final = clock() - time;
	cout << "Algorithm 1 time: " << (double) final << endl;
	
	//2
	time = clock();
	sum = 0;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			++sum;
		}
	}
	
	final = clock() - time;
	cout << "Algorithm 2 time: " << (double) final << endl;
	
	//3
	time = clock();
	sum = 0;
	for(i=0; i<n; ++i){
		for(j=0; j<n*n; ++j){
			++sum;
		}
	}
	
	final = clock() - time;
	cout << "Algorithm 3 time: " << (double) final << endl;
	
	//4
	time = clock();
	sum = 0;
	for(i=0; i<n; ++i){
		for(j=0; j<i; ++j){
			++sum;
		}
	}
	
	final = clock() - time;
	cout << "Algorithm 4 time: " << (double) final << endl;
	
	//5
	time = clock();
	sum = 0;
	for(i=0; i<n; ++i){
		for(j=0; j<i*i; ++j){
			for(k=0; k<j; ++k){
				++sum;
			}
		}
	}
	
	final = clock() - time;
	cout << "Algorithm 5 time: " << (double) final << endl;
	
	//6
	time = clock();
	sum = 0;
	for(i=0; i<n; ++i){
		for(j=1; j<i*i; ++j){
			if(j%i==0){
				for(k=0; k<j; ++k){
					++sum;
				}
			}
		}
	}
	
	final = clock() - time;
	cout << "Algorithm 6 time: " << (double) final << endl;
}
