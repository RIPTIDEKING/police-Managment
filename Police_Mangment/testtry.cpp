#include "prog.cpp"

class t{
	public:
		int a;
		virtual int b(int c,int d,int e=4) = 0;
};
class tt:public t{
	public:
	int b(int c,int d=2,int f=0){
		return c+d;
	}
};
int fun(int a,int b=5,int c=10){
	return a+b+c;
}
int main(){
Criminal a;
PoliceMan b;
b.EnterInfo("Ayush","Agarwal","23/2/2000",19,"fair","dot in Eye","306,Ganga hostel,Mnit jaipur","7378011858","DCP",1000000000,10000);
a.EnterInfo("navyug","mohan","18-5-1999",20,"yellow","hole instead of the reproduction organs","ganga hostel, Mnit jaipur","123456789","bakchodi","Ayush Agarwal");
a.createEntry();
b.createEntry();
}
