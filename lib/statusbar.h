#ifndef statusbar_H_
#define statusbar_H_

class statusbar{
private:
	static const int zero=0;
	static const int hund=100;
	int max;
	int point;
	int maxpoint;
	bool r;
	void setmaxpoint(int predefmaxpoint=25){maxpoint=predefmaxpoint;};
	void setpoint(){setmaxpoint(); point=(double)event/maxevents*maxpoint;};
	void drawpercentual();
public:
	char chr;
	void setchr(char c='*'){chr=c;};
	int event, maxevents;
	void setmaxevents(int m){maxevents=m;};
	void draw();
	void draw(int ev);
	void drawwpercent();
	void drawwpercent(int ev);
	void setr(int ok);
};
#endif
