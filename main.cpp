#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <iomanip>

using namespace std;

//double seed=time(NULL);
double seed=33149495;

int main(){
	//I experiment
  //open file
  ofstream save;
  save.open("montecarlo.csv", ios::out);
  while(!save.is_open()) cout <<"error"<<endl;
  //file
  srand(seed);  
int year[365]={0};
 int people=55,n=500000;
int cntr=0;
 for(int i=2;i<=people;i++){//table per people
   cntr=0;
   for(int j=0;j<n;j++){//generates n events
     for(int l=0;l<365;l++) year[l]=0;
     for(int k=0;k<i;k++) ++year[rand()%365]; //put i random birthday in year
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
		if(++year[rand()%365]==2) break;	 //count how many people before two have same birthday
	}
		average=((average*(j-1))+cntr)/j;	
}
	cout<<"\n\n***************************\n\n";
	cout<<"On average with "<<n<<" simulation, I need "<<average<<" people to be sure two have same birthday\n\n";
	
  return 0;
}
