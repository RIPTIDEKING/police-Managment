#include "prog.cpp"

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

