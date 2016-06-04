#include <statusbar.h>
#include <iostream>

using std::cout;

void statusbar::drawpercentual(){
cout<<(double)point/maxpoint*hund<<"%";
};


void statusbar::draw(){
    setchr();
	if(r) cout<<"\r";
    cout<<"[";
    setpoint();
    for(int i=0;i<point;i++) cout<<chr;
    for(int i=point;i<maxpoint;i++) cout<<" ";
    cout<<"]";
  }

void statusbar::draw(int ev){
  event=ev;
  draw();
}

void statusbar::drawwpercent(){
  draw();
  drawpercentual();
};

void statusbar::drawwpercent(int ev){
  draw(ev);
  drawpercentual();
};

void statusbar::setr(int ok){
	if(ok==1) r=true;	
};

