//#include <bits/stdc++.h>
//using namespace std;
#include "fio_manag.cpp"

class basePersonInfo{
	private:
		string address;
		string phoneNumber;
	protected:
		string dob;
		int age;
		string complexion;
		string birthMarks;	
		void setAdd(string addr){
			address =addr; 
		}
		void setPhNo(string phnr){
			phoneNumber = phnr;
		}
		string getAdd(){
			return address;
		}
		string getPhNo(){
			return phoneNumber;
		}
	public:
		string fName;
		string lName;
		virtual void createEntry(
//		string fname,
//		string lname,
//		string Dob,
//		int Age,
//		string Complexion,
//		string birthmark,
//		string addr,
//		string phoneNo
		)=0;	
};

class Criminal:public basePersonInfo{
	protected:
		string caughtBy;
	public:
		string crimes;		
		Criminal(){}
		Criminal(
		string fname,
		string lname,
		string Dob,
		int Age,
		string Complexion,
		string birthmark,
		string addr,
		string phoneNo,
		string crime,
		string CaughtBy){
			fName = fname;
			lName = lname;
			dob = Dob;
			age = Age;
			complexion = Complexion;
			birthMarks = birthmark;
			setPhNo(phoneNo);
			setAdd(addr);
			crimes = crime;
			caughtBy = CaughtBy;		
		}
		void EnterInfo(
		string fname,
		string lname,
		string Dob,
		int Age,
		string Complexion,
		string birthmark,
		string addr,
		string phoneNo,
		string crime,
		string CaughtBy){
			fName = fname;
			lName = lname;
			dob = Dob;
			age = Age;
			complexion = Complexion;
			birthMarks = birthmark;
			setPhNo(phoneNo);
			setAdd(addr);
			crimes = crime;
			caughtBy = CaughtBy;		
		}
	void createEntry(){
		fileinout f("criminal");
		f.fwOs();
		f.fwDouble(fName,lName);
		f.fwDouble(dob,toStr(age));
		f.fwSingle(complexion);
		f.fwSingle(birthMarks);
		f.fwSingle(getAdd());
		f.fwSingle(getPhNo());
		f.fwSingle(crimes);
		f.fwSingle(caughtBy);
		f.fwOe();
	}
};

class PoliceMan:private basePersonInfo{
	protected:
		int salary;
	public:
		string post;
		int cCaught;
				
		PoliceMan(){}
		PoliceMan(
		string fname,
		string lname,
		string Dob,
		int Age,
		string Complexion,
		string birthmark,
		string addr,
		string phoneNo,
		string Post,
		int Salary,
		int CCaught){
			fName = fname;
			lName = lname;
			dob = Dob;
			age = Age;
			complexion = Complexion;
			birthMarks = birthmark;
			setPhNo(phoneNo);
			setAdd(addr);
			post = Post;
			cCaught = CCaught;
			salary = Salary;		
		}
		void EnterInfo(
		string fname,
		string lname,
		string Dob,
		int Age,
		string Complexion,
		string birthmark,
		string addr,
		string phoneNo,
		string Post,
		int Salary,
		int CCaught){
			fName = fname;
			lName = lname;
			dob = Dob;
			age = Age;
			complexion = Complexion;
			birthMarks = birthmark;
			setPhNo(phoneNo);
			setAdd(addr);
			post = Post;
			salary = Salary;	
		}
	void createEntry(){
		fileinout f("policeman");
		f.fwOs();
		f.fwDouble(fName,lName);
		f.fwDouble(dob,toStr(age));
		f.fwDouble(post,toStr(salary));
		f.fwSingle(complexion);
		f.fwSingle(birthMarks);
		f.fwSingle(getAdd());
		f.fwSingle(getPhNo());
		f.fwSingle(toStr(cCaught));
		f.fwOe();
	}
};

//int main(){
//
//	return 0;
//}
