#include "fio_manag.cpp"

int main(){

//	PoliceMan c;
//	fileinout f;
//	vector<PoliceMan> v;
//	char ch;
//	do{
//		c.EnterInfo();
//		f.writeToFile(c);
//		cout << "Do you want to enter another Police man info: (y/n) ";
////		cin.ignore();
//		cin >> ch; 
//		cout << ch;
//		cin.ignore();
//	}while(ch =='y');
//	cout << "data recorded sucessfully";
//	v = f.readFromFile(0);
//	for (int i=0;i<v.size();i++){
//		v[i].showOnScreen();
//	}
char ch[100];
cin.getline(ch,sizeof(ch));
if(!strcmp(ch,"")){
	cout << "Sucess";
	cout << ch;
}else{
	cout << "Failed";
}
}
