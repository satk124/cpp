#include <iostream>
#include <cstring>
#include <climits>
#include <string>
// palindromic sequence using dynamic programming.
using namespace std;
string s;
int dp[25][25];

int len(int l, int h){
	cout<<l<<" "<<h<<endl;
	if(dp[l][h]!=0) return dp[l][h];	
	else if(l==h) return dp[l][h]=1;
	else if(l==h-1 && s[l]==s[h]) return dp[l][h]=2;
	// if(l==h-1 && s[l]!=s[h]) return dp[l][h]=0;
	else if(s[l]==s[h]) return dp[l][h]=2+len(l+1,h-1);
	else {
		int t1=len(l, h-1);
		int t2=len(l+1, h);
		int t3=t1>t2?t1:t2;		
		return dp[l][h]=t3;
	}
}

int main(){
	getline(cin, s);
	
	
/*  dp=new int * [s.length()];
	for(unsigned int i=0; i<s.length(); i++){
		dp[i]=new int[s.length()];
	}
	
	for(unsigned int i=0; i<s.length(); i++){
		for(unsigned int j=0; i<s.length(); j++){
			cout<<dp[i][j]<<"| ";
		}		
		cout<<endl;
	} */
		
	memset(dp, 0 , sizeof(dp));
	cout<<endl;
	cout<<len(0, s.length()-1);	
	for(unsigned int i=0; i<=s.length(); i++){
		for(unsigned int j=0; j<=s.length(); j++){
			cout<<dp[i][j]<<"| ";
		}		
		cout<<endl;
	}
	
}
