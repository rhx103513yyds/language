/*
1.0
*/
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
//#pragma GCC optimize(3)
using namespace std;
#define int long long
#define sr srand(time(0))
string a[1005][1005];
string b[1005][1005];
unordered_map<string,int>result_score;
unordered_map<string,string>synthesize;
int Refresh;//ms
int score;
int hi;
int space_sqrare[1005][2];
int space;
int omd(int l,int r){
	return rand()%(r-l+1)+l;
}
bool __exit;
bool over;
void print_result(string s){
	int l=s.length();
	for(int i=1;i<=5-l;i++)cout<<" ";
	cout<<s;
}
void init(){
	hi=0;
	result_score["CE"]=2;
	result_score["JU"]=4;
	result_score["RE"]=8;
	result_score["TLE"]=16;
	result_score["MLE"]=32;
	result_score["ILE"]=64;
	result_score["OLE"]=128;
	result_score["UKE"]=256;
	result_score["WA"]=512;
	result_score["PC"]=1024;
	result_score["AC"]=2048;
	result_score["PE"]=4096;
	result_score["DOJ"]=8192;
	result_score["SJE"]=16384;
	result_score["AU"]=32768;
	result_score["AK"]=65536;
	synthesize["CE"]="JU";
	synthesize["JU"]="RE";
	synthesize["RE"]="TLE";
	synthesize["TLE"]="MLE";
	synthesize["MLE"]="ILE";
	synthesize["ILE"]="OLE";
	synthesize["OLE"]="UKE";
	synthesize["UKE"]="WA";
	synthesize["WA"]="PC";
	synthesize["PC"]="AC";
	synthesize["AC"]="PE";
	synthesize["PE"]="DOJ";
	synthesize["DOJ"]="SJE";
	synthesize["SJE"]="SJE";
	synthesize["AU"]="AK";
	synthesize["AK"]="???";
}
void reset(){
	sr;
	score=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			a[i][j]="_";
		}
	}
	int x1,y1;
	x1=omd(1,4);
	y1=omd(1,4);
	a[x1][y1]="CE";
	int x2=x1,y2=y1;
	while(x1==x2&&y1==y2){
		x2=omd(1,4);
		y2=omd(1,4);
	}
	a[x2][y2]="CE";
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			b[i][j]=a[i][j];
		}
	}
	space=14;
	int tmp=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			if(a[i][j]!="_")continue;
			tmp++;
			space_sqrare[tmp][0]=i;
			space_sqrare[tmp][1]=j;
		}
	}
}
void print(){
	system("cls");
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			print_result(a[i][j]);
		}
		if(i==1){
			cout<<"         score:"<<score<<" hi:"<<hi;
		}
		cout<<"\n";
	}
}
void printb(){
	system("cls");
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			print_result(b[i][j]);
		}
		cout<<"\n";
	}
//	cout<<"\n\n\n\n\n\n\n\n\n\n\n114514";
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout<<"Ë¢ÐÂ¼ä¸ô:(ms)";
	cin>>Refresh;
	sr;
	init();
//	reset();
//	printb();
//	return 0;
	while(!__exit){
		reset();
		while(!over){
			print();
			char c;
			c=getch();
			if(c==72){//¨¦? 
				bool change=0;
				for(int j=1;j<=4;j++){
					for(int i=1;i<=4;i++){
						if(b[i][j]=="_")continue;
						bool syn=0;
						int x=i,y=j;
						string tmp=b[x][y];
						b[x][y]="_";
						while(x>1){
							if(b[x-1][y]!="_"){
								if(b[x-1][y]==tmp){
									syn=1;
									change=1;
									b[x-1][y]=synthesize[b[x-1][y]];
									score+=result_score[b[x-1][y]];
//									space++;
									hi=max(hi,score);
								}
								break;
							}
							else {
								x--;
								change=1;
							}
						}
						if(!syn)b[x][y]=tmp;
					}
				}
				if(!change){
					for(int i=1;i<=4;i++){
						for(int j=1;j<=4;j++){
							b[i][j]=a[i][j];
						}
					}
					continue;
				}
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						a[i][j]=b[i][j];
					}
				}
				int x,y;
				int ran=(rand()-1)%space+1;
				x=space_sqrare[ran][0];
				y=space_sqrare[ran][1];
				bool r=rand()%2;
				print();
				Sleep(Refresh);
				if(r<1)a[x][y]="CE";
				else a[x][y]="JU";
				print();
				space=0;
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						b[i][j]=a[i][j];
						if(a[i][j]=="_"){
							space++;
							space_sqrare[space][0]=i;
							space_sqrare[space][1]=j;
						}
					}
				}
			}
			else if(c==80){//?? 
				bool change=0;
				for(int j=1;j<=4;j++){
					for(int i=4;i>=1;i--){
						if(b[i][j]=="_")continue;
						bool syn=0;
						int x=i,y=j;
						string tmp=b[x][y];
						b[x][y]="_";
						while(x<4){
							if(b[x+1][y]!="_"){
								if(b[x+1][y]==tmp){
									syn=1;
									change=1;
									b[x+1][y]=synthesize[b[x+1][y]];
									score+=result_score[b[x+1][y]];
//									space++;
									hi=max(hi,score);
								}
								break;
							}
							else {
								x++;
								change=1;
							}
						}
						if(!syn)b[x][y]=tmp;
					}
				}
				if(!change){
					for(int i=1;i<=4;i++){
						for(int j=1;j<=4;j++){
							b[i][j]=a[i][j];
						}
					}
					continue;
				}
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						a[i][j]=b[i][j];
					}
				}
				int x,y;
				int ran=(rand()-1)%space+1;
				x=space_sqrare[ran][0];
				y=space_sqrare[ran][1];
				bool r=rand()%2;
				print();
				Sleep(Refresh);
				if(r<1)a[x][y]="CE";
				else a[x][y]="JU";
				print();
				space=0;
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						b[i][j]=a[i][j];
						if(a[i][j]=="_"){
							space++;
							space_sqrare[space][0]=i;
							space_sqrare[space][1]=j;
						}
					}
				}
			}
			else if(c==75){//¡Á¨® 
				bool change=0;
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						if(b[i][j]=="_")continue;
						bool syn=0;
						int x=i,y=j;
						string tmp=b[x][y];
						b[x][y]="_";
						while(y>1){
							if(b[x][y-1]!="_"){
								if(b[x][y-1]==tmp){
									syn=1;
									change=1;
									b[x][y-1]=synthesize[b[x][y-1]];
									score+=result_score[b[x][y-1]];
//									space++;
									hi=max(hi,score);
								}
								break;
							}
							else {
								y--;
								change=1;
							}
						}
						if(!syn)b[x][y]=tmp;
					}
				}
				if(!change){
					for(int i=1;i<=4;i++){
						for(int j=1;j<=4;j++){
							b[i][j]=a[i][j];
						}
					}
					continue;
				}
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						a[i][j]=b[i][j];
					}
				}
				int x,y;
				int ran=(rand()-1)%space+1;
				x=space_sqrare[ran][0];
				y=space_sqrare[ran][1];
				bool r=rand()%2;
				print();
				Sleep(Refresh);
				if(r<1)a[x][y]="CE";
				else a[x][y]="JU";
				print();
				space=0;
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						b[i][j]=a[i][j];
						if(a[i][j]=="_"){
							space++;
							space_sqrare[space][0]=i;
							space_sqrare[space][1]=j;
						}
					}
				}
			}
			else if(c==77){//¨®¨° 
				bool change=0;
				for(int i=4;i>=1;i--){
					for(int j=4;j>=1;j--){
						if(b[i][j]=="_")continue;
						bool syn=0;
						int x=i,y=j;
						string tmp=b[x][y];
						b[x][y]="_";
						while(y<4){
							if(b[x][y+1]!="_"){
								if(b[x][y+1]==tmp){
									syn=1;
									change=1;
									b[x][y+1]=synthesize[b[x][y+1]];
									score+=result_score[b[x][y+1]];
//									space++;
									hi=max(hi,score);
								}
								break;
							}
							else {
								y++;
								change=1;
							}
						}
						if(!syn)b[x][y]=tmp;
					}
				}
				if(!change){
					for(int i=1;i<=4;i++){
						for(int j=1;j<=4;j++){
							b[i][j]=a[i][j];
						}
					}
					continue;
				}
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						a[i][j]=b[i][j];
					}
				}
				int x,y;
				int ran=(rand()-1)%space+1;
				x=space_sqrare[ran][0];
				y=space_sqrare[ran][1];
				bool r=rand()%2;
				print();
				Sleep(Refresh);
				if(r<1)a[x][y]="CE";
				else a[x][y]="JU";
				print();
				space=0;
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						b[i][j]=a[i][j];
						if(a[i][j]=="_"){
							space++;
							space_sqrare[space][0]=i;
							space_sqrare[space][1]=j;
						}
					}
				}
			}
			over=1;
			for(int i=1;i<=4;i++){
				for(int j=1;j<=4;j++){
					if(a[i+1][j]==a[i][j]){
						over=0;
					}
					if(a[i-1][j]==a[i][j]){
						over=0;
					}
					if(a[i][j+1]==a[i][j]){
						over=0;
					}
					if(a[i][j-1]==a[i][j]){
						over=0;
					}
				}
			}
			hi=max(hi,score);
//			__exit=1;
		}
	}
	return 0;
}

/*
By rhx(rhx103513yyds)
*/
