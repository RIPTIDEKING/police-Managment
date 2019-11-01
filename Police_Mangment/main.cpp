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
	

	void guiInit(){
		cout << endl;
		cout << "1. Enter Police information"<<endl;
		cout << "2. Enter Criminal information"<<endl;
		cout << "3. Show Police Men Information"<<endl;
		cout << "4. Show Criminals Information"<<endl;
		cout << "5. Exit"<<endl;
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
