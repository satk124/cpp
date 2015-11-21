#include <iostream>
#include <cstring>
#include <climits>

using namespace std;
int arr[] = {80, 60, 30, 40, 20, 10};
int idp[100];
int ddp[100];

int main(){
	int sz=sizeof(arr)/sizeof(arr[0]);	
	
	for(int i=0; i<sz; i++){
		idp[i]=1;		
		if(i==0) continue;		
		for(int j=0; j<i; j++){			
			if(idp[j]+1>idp[i] && arr[i]>arr[j]){
				idp[i]=idp[j]+1;						
			}
		}
	}	
	for(int i=sz-1; i>=0; i--){
		ddp[i]=1;		
		if(i==sz-1) continue;		
		for(int j=sz-1; j>i; j--){			
			if(ddp[j]+1>ddp[i] && arr[i]>arr[j]){
				ddp[i]=ddp[j]+1;						
			}
		}
	}
	int max=INT_MIN;
	for(int i=0; i<sz; i++){
		cout<<idp[i]<<" ";
		if(max<idp[i]+ddp[i]) max=idp[i]+ddp[i];
	}
	cout<<endl;
	for(int i=0; i<sz; i++){
		cout<<ddp[i]<<" ";
	}
	cout<<endl;
	cout<<max-1<<endl;
	return 0;	
} 

