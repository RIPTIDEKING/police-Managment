#include "basicFun.cpp"

class encryption{
	public:
		string encrpt(string orignal){
			string mess="",tmess = "";
			char temp;
			int len = orignal.length();
			int counter;
			if(len > 129){
				counter = 129;
				for(int i= 129;i<len;i++){
					temp = orignal[i]+i-129+1;
					tmess += temp;
				}
			}else{
				counter = len;
			}
			for(int i=0;i<counter;i++){
				temp = orignal[i]+i+1;
				mess += temp;
			}
			return mess+tmess;
		}
		string dcrpt(string mess){
			string orignal="",tmess="";
			char temp;
			int len = mess.length();
			int counter;
			if(len > 129){
				counter = 129;
				for(int i= 129;i<len;i++){
					temp = orignal[i]-i-129-1;
					tmess += temp;
				}
			}else{
				counter = len;
			}
			for(int i=0;i<counter;i++){
				temp = mess[i]-i-1;
				orignal += temp;
			}
			return orignal+tmess;
		}
};
class fileinout{
	private:
		fstream fin,fout;
		encryption e;
	public:
		fileinout(string filename){
			if(filename == "criminal"){
				fin.open("criminal.txt",ios::in);
				fout.open("criminal.txt",ios::app);
			}else if(filename == "policeman"){
				fin.open("policeman.txt",ios::in);
				fout.open("policeman.txt",ios::app);
			}else{
				fin.open("defaultInfo.txt",ios::in);
				fout.open("defaultInfo.txt",ios::app);
			}
			
		}
		~fileinout(){
			fin.close();
			fout.close();
		}
		void fwSingle(string info){
			fout << e.encrpt(info)<<"\n";
		}
		void fwDouble(string info1,string info2){
			fout << e.encrpt(info1) << "\t" << e.encrpt(info2) << "\n";
		}
		void fwOs(){
			fout << "fileObjStart \n";
		}
		void fwOe(){
			fout << "fileObjEnd \n";
		}
};

//int main(){
//fstream f;
//encryption e;
//f.open("abc.txt",ios::out);
//f << e.encrpt("a\t_");
//f.close();
//f.open("abc.txt",ios::in);
//string a,b;
//int i='~';
//char c = 255;
//cout << i << endl;
//cout << c <<endl;
//f >> a >> b;
//cout << e.dcrpt(a) << c <<b;
//	f.open("abc.txt",ios::out);
//	string fname = "Manu",sname = "Agarwal";
//	f << fname <<sname<<"";
//	cout << fname << " "<<sname;
//	f.close();

//string a,b;
//a = e.encrpt("ayush agarwal is my name");
//b = e.dcrpt(a);
//cout << a << endl << b;
//for(int i =0;i<255;i++){
//	char c = i;
//	cout << c;
//}
//return 0;
//}
