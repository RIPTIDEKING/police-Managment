#include <bits/stdc++.h>
#include <string.h>
using namespace std;

string toStr(int n){
	ostringstream s;
	s << n;
	return s.str();
}
int toInt(string s){
	stringstream ss(s);
	int x = 0;
	ss >> x;
	return x;
}
bool StrCmp(string a, string b){
	if(a.length()!=b.length())
		return 0;
	else{
		for(int i=0;i<b.length();i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 0;
		}
	}
	return 1;
}
int Search(char a[], char b[]){
		for(int i=0;i<strlen(b);i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 0;
		}
	return 1;
}
bool Search(string a, string b){
		for(int i=0;i<b.size();i++){
			if(toupper(a[i])!=toupper(b[i]))
				return 0;
		}
	return 1;
}

class encryption{
	public:
		string encrpt(string orignal){
			string mess="",tmess = "";
			char temp;
			int len = orignal.length();
			int counter;
			if(len > 129){
				counter = 129;
				for(int i= 129;i<len;i++){
					temp = orignal[i]+i-129+1;
					tmess += temp;
				}
			}else{
				counter = len;
			}
			for(int i=0;i<counter;i++){
				temp = orignal[i]+i+1;
				mess += temp;
			}
			return mess+tmess;
		}
		string dcrpt(string mess){
			string orignal="",tmess="";
			char temp;
			int len = mess.length();
			int counter;
			if(len > 129){
				counter = 129;
				for(int i= 129;i<len;i++){
					temp = orignal[i]-i-129-1;
					tmess += temp;
				}
			}else{
				counter = len;
			}
			for(int i=0;i<counter;i++){
				temp = mess[i]-i-1;
				orignal += temp;
			}
			return orignal+tmess;
		}
};

char* chg(string input){
	char *rt = new char[100];
	for(int i=0;i<input.size();i++){
		rt[i]= input[i];
	}
	return rt;
}

