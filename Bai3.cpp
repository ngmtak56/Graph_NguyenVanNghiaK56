#include<iostream>
#include<fstream>
#include<map>
#define MAX 100
using namespace std;

const char input1_1[]="input1_1.txt";
const char output1_1[]="output1_1.txt";

void createMatrix(int G[][MAX],int n){
	int i,j;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			G[i][j] = 0;	
			}
		}
	}
void readFile(const char*fileName,int G[][MAX],int &n){
	int x,y,i,j;
	ifstream file;
	file.open(fileName, ios::in);
	if(file==NULL){
		cout<<"File khong ton tai";
		return;
		}
	file>>n;
	createMatrix(G,n);	
	while(!file.eof()){
		file>>x;
		file>>y;
		G[x-1][y-1]=1;
		G[y-1][x-1]=1;
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
void edgeListPrint(int G[][MAX],int n){
	int i,j;
	cout<<"Danh sach canh: "<<endl;
	for(i=0; i<n; ++i){
		cout<<i+1<<" :";
		for(j=0; j<n; ++j){
			if(G[i][j]==1)
				cout<<" "<<j+1; 
			}
		cout<<endl; 
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
void writeFile(const char* fileName,int G[][MAX],int n,map<int,int> count){
	int i,j;
	ofstream file;
	file.open(fileName,ios::out);
	file<<n<<endl;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j)
			file<<G[i][j]<<" ";
		file<<endl;
		}
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			if(G[i][j]==1)
				file<<j+1;
			}
		file<<endl;
		}
	for(i=0; i<n; ++i)
		file<<count[i]<<endl;
	file.close();
	}
int main(){
	int G[MAX][MAX],n;
	map<int,int> count;
	readFile(input1_1,G,n);
	adjMatrixPrint(G,n);
	edgeListPrint(G,n);
	count = degTop(G,n);
	writeFile(output1_1,G,n,count);
	return 0;
	}
