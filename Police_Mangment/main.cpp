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
	// search
	// edit
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
	void findAo(){
		cout << endl << "1. Find Officer by Officer I'd";
		cout << endl << "2. Find Officer by Name";
		cout << endl << "3. Find Officer by Post"<<endl<<endl;
		
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
		cout << "6. Exit"<<endl;
		cout << endl;
	}
	void init(){
		fileinout f;
		criminals = f.readFromFile();
		police = f.readFromFile(0);
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
};

int main(){
	guiManage gm;
	int n;
	bool con=1;
	gm.init();
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
