#include<bits/stdc++.h>
using namespace std;

string s,command;
vector<string>a,a2;

bool check(){
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++){
			if(a2[i][j]=='E'){
				if(a[i][j]!='B')return 0;
			}
		}
	}
	return 1;
}

int main(int argc,char **argv){
	fstream file(argv[1],ios::in);
	if(!file){
		cout<<"�ɮ׶}�ҥ���!";
		
	}
	system("cls");
	int dx[5]={0,-1,0,1,0},dy[5]={0,0,-1,0,1},x,y,ex,ey;
	int flag=0,com=0;stack<int>lcomm;
	map<string,int>comm;
	comm["w"]=1,comm["a"]=2,comm["s"]=3,comm["d"]=4;
	while(file>>s){
		for(int i=0;i<s.size()&&(!flag);i++){
			if(s[i]=='A'){
				x=a.size(),y=i,flag=1;
			}
		}
		a.push_back(s);
	}
	a2=a;
	for(int i=0;i<a.size();i++){
		for(int j=0;j<a[i].size();j++)cout<<a[i][j];
		cout<<endl;
	}
	cout<<endl;
	cout<<"�п�J���O(�X�k���O�u��w(���W),a(����),s(���U),d(���k)�M�j�gR(�_��))\n";
	cout<<"(�_��i�H�_���Ĥ@�B):"; 
	while(cin>>command){
		if(command!="w"&&command!="a"&&command!="s"&&command!="d"&&command!="R"){
			cout<<"��J���~!\n";
		}
		else {
			if(command=="R"){
				if(lcomm.size()){
					int lcom=lcomm.top();lcomm.pop();
					a[x-dx[lcom]][y-dy[lcom]]='A';x-=dx[lcom],y-=dy[lcom];
					if(a[x+2*dx[com]][y+2*dy[com]]=='B'){
						a[x+dx[lcom]][y+dy[lcom]]='B';
						a[x+2*dx[lcom]][y+2*dy[lcom]]='*';
					}
					else{
						a[x+dx[lcom]][y+dy[lcom]]='*';
					}
				}
				else{
					cout<<"�w�g�S���W�@�B�i�H�_��FQQ\n";
				}
			}
			else{
				com=comm[command];
				if(a[x+dx[com]][y+dy[com]]=='*'||a[x+dx[com]][y+dy[com]]=='E'){
					a[x][y]='*';
					x+=dx[com],y+=dy[com];
					a[x][y]='A';
					lcomm.push(com);
				}
				else if(a[x+dx[com]][y+dy[com]]=='B'&&(a[x+2*dx[com]][y+2*dy[com]]=='*'||a[x+2*dx[com]][y+2*dy[com]]=='E')){
					a[x+2*dx[com]][y+2*dy[com]]='B',a[x+dx[com]][y+dy[com]]='A';
					a[x][y]='*';x+=dx[com],y+=dy[com];
					lcomm.push(com);
				}
			}
		}
		system("cls");
		for(int i=0;i<a.size();i++){
			for(int j=0;j<a[i].size();j++){
				if(a[i][j]=='*'&&a2[i][j]=='E')a[i][j]=a2[i][j];
				cout<<a[i][j];
			}
			cout<<endl;
		}
		cout<<endl;
		if(check())break;
		cout<<"�п�J���O(�X�k���O�u��w(���W),a(����),s(���U),d(���k)�M�j�gR)\n";
		cout<<"(�j�gR�N��_��̫�@�Ӱʧ@):";
	}
	cout<<"CONGRATULATIONS! YOU WIN THE GAME!\n";
}
