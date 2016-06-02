#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

//double seed=time(NULL);
double seed=33149495;
double p(double x);
int yearrand();

int main(){
	srand(seed); 
	//I experiment
  //open file
  ofstream save;
  save.open("montecarlo.csv", ios::out);
  while(!save.is_open()) cout <<"error"<<endl;
  //file
int year[365]={0};
 int people=55,n=500000;
int cntr=0;
 for(int i=2;i<=people;i++){//table per people
   cntr=0;
   for(int j=0;j<n;j++){//generates n events
     for(int l=0;l<365;l++) year[l]=0;
     for(int k=0;k<i;k++) ++year[yearrand()%365]; //put i random birthday in year
     for(int l=0;l<365;l++) if(year[l]>=2) {cntr++;break;}//check if in this of n cases there are 2 people with same birthday
   }
   cout<<i<<" people\tp:  "<<setw(6)<<(double)cntr/n*100<<"%"<<endl;
   save<<i<<";"<<(double)cntr/n<<endl; 
}
	//II experiment
	
	double average=0;
	
	for(int j=1; j<=n;j++){//n simulations
		for(int l=0;l<365;l++) year[l]=0; //reset
		cntr=0;
		
	while(true){
		cntr++;
		if(++year[yearrand()%365]==2) break;	 //count how many people before two have same birthday
	}
		average=((average*(j-1))+cntr)/j;	
}
	cout<<"\n\n***************************\n\n";
	cout<<"On average with "<<n<<" simulation, I need "<<average<<" people to be sure two have same birthday\n\n";
	
  return 0;
}


/*
 function of probablity based on italian born in 2014
 data source: http://demo.istat.it/altridati/IscrittiNascita/2014/T2.8.xls
*/
 double p(double x){
	return (-3.27*pow(10.,-9)*x*x*x+1.86*pow(10.,-6)*x*x-2.63*pow(10.,-4)+0.0889)/15.643;
}

int yearrand(){
	int n=500000,i=0;
	double xi=0,yi=0;  
	int a=0,b=365;
	double fmax=p(9);
	while(i<n){  
		xi=rand()%(b-a+1)+a;
		yi=rand()/(double)RAND_MAX*fmax;
		if(p(xi)>yi) {return xi; i++;}
	}
	return -1;
}
