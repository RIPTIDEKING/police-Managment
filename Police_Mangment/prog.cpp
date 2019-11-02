#include "basicFun.cpp"

class basePersonInfo{
	private:
		char address[100];
		char phoneNumber[30];
	public:
		char dob[15];
		int age;
		char gender[20];
		char complexion[40];
		char birthMarks[40];	
		void setAdd(char addr[]){
			for(int i=0;i<100;i++){
			address[i] = addr[i];	
			}
			 
		}
		void setPhNo(char phnr[]){
			for(int i=0;i<30;i++){
				phoneNumber[i] = phnr[i];
			}
		}
		char * getAdd(){
			return address;
		}
		char * getPhNo(){
			return phoneNumber;
		}
	public:
		char fName[20];
		char lName[20];
//		virtual void createEntry()=0;	
};

class Criminal:public basePersonInfo{
		
	public:
		char caughtBy[100];
		char criminalid[50];
		char crimes[100];
		char punishment[100];
		bool status;		
		
		bool match(vector<Criminal> v){
		for(int i=0;i<v.size();i++){
			if(StrCmp(v[i].criminalid,criminalid)){
				return 1;
			}
		}
		return 0;	
		}
		
		void EnterInfo(vector<Criminal> v){
			char Age[3];
			char phoneNo[30];
			char addr[100];
			cout << endl << "Criminal I'd: ";
			cin.getline(criminalid,sizeof(criminalid));
			
			if(match(v)){
				cout <<endl <<"Already Exist"<<endl;
				return;
			}
			
			cout <<"First Name: ";
			//cin.ignore();
			cin.getline(fName,sizeof(fName));
			cout <<"Last Name: ";
			cin.getline(lName,sizeof(lName));
			cout <<"Gender: ";
			cin.getline(gender,sizeof(gender));
			cout <<"Date of birth: ";
			cin.getline(dob,sizeof(dob));
			cout << "Age: ";
			cin.getline(Age,sizeof(Age));
			cout << "Complexion: ";
			cin.getline(complexion,sizeof(complexion));
			cout << "birthMarks: ";
			cin.getline(birthMarks,sizeof(birthMarks));
			cout << "Phone Number: ";
			cin.getline(phoneNo,sizeof(phoneNo));
			cout << "address: ";
			cin.getline(addr,sizeof(addr));
			cout << "Crimes: ";
			cin.getline(crimes,sizeof(crimes));
			cout << "Caught Status (1 for caught and 0 for still at large): ";
			cin >> status;
			cin.ignore();
			if(status){
			cout << "Caught By: ";
			cin.getline(caughtBy,sizeof(caughtBy));
			cout << "Punishment: ";
			cin.getline(punishment,sizeof(punishment));	
			}else{
				strcpy(caughtBy,"None");
				strcpy(punishment,"None");
			}
			age = stoi(Age);
			setPhNo(phoneNo);
			setAdd(addr);		
		}
		void showOnScreen(){
			cout << endl;
			cout << "Name: "<<fName<<" "<<lName<<endl;
			cout << "Criminal I'd: "<<criminalid<<endl;
			cout << "Gender: "<<gender<<endl;
			cout << "Date of Birth (AGE): "<<dob<<" ("<<age<<") "<<endl;
			cout << "Complexion: "<<complexion<<endl;
			cout << "birth Marks: "<<birthMarks<<endl;
			cout << "Phone Number:"<<getPhNo()<<endl;
			cout << "Address: "<<getAdd()<<endl;
			cout << "Crimes: "<<crimes<<endl;
			cout << "Caught Status: ";
			if (status){
			cout << "Already Caught"<<endl;
			cout << "Caught By: "<<caughtBy<<endl;
			cout << "Punishment: "<<punishment<<endl;
			}else{
				cout << "Still at Large"<<endl;
			}
			
		}
};

class PoliceMan:public basePersonInfo{
	private:
		char password[100];
	protected:
		char salary[100];
		
	public:
		char officerid[100];
		char post[100];
		int cCaught;	
		
		bool match(vector<PoliceMan> v){
		for(int i=0;i<v.size();i++){
			if(StrCmp(v[i].officerid,officerid)){
				return 1;
			}
		}
		return 0;	
		}
		
		void setPass(char pass[]){
			strcpy(pass,password);
		}
		char * getPass(){
			return password;
		}
		
		void EnterInfo(vector<PoliceMan> v){
			char Age[3];
			char phoneNo[30];
			char addr[100];
			char ccaught[50];
			cout << endl << "Officer I'd: ";
			cin.getline(officerid,sizeof(officerid));
			
			if(match(v)){
				cout <<endl <<"Already Exist"<<endl;
				return;
			}
			
			cout << "Enter Password: ";
			cin.getline(password,sizeof(password));
			cout <<"First Name: ";
			cin.getline(fName,sizeof(fName));
			cout <<"Last Name: ";
			cin.getline(lName,sizeof(lName));
			cout <<"Gender: ";
			cin.getline(gender,sizeof(gender));
			cout <<"Date of birth: ";
			cin.getline(dob,sizeof(dob));
			cout << "Age: ";
			cin.getline(Age,sizeof(Age));
			cout << "Complexion: ";
			cin.getline(complexion,sizeof(complexion));
			cout << "birthMarks: ";
			cin.getline(birthMarks,sizeof(birthMarks));
			cout << "Post: ";
			cin.getline(post,sizeof(post));
			cout << "Phone Number: ";
			cin.getline(phoneNo,sizeof(phoneNo));
			cout << "address: ";
			cin.getline(addr,sizeof(addr));
			cout << "Salary: ";
			cin.getline(salary,sizeof(salary));
			cout << "Criminals Caught: ";
			cin.getline(ccaught,sizeof(ccaught));
			age = stoi(Age);
			cCaught = stoi(ccaught);
			setPhNo(phoneNo);
			setAdd(addr);		
		}
		void showOnScreen(){
			cout << endl;
			cout << "Name: "<<fName<<" "<<lName<<endl;
			cout << "Officer I'd: "<<officerid<<endl;
			cout << "Gender: "<<gender<<endl;
			cout << "Date of Birth (AGE): "<<dob<<" ("<<age<<") "<<endl;
			cout << "Complexion: "<<complexion<<endl;
			cout << "birth Marks: "<<birthMarks<<endl;
			cout << "Post: "<<post<<endl;
			cout << "Salary: "<<salary<<endl;
			cout << "Phone Number:"<<getPhNo()<<endl;
			cout << "Address: "<<getAdd()<<endl;
			cout << "Criminal Caught: "<<cCaught<<endl;
		}
		
};


