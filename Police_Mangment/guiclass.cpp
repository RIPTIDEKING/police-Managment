#include "fio_manag.cpp"

class guiManage{
	public:
		vector<Criminal> criminals;
		vector<PoliceMan> police;
		Criminal tc;
		PoliceMan tp,cp;
		
		
	guiManage(){
	
	}
	
	void chgPass(){
			char tpass[100];
			cout << endl << "Enter Current Password: ";
			cin.getline(tpass,sizeof(tpass));
			if(strcmp(cp.getPass(),tpass)){
			cout << endl << "Wrong Password!!!"<<endl;
			return;	
			}
			cout << endl << "Enter New Password: ";
			//cin.ignore();
			cin.getline(tpass,sizeof(tpass));
			cp.setPass(tpass);
			//cout <<"bbb"<< tpass<<"aaa";
			
			for(int i=0;i<police.size();i++){
				if(StrCmp(cp.officerid,police[i].officerid)){
					police[i] = cp;
				}
			}
			fileinout ff;
			remove("police.dat");
			for(int j =0;j<police.size();j++){
				ff.writeToFile(police[j]);
			}
			cout << endl <<"Password Updated Sucessfully!!"<<endl;
		}
	
	void updatePolice(){
		char id[100];
		cout << "Enter Officer I'd : ";
		cin.getline(id,sizeof(id));
	
		PoliceMan temp;
		bool f = 1;	
		for(int i=0;i<police.size();i++){
			if(StrCmp(police[i].officerid,id)){
				cout << endl << "Entered information will be updated and blank will remain same.";
				strcpy(temp.officerid,id);
				temp.setPass(police[i].getPass());
				cout <<endl << "First Name: ";
				cin.getline(temp.fName,sizeof(temp.fName));
				if(StrCmp(temp.fName,"")){
					strcpy(temp.fName, police[i].fName);
				}
				cout <<"Last Name: ";
				cin.getline(temp.lName,sizeof(temp.lName));
				if(StrCmp(temp.lName,"")){
					strcpy(temp.lName,police[i].lName);
				}
				cout << "Gender: ";
				cin.getline(temp.gender,sizeof(temp.gender));
				if(StrCmp(temp.gender,"")){
					strcpy(temp.gender,police[i].gender);
				}
				cout << "dob: ";
				cin.getline(temp.dob,sizeof(temp.dob));
				if(StrCmp(temp.dob,"")){
					strcpy(temp.dob,police[i].dob);
				}
				cout << "Age (0 for no change) : ";
				cin >> temp.age;
				cin.ignore();
				if(temp.age == 0){
					temp.age = police[i].age;
				}
				cout << "Complexion: ";
				cin.getline(temp.complexion,sizeof(temp.complexion));
				if(StrCmp(temp.complexion,"")){
					strcpy(temp.complexion,police[i].complexion);
				}
				cout << "Birth Marks: ";
				cin.getline(temp.birthMarks,sizeof(temp.birthMarks));
				if(StrCmp(temp.birthMarks,"")){
					strcpy(temp.birthMarks,police[i].birthMarks);
				}
				cout << "Post: ";
				cin.getline(temp.post,sizeof(temp.post));
				if(StrCmp(temp.post,"")){
					strcpy(temp.post,police[i].post);
				}
				cout << "Salary: ";
				cin.getline(temp.salary,sizeof(temp.salary));
				if(StrCmp(temp.salary,"")){
					strcpy(temp.salary,police[i].salary);
				}
				cout << "Criminal Caught (0 for no Change) : ";
				cin >> temp.cCaught;
				cin.ignore();
				if(temp.cCaught == 0){
					temp.cCaught = police[i].cCaught;
				}
				cout << "Address: ";
				char t[100];
				cin.getline(t,sizeof(t));
				if(StrCmp(t,"")){
					temp.setAdd(police[i].getAdd());
				}else{
					temp.setAdd(t);
				}
				cout << "Phone Number: ";
				char tt[30];
				cin.getline(tt,sizeof(tt));
				if(StrCmp(tt,"")){
					temp.setPhNo(police[i].getPhNo());
				}else{
					temp.setPhNo(tt);
				}
				police[i] = temp;
				f = 0;
				break;
			}
		}
		if(f){
			cout << endl << "Invalid Id!!"<<endl;
			return;
		}
		fileinout ff;
		remove("police.dat");
		for(int j =0;j<police.size();j++){
			ff.writeToFile(police[j]);
		}
		cout << endl << "Information sucessfully updated."<<endl;
		return;
		
	}
	void updateCriminal(){
		char id[100];
		cout << "Enter Criminal I'd : ";
		cin.getline(id,sizeof(id));
	
		Criminal temp;
		bool f = 1;	
		for(int i=0;i<criminals.size();i++){
			if(StrCmp(criminals[i].criminalid,id)){
				cout << endl << "Entered information will be updated and blank will remain same.";
				strcpy(temp.criminalid,id);
				cout <<endl << "First Name: ";
				cin.getline(temp.fName,sizeof(temp.fName));
				if(StrCmp(temp.fName,"")){
					strcpy(temp.fName, criminals[i].fName);
				}
				cout <<"Last Name: ";
				cin.getline(temp.lName,sizeof(temp.lName));
				if(StrCmp(temp.lName,"")){
					strcpy(temp.lName,criminals[i].lName);
				}
				cout << "Gender: ";
				cin.getline(temp.gender,sizeof(temp.gender));
				if(StrCmp(temp.gender,"")){
					strcpy(temp.gender,criminals[i].gender);
				}
				cout << "dob: ";
				cin.getline(temp.dob,sizeof(temp.dob));
				if(StrCmp(temp.dob,"")){
					strcpy(temp.dob,criminals[i].dob);
				}
				cout << "Age (0 for no change) : ";
				cin >> temp.age;
				cin.ignore();
				if(temp.age == 0){
					temp.age = criminals[i].age;
				}
				cout << "Complexion: ";
				cin.getline(temp.complexion,sizeof(temp.complexion));
				if(StrCmp(temp.complexion,"")){
					strcpy(temp.complexion,criminals[i].complexion);
				}
				cout << "Birth Marks: ";
				cin.getline(temp.birthMarks,sizeof(temp.birthMarks));
				if(StrCmp(temp.birthMarks,"")){
					strcpy(temp.birthMarks,criminals[i].birthMarks);
				}
				cout << "Crimes: ";
				cin.getline(temp.crimes,sizeof(temp.crimes));
				if(StrCmp(temp.crimes,"")){
					strcpy(temp.crimes,criminals[i].crimes);
				}
				
				cout << "Status ( 1 for caught / 0 for not caught ): ";
				cin >> temp.status;
				cin.ignore();
				if(temp.status){
					cout << "Caught By: ";
					cin.getline(temp.caughtBy,sizeof(temp.caughtBy));
					if(StrCmp(temp.caughtBy,"")){
						strcpy(temp.caughtBy,criminals[i].caughtBy);
					}
					cout << "Punishment: ";
					cin.getline(temp.punishment,sizeof(temp.punishment));
					if(StrCmp(temp.punishment,"")){
						strcpy(temp.punishment,criminals[i].punishment);
					}
				}
				cout << "Address: ";
				char t[100];
				cin.getline(t,sizeof(t));
				if(StrCmp(t,"")){
					temp.setAdd(criminals[i].getAdd());
				}else{
					temp.setAdd(t);
				}
				cout << "Phone Number: ";
				char tt[30];
				cin.getline(tt,sizeof(tt));
				if(StrCmp(tt,"")){
					temp.setPhNo(criminals[i].getPhNo());
				}else{
					temp.setPhNo(tt);
				}
				criminals[i] = temp;
				f = 0;
				break;
			}
		}
		if(f){
			cout << endl << "Invalid Id!!"<<endl;
			return;
		}
		fileinout ff;
		remove("criminal.dat");
		for(int j =0;j<criminals.size();j++){
			ff.writeToFile(criminals[j]);
		}
		cout << endl << "Information sucessfully updated."<<endl;
		return;
		
	}
	
	bool auth(){
		char offid[100],passw[100];
		cout << endl <<"Enter Officer I'd: ";
		cin.getline(offid,sizeof(offid));
		cout << "Enter Password: ";
		cin.getline(passw,sizeof(passw));
		for(int i=0;i<police.size();i++){
			if(StrCmp(police[i].officerid,offid)){
			//	cout <<endl<<" pass "<< police[i].getPass() << "  word: "<<i<<endl;
				if(!strcmp(passw,police[i].getPass())){
					//guiInit();
					cp = police[i];
					return 0;
				}else{
					cout << "Wrong Password"<<endl;
					return 1;
				}
			}
		}
		cout << "Wrong I'd."<<endl;
		return 1;
	}
	
	void deletePolice(string id){
		bool f = 1;
		fileinout ff;
		vector<PoliceMan> temp;
		for(int i=0;i<police.size();i++){
			if(Search(police[i].officerid,id)){
			f = 0;
			//cout << "here";
			continue;
			}
			temp.push_back(police[i]);
		}
		
		if(f){
			cout << "No such officer Available";
		}else{
			police = temp;
			remove("police.dat");
			for(int j =0;j<police.size();j++){
				ff.writeToFile(police[j]);
			}
			cout << endl << "Information sucessfully deleted."<<endl;
			return;
		}
	}

	void deleteCriminal(string id){
		bool f = 1;
		fileinout ff;
		vector<Criminal> temp;
		for(int i=0;i<criminals.size();i++){
			
			if(Search(criminals[i].criminalid,id)){
			f = 0;
			continue;
			}
			temp.push_back(criminals[i]);
		}
		
		if(f){
			cout << "No such criminal Available";
		}else{
			criminals = temp;
			remove("criminal.dat");
			for(int j =0;j<criminals.size();j++){
				ff.writeToFile(criminals[j]);
			}
			cout << endl << "Information sucessfully deleted."<<endl;
			return;
		}
	}
	
	void searchByIdP(char id[]){
		bool f = 1;
		for(int i=0;i<police.size();i++){
			if(Search(police[i].officerid,id)){
				police[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such officer Available";
		}
	}
	
	void searchByIdC(char id[]){
		bool f = 1;
		for(int i=0;i<criminals.size();i++){
			if(Search(criminals[i].criminalid,id)){
				criminals[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such criminal Available";
		}
	}

	
	void searchByageP(int a){
		bool f = 1;
		for(int i=0;i<police.size();i++){
			if(police[i].age == a){
				police[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such officer Available";
		}
	}
	
	void searchByageC(int a){
		bool f = 1;
		for(int i=0;i<criminals.size();i++){
			if(criminals[i].age == a){
				criminals[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such criminal Available";
		}
	}
	
	void searchBygenP(string s){
		bool f = 1;
		for(int i=0;i<police.size();i++){
			if(Search(police[i].gender,s)){
				police[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such officer Available";
		}
	}
	
	
		void searchBygenC(string s){
		bool f = 1;
		for(int i=0;i<criminals.size();i++){
			if(Search(criminals[i].gender,s)){
				criminals[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such criminal Available";
		}
	}

	void searchBybmC(string s){
		bool f = 1;
		for(int i=0;i<criminals.size();i++){
			if(Search(criminals[i].birthMarks,s)){
				criminals[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such criminal Available";
		}
	}
	
	void searchBycomC(string s){
		bool f = 1;
		for(int i=0;i<criminals.size();i++){
			if(Search(criminals[i].complexion,s)){
				criminals[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such criminal Available";
		}
	}
	
	void searchBycbC(string s){
		bool f = 1;
		for(int i=0;i<criminals.size();i++){
			if(Search(criminals[i].caughtBy,s)){
				criminals[i].showOnScreen();
				bool f = 0;
			}
		}
		if(f){
			cout << "No such criminal Available";
		}
	}
	
	void searchByNameP(string name){
		string Cname,fn,sn;
		bool f=1;
		for(int i=0;i<police.size();i++){
			fn = police[i].fName;
			sn = police[i].lName;
			Cname = fn+" "+sn;
			if(Search(Cname,name)){
				police[i].showOnScreen();
				f = 0;
			}
		}
		if(f){
			cout << "No such officer Available";
		}
	}	
	
	void searchByNameC(string name){
		string Cname,fn,sn;
		bool f=1;
		for(int i=0;i<criminals.size();i++){
			fn = criminals[i].fName;
			sn = criminals[i].lName;
			Cname = fn+" "+sn;
			if(Search(Cname,name)){
				criminals[i].showOnScreen();
				f = 0;
			}
		}
		if(f){
			cout << "No such criminal Available";
		}
	}
	
	
	void searchByPost(string po){
		bool f=1;
		for(int i=0;i<police.size();i++){
			if(Search(police[i].post,po)){
				police[i].showOnScreen();
				f=0;
			}
		}
		if(f){
			cout << "No such officer Available";
		}
	}
	
	void searchByCrime(string po){
		bool f=1;
		for(int i=0;i<criminals.size();i++){
			if(Search(criminals[i].crimes,po)){
				criminals[i].showOnScreen();
				f=0;
			}
		}
		if(f){
			cout << "No such criminal Available";
		}
	}
	
	void showPosts(){
		vector<string> pos;
		string s;
		cout << endl;
		for(int j=0;j<police.size();j++){
			int flag=0;
			s = police[j].post;
			for(int i=0;i<pos.size();i++){
				if(StrCmp(s,pos[i])){
					flag=1;
					break;
				}
			}
			if(flag==0){
				pos.push_back(s);
			}	
		}
		sort(pos.begin(),pos.end());
		
		for(int i=0;i<pos.size();i++){
			cout << pos[i]<<endl;
		}
		if(pos.size()==0){
			cout << "<Empty Set>"<<endl;
		}
		cout << endl;	
	}
	
		void showCrimes(){
		vector<string> pos;
		string s;
		cout << endl;
		for(int j=0;j<criminals.size();j++){
			int flag=0;
			s = criminals[j].crimes;
			for(int i=0;i<pos.size();i++){
				if(StrCmp(s,pos[i])){
					flag=1;
					break;
				}
			}
			if(flag==0){
				pos.push_back(s);
			}	
		}
		sort(pos.begin(),pos.end());
		
		for(int i=0;i<pos.size();i++){
			cout << pos[i]<<endl;
		}
		if(pos.size()==0){
			cout << "<Empty Set>"<<endl;
		}
		cout << endl;	
	}

	
	void findAo(){
		cout << endl << "1. Find Officer by Officer I'd";
		cout << endl << "2. Find Officer by Name";
		cout << endl << "3. Find Officer by Post";
		cout << endl << "4. Find Officer by Age";
		cout << endl << "5. Find Officer by Gender"<<endl<<endl;
		
		int n;
		cin >> n;
		cin.ignore();
		char input[100];
		switch(n){
			case 1:{
				cout << "Enter I'd: ";
				cin.getline(input,sizeof(input)); 
				searchByIdP(input);
				break;
			}
			case 2:{
				cout << "Enter Name: ";
				cin.getline(input,sizeof(input));
				searchByNameP(input);
				break;
			}
			case 3:{
				showPosts();
				cout << "Enter Post: ";
				cin.getline(input,sizeof(input));
				searchByPost(input);
				break;
			}
			case 4:{
				cout << "Enter Age: ";
				cin.getline(input,sizeof(input));
				int a = stoi(input);
				searchByageP(a);
				break;
			}
			case 5:{
				cout << "Enter gender: ";
				cin.getline(input,sizeof(input));
				searchBygenP(input);
				break;
			}
			default:{
				cout << "Invalid Choice"<<endl;
				break;
			}
		}
	}


		void findAc(){
		cout << endl << "1. Find Criminal by Criminal I'd";
		cout << endl << "2. Find Criminal by Name";
		cout << endl << "3. Find Criminal by Crime";
		cout << endl << "4. Find Criminal by Age";
		cout << endl << "5. Find Criminal by Gender";
		cout << endl << "6. Find Criminal by Birth Mark";
		cout << endl << "7. Find Criminal by Complexion";
		cout << endl << "8. List Criminal Caught By "<<endl<<endl;
		
		int n;
		cin >> n;
		cin.ignore();
		char input[100];
		switch(n){
			case 1:{
				cout << "Enter I'd: ";
				cin.getline(input,sizeof(input)); 
				searchByIdC(input);
				break;
			}
			case 2:{
				cout << "Enter Name: ";
				cin.getline(input,sizeof(input));
				searchByNameC(input);
				break;
			}
			case 3:{
				showCrimes();
				cout << "Enter Crime: ";
				cin.getline(input,sizeof(input));
				searchByCrime(input);
				break;
			}
			case 4:{
				cout << "Enter Age: ";
				cin.getline(input,sizeof(input));
				int a = stoi(input);
				searchByageC(a);
				break;
			}
			case 5:{
				cout << "Enter gender: ";
				cin.getline(input,sizeof(input));
				searchBygenC(input);
				break;
			}
			case 6:{
				cout << "Enter Birth Mark: ";
				cin.getline(input,sizeof(input));
				searchBybmC(input);
				break;
			}
			case 7:{
				cout << "Enter Complexion: ";
				cin.getline(input,sizeof(input));
				searchBycomC(input);
				break;
			}
			case 8:{
				cout << "Enter Officer Name: ";
				cin.getline(input,sizeof(input));
				searchBycbC(input);
				break;
			}
			default:{
				cout << "Invalid Choice"<<endl;
				break;
			}
		}
	}


	void guiInit(){
		cout << endl;
		cout << "1. Enter Officer information"<<endl;
		cout << "2. Enter Criminal information"<<endl;
		cout << "3. Show Officer Information"<<endl;
		cout << "4. Show Criminals Information"<<endl;
		cout << "5. Find a Officer"<<endl;
		cout << "6. Find a Criminal"<<endl;
		cout << "7. Delete Information"<<endl;
		cout << "8. Update Officer Information"<<endl;
		cout << "9. Update Criminal Information"<<endl;
		cout << "10. Change Password"<<endl;
		cout << "11. Exit"<<endl;
		cout << endl;
	}
	void init(){
		fileinout f;
		criminals = f.readFromFile();
		police = f.readFromFile(0);
		cout << "		--WELCOME--"<<endl;
	}
	void enterInfo(int n){
		char ch;
		string objinfo = "false";
		fileinout f;
		do{
			switch(n){
			case 1: {
				if(StrCmp(cp.post,"sp") || StrCmp(cp.post,"dsp") || StrCmp(cp.post,"Inspector")){
				tp.EnterInfo(police);
				if(!tp.match(police)){		
				f.writeToFile(tp);
				police.push_back(tp);				
				}
					objinfo = "Police Man";
				}else{
					cout << endl << "Permission Denied!!"<<endl;
				}
				
				break;
			}
			case 2:{
				if(StrCmp(cp.post,"sp") || StrCmp(cp.post,"dsp") || StrCmp(cp.post,"Inspector") || StrCmp(cp.post,"si")){
				tc.EnterInfo(criminals);
				if(!tc.match(criminals)){
				f.writeToFile(tc);
				criminals.push_back(tc);	
				}
				objinfo = "Criminal";
			}else{
				cout << endl << "Permission Denied!!"<<endl;
			}
				break;
			} 
			default:{
				cout << "Invalid Choice.."<<endl;
				return;
			}
		}
		if(objinfo == "false"){
			return;	
		}
		cout <<endl<< "Do you want to enter another "<< objinfo << " info (y/n): ";
		cin >> ch; 
		cin.ignore();
	}while(ch =='y');
	cout << endl <<"data recorded sucessfully" << endl;		
	}
	
	void shCmpInfo(int n){
		int size;
		if(n == 3){
			if(StrCmp(cp.post,"sp") || StrCmp(cp.post,"dsp") || StrCmp(cp.post,"Inspector")){
			size = police.size();
			if(size==0){
				cout << "No data Available"<<endl;
				return;
			}
			for(int i=0;i<size;i++){
				police[i].showOnScreen();
			}
			}else{
				cout << endl << "Permission Denied!!" <<endl;
			}
		}else if(n == 4){
			size = criminals.size();
			if(size==0){
				cout << "No data Available"<<endl;
				return;
			}
			for(int i=0;i<size;i++){
				criminals[i].showOnScreen();
			}
		}
	
	}
	
	void deleteInfo(){
		cout << endl << "1. Delete Officer Information"<<endl;
		cout << "2. Delete Criminal Information"<<endl;
		int n;
		char ch[100];
		cin >> n;
		cin.ignore();
		if(n==1){
			if(StrCmp(cp.post,"sp") || StrCmp(cp.post,"dsp")){
			cout << endl << "Enter Officer I'd: ";
			cin.getline(ch,sizeof(ch));
			deletePolice(ch);	
			}else{
				cout << endl << "Permission Denied!!" << endl;
			}
		}else if(n==2){
			if(StrCmp(cp.post,"sp")){
			cout << endl << "Enter Criminal I'd: ";
			cin.getline(ch,sizeof(ch));
			deleteCriminal(ch);	
			}else{
				cout << endl << "Permission Denied!!"<< endl;
			}
			
		}else{
			cout << endl << "Invalid Choice" <<endl;
		}
	}
};
