#include<iostream>
#include<fstream>
#include<sstream>
#include<map>
#define MAX 100
using namespace std;

const char input1_2[]="input1_2.txt";
const char output1_2[]="output1_2.txt";

void createMatrix(int G[][MAX],int n){
	int i,j;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			G[i][j] = 0;	
			}
		}
	}
void readFile(const char*fileName,int G[][MAX],int &n){
	int i,j,num[MAX];
	char ch[MAX];
	string str;
	ifstream file;
	file.open(fileName,ios::in);
	if(file==NULL){
		cout<<"File khong ton tai";
		return;
		}
	file>>n;
	createMatrix(G,n);
	for(i=0; i<n; ++i){
		file>>str;
		for(j=0; j<str.length(); ++j){
			ch[j] = str[j];
			num[j] = int(ch[j])-48;
			G[i][num[j]-1]=1;
			}
		}
	file.close();
	}
void adjMatrixPrint(int G[][MAX],int n){
	int i,j;
	cout<<"Ma tran ke: "<<endl;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j)
			cout<<G[i][j]<<" ";
		cout<<endl;
		}		
	}
void adjListPrint(int G[][MAX],int n){
	int i,j;
	cout<<"Danh sach ke: "<<endl; 
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			if(G[i][j] == 1 && i<j)
				cout<<i+1<<" : "<<j+1<<endl;
			}	
		}
	}
map<int,int> degTop(int G[][MAX],int n){
	int i,j;
	map<int,int> count;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			if(G[i][j]==1)
				count[i]++;
			}
		}
	cout<<"Bac cua dinh: "<<endl;
	for(i=0; i<n; ++i)
		cout<<"Deg("<<i+1<<") = "<<count[i]<<endl;
	return count;
	}
void writeFile(const char*fileName,int G[][MAX],int n,map<int,int> count){
	int i,j;
	FILE *file;
	file = fopen(fileName,"w");
	fprintf(file,"%d\n",n);
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j)
			fprintf(file,"%d ",G[i][j]);
		fprintf(file,"\n");
		}
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			if(G[i][j]==1 && i<j)
				fprintf(file,"%d %d\n",i+1,j+1);
			}
		}	
	for(i=0; i<n; ++i)
		fprintf(file,"%d\n",count[i]);
	fclose(file);
	}
int main(){
	int G[MAX][MAX],n;
	map<int,int> count;
	readFile(input1_2,G,n);
	adjMatrixPrint(G,n);
	adjListPrint(G,n);
	count=degTop(G,n);
	writeFile(output1_2,G,n,count);
	return 0;
	}
