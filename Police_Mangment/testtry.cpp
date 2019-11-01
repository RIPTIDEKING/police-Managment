#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

class abcd{
	public:
		int a;
		int b;
		char abc[25];
		//string abc;
		
	void setabc(char aaa[]){
		for(int i=0;i<25;i++){
			abc[i] = aaa[i];
		}
	}
	char * getabc(){
		return abc;
	}
	void setData(){
		cout << "a:";
		cin >> a;
		cout << "b:";
		cin >> b;
		cout << "c:";
	
	cout << "b:";
	char abb[25];
	cin.getline(abb,sizeof(abb));
	cout << 45 <<endl;
	cout << abb;

	}
	void getData(){
		cout << a<<endl;
		cout << b<<endl;
		cout << abc<<endl;
	}
	void wtf(){
		fstream f;
		abcd a;
		f.open("aaa.dat",ios::app | ios :: binary);
		a.setData();
		
		f.write((char * ) &a, sizeof(a));
		f.close();
		
	}
	void rff(){
		fstream f;
		abcd a;
		f.open("aaa.dat",ios::in|ios::binary);
		
		while(((f.read((char *) &a , sizeof(a))))){
		a.getData();	
		cout << "next" << endl;
		}
		f.close();
//		
//		
//		
//                      fstream f;
//                      Student Stu;
//
//                      f.open("Student.dat",ios::in|ios::binary);
//
//                      cout<<"\n\tRoll\tName\tMarks\n";
//
//                      while( (f.read((char*)&Stu,sizeof(Stu))) != NULL )
//                      		Stu.putdata();
//
//                      f.close();
//		
	}
};

int main(){
	abcd a;
//	a.setData();
//	cout<<"next"<<endl;
//	char b[25];
//	scanf("%s",b);
//	a.setabc(b);
//	char *p;
//	p = a.getabc();
//	cout << p[2];
//	a.wtf();
//	a.rff();
	a.setData();

}

