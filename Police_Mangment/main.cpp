#include "fio_manag.cpp"

class guiManage{
	public:
		vector<Criminal> criminals;
		vector<PoliceMan> police;
		Criminal tc;
		PoliceMan tp;
		
		
	guiManage(){
	
	}
	
	// authentication
	// show options according to permission
	//Update
	
	bool auth(){
		char offid[100],passw[100];
		cout << endl <<"Enter Officer I'd: ";
		cin.getline(offid,sizeof(offid));
		cout << "Enter Password: ";
		cin.getline(passw,sizeof(passw));
		for(int i=0;i<police.size();i++){
			if(StrCmp(police[i].officerid,offid)){
				//cout <<endl<<" pass "<< police[i].getPass() << "  word: "<<i<<endl;
				if(!strcmp(passw,police[i].getPass())){
					//guiInit();
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
			cout << "here";
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
		cout << "1. Enter Police information"<<endl;
		cout << "2. Enter Criminal information"<<endl;
		cout << "3. Show Police Men Information"<<endl;
		cout << "4. Show Criminals Information"<<endl;
		cout << "5. Find a Officer"<<endl;
		cout << "6. Find a Criminal"<<endl;
		cout << "7. Delete Information"<<endl;
		cout << "8. Exit"<<endl;
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
		string objinfo;
		fileinout f;
		do{
			switch(n){
			case 1: {
				tp.EnterInfo(police);
				if(!tp.match(police)){		
				f.writeToFile(tp);
				police.push_back(tp);	
				}
				objinfo = "Police Man";
				break;
			}
			case 2:{
				tc.EnterInfo(criminals);
				if(!tc.match(criminals)){
				f.writeToFile(tc);
				criminals.push_back(tc);	
				}
				objinfo = "Criminal";
				break;
			} 
			default:{
				cout << "Invalid Choice"<<endl;
				return;
			}
		}
		
		cout << "Do you want to enter another "<< objinfo << " info (y/n): ";
		cin >> ch; 
		cin.ignore();
	}while(ch =='y');
	cout << "data recorded sucessfully";		
	}
	
	void shCmpInfo(int n){
		int size;
		if(n == 3){
			size = police.size();
			if(size==0){
				cout << "No data Available"<<endl;
				return;
			}
			for(int i=0;i<size;i++){
				police[i].showOnScreen();
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
			cout << endl << "Enter Officer I'd: ";
			cin.getline(ch,sizeof(ch));
			deletePolice(ch);	
		}else if(n==2){
			cout << endl << "Enter Criminal I'd: ";
			cin.getline(ch,sizeof(ch));
			deleteCriminal(ch);
		}else{
			cout << endl << "Invalid Choice" <<endl;
		}
	}
};

int main(){
	guiManage gm;
	int n;
	bool con=1;
	//gm.auth();
	gm.init();
//	char t[100];
//	strcpy(t,"AyushAgarwal");
//	gm.police[0].setPass(t);
//	cout << gm.police[0].getPass();
	if(!gm.police.size() == 0){
	while(gm.auth());	
	}
	while(con){
	gm.guiInit();
	cin >> n;
	cout << endl;
	cin.ignore();
	switch(n){
		case 1:{
			gm.enterInfo(n);
			break;
		}
		case 2:{
			gm.enterInfo(n);
			break;
		}
		case 3:{
			gm.shCmpInfo(n);
			break;
		}
		case 4:{
			gm.shCmpInfo(n);
			break;
		}
		case 5:{
			gm.findAo();
			break;
		}
		case 6:{
			gm.findAc();
			break;
		}
		case 7:{
			gm.deleteInfo();
			break;
		}
		case 8:{
			con = 0;
			break;
		}
		default:{
			cout << "Wrong Choice"<<endl;
			break;
		}
	}	
	
	}
		
	return 0;
}
