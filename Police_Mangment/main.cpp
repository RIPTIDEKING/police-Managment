#include "guiclass.cpp"



int main(){
	guiManage gm;
	int n;
	bool con=1;
	gm.init();
	
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
			if(StrCmp(gm.cp.post,"sp") || StrCmp(gm.cp.post,"dsp") || StrCmp(gm.cp.post,"Inspector")){
			gm.findAo();
			}else{
				cout << endl << "Permission Denied!!"<<endl;
			}
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
			if(StrCmp(gm.cp.post,"sp") || StrCmp(gm.cp.post,"dsp")){
			gm.updatePolice();
		}else{
			cout << endl << "Permission Denied!!"<<endl;
		}
			break;
		}
		case 9:{
			if(StrCmp(gm.cp.post,"sp") || StrCmp(gm.cp.post,"dsp") || StrCmp(gm.cp.post,"Inspector")){
			gm.updateCriminal();
		}else{
			cout << endl << "Permission Denied!!"<<endl;
		}
			break;
		}
		case 10:{
			gm.chgPass();
			break;
		}
		case 11:{
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
