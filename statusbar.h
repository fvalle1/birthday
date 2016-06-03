#include <iostream>

using std::cout;

class statusbar{
private:
	static const int zero=0;
	static const int hund=100;
	int max;
	int point;
	int maxpoint;
	void setmaxpoint(int predefmaxpoint=25){maxpoint=predefmaxpoint;};
	void setpoint(){setmaxpoint(); point=(double)event/maxevents*maxpoint;};
	void drawpercentual(){cout<<(double)point/maxpoint*hund<<"%";};
public:
	char chr;
	void setchr(char c='*'){chr=c;};
	int event, maxevents;
	void setmaxevents(int m){maxevents=m;};
	void draw(){
		setchr();
		cout<<"[";
		setpoint();
		for(int i=0;i<point;i++) cout<<chr;
		for(int i=point;i<maxpoint;i++) cout<<" ";
		cout<<"]";
	};
	void draw(int ev){
		event=ev;
		draw();
	};
	void drawwpercent(){
		draw();
		drawpercentual();
	};
	void drawwpercent(int ev){
		draw(ev);
		drawpercentual();
	};
}statusbar;
