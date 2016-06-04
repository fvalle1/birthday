#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "statusbar.h"

using namespace std;

//double seed=time(NULL);
double seed=33149495;
double p(double x);
int yearrand();

int main(){
	srand(seed);
	statusbar mybar;
	int n=500000;

//I experiment
	ofstream save;		  //open file
  save.open("montecarlo.csv", ios::out);
  while(!save.is_open()) cout <<"error creating file!"<<endl;	
int year[365]={0}, people=55;
mybar.maxevents=people;
int cntr=0;
 for(int i=2;i<=people;i++){//table per people
   cntr=0;
   for(int j=0;j<n;j++){//generates n events
     for(int l=0;l<365;l++) year[l]=0;	//reset year
     for(int k=0;k<i;k++) ++year[yearrand()%365]; //put i random birthday in year
     for(int l=0;l<365;l++) if(year[l]>=2) {cntr++;break;}//check if in this of n cases there are 2 people with same birthday
   }
	 save<<i<<";"<<(double)cntr/n<<endl;
   cout<<i<<" people\tp:  "<<setw(6)<<(double)cntr/n*100<<"%"<<"\t";
	 mybar.drawwpercent(i);cout<<endl;

}
	
	cout<<"\n\n***************************\n\n";
	//II experiment
	double average=0;
	mybar.setmaxevents(n);
		mybar.setr(1);
	for(int j=1; j<=n;j++){//n simulations
		for(int l=0;l<365;l++) year[l]=0; //reset
		cntr=0;
		
	while(true){
		cntr++;
		if(++year[yearrand()%365]==2) break;	 //count how many people before two have same birthday
	}
		average=((average*(j-1))+cntr)/j;
		mybar.draw(j);
}
	cout<<"\rWith "<<n<<" simulation, I need a average of "<<average<<" people to be sure two have same birthday\n\n";
  return 0;
}


/*
 function of probablity based on italian born in 2014
 data source: http://demo.istat.it/altridati/IscrittiNascita/2014/T2.8.xls
*/
 double p(double x){
	return (-3.27*pow(10.,-9)*x*x*x+1.86*pow(10.,-6)*x*x-2.63*pow(10.,-4)*x+0.0889)/15.643;
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
