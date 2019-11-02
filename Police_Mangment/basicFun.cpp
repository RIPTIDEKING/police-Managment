#include <bits/stdc++.h>
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
