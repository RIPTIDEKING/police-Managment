#include "prog.cpp"

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

	public:
		void writeToFile(Criminal obj){
			fstream fout;
			fout.open("criminal.dat",ios::app|ios::binary);
			fout.write((char *) &obj,sizeof(obj));
			fout.close();
		}
		vector<Criminal> readFromFile(){
			fstream fin;
			vector<Criminal> robjs;
			Criminal tobj;
			fin.open("criminal.dat",ios::in|ios::binary);
			while(fin.read((char *) &tobj,sizeof(tobj))){
				robjs.push_back(tobj);
			}
			return robjs;
		}
		void writeToFile(PoliceMan obj){
			fstream fout;
			fout.open("police.dat",ios::app|ios::binary);
			fout.write((char *) &obj,sizeof(obj));
			fout.close();
//			cout << "Sucessfully recorded";
		}
		vector<PoliceMan> readFromFile(int n){
			fstream fin;
			vector<PoliceMan> robjs;
			PoliceMan tobj;
			fin.open("police.dat",ios::in|ios::binary);
			while(fin.read((char *) &tobj,sizeof(tobj))){
				robjs.push_back(tobj);
			}
			return robjs;
		}
};

