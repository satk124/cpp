#include <iostream>
#include <string>
#include <climits>
#include <cstring>

using namespace std;
int dp[10][10];
int c[10][10];
int min(int a, int b){ 
	if(a>b) return b;
	else return a;
	}

int main(){
	string str;
	int beg, end;
	getline(cin, str);
	
	memset(dp, 0, sizeof(dp));
	memset(c, 0, sizeof(c));
	
	int len=str.length();
	
	for(int i=0; i<len; i++){
		dp[i][i]=1;
		c[i][i]=0;
	}
	for(int l=2; l<=len; l++){
		for(int i=0; i<len-l+1; i++){
			beg=i;
			end=i+l-1;
			if(l==2){				
				if(str[beg]==str[end]){
					dp[beg][end]=1;
				}
				else{
					dp[beg][end]=0;
				}
			}
			else {
				if(str[beg]!=str[end]) dp[beg][end]=0;
				else if(dp[beg+1][end-1]==1){
					dp[beg][end]=1;
				}
				else{
					dp[beg][end]=0;
				}
			}
			if(dp[beg][end]==1) c[beg][end]=0;
			else {
				c[beg][end]=INT_MAX;
				for(int j=beg; j<end; j++){
					c[beg][end]=min(c[beg][end], c[beg][j]+c[j+1][end]+1);
				}
			}	
							
		}
		
	}
	cout<<c[0][len-1]<<endl;
	
}

