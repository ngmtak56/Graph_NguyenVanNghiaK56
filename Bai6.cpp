#include<iostream>
#include<fstream>
#include<map>
#define MAX 100
using namespace std;

const char input2_1[]="input2_1.txt";
const char output2_1[]="output2_1.txt";

void readFile(const char* fileName,int G[][MAX],int n){
	int i,j;
	ifstream file;
	file.open(fileName,ios::in);
	if(file==NULL){
		cout<<"File khong ton tai";
		return;
		}
	file>>n;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			
			}
		}
	file.close();
	}
void adjMatrixPrint(int G[][MAX],int n){
	int i,j;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
			if(G[i][j]==1)
			 	cout<<G[i][j]<<" ";
			}
		}
	}
void edgeListPrint(int G[][MAX],int n){
	int i,j;
	for(i=0; i<n; ++i){
		for(j=0; j<n; ++j){
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
void writeFile(const char* fileName,int G[][MAX],int n,map<int,int> count){
		
	}
int main(){
	return 0;
	}
