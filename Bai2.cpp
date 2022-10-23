#include<iostream>
#include<fstream>
#define MAX 100
using namespace std;

const char input1[] = "input1.txt";
const char input1_1[]="input1_1.txt";
const char input1_2[]="input1_2.txt";

//----------------------Doc file------------------------
void readFile(const char *fileName,int G[][MAX],int &n){
	ifstream file;
	file.open(fileName, ios::in);
	if(file==NULL){
		cout<<"File khong ton tai";
		return;
		}
	file>>n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			file>>G[i][j];
			}
		}
	file.close();
	}
//--------------In danh sach ke/canh--------------
void edgeListPrint(int G[][MAX],int n,int target){
	int i,j;
	if(target==1){
		cout<<"Danh sach ke: "<<endl; 
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				if(G[i][j] == 1 && i<j)
					cout<<i+1<<" : "<<j+1<<endl;
				}	
			}
		}
	if(target==2){
		cout<<"Danh sach canh: "<<endl;
		for(i=0; i<n; ++i){
			cout<<i+1<<" : ";
			for(j=0; j<n; ++j){
				if(G[i][j]==1)
					cout<<" "<<j+1; 
				}
			cout<<endl; 
			}
		}
	}
//-------------------------Luu vao file----------------------------
void writeFile(const char *fileName,int G[][MAX],int n,int target){
	int i,j;
	ofstream file;
	file.open(fileName,ios::out);
	if(target==1){  //Danh sach ke
		file<<n<<endl;
		for(i=0; i<n; ++i){
		 	for(j=0; j<n; ++j){
		 		if(G[i][j]==1 && i<j)
		 			file<<i+1<<" "<<j+1<<endl;
				}
		 	}
		}
	if(target==2){  //Danh sach canh
		file<<n<<endl;
		for(i=0; i<n; ++i){
			for(j=0; j<n; ++j){
				if(G[i][j]==1)
					file<<j+1;
				}
			file<<endl;
			}
		}
	file.close();
	}
int main(){
	int G[MAX][MAX],n;
	readFile(input1,G,n);	//Doc du lieu tu file input1
	edgeListPrint(G,n,1);
	edgeListPrint(G,n,2);
	writeFile(input1_1,G,n,1); //Luu vao file input1_1
	writeFile(input1_2,G,n,2); //Luu vao file input1_2
	return 0;
	} 
