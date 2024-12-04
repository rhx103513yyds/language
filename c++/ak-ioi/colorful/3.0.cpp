/*
3.0
使每个评测结果只能合并一次，并在合并中使用了全新写法，减少了一点代码长度
*/
#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
//#pragma GCC optimize(3)
using namespace std;
#define int long long
#define sr srand(time(0))
void SetConsoleColor(WORD wAttributes) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, wAttributes);
}
string a[1005][1005];
string b[1005][1005];
int walk[1005][2];
int ci[1005][3];
int cj[1005][3];
unordered_map<string,int>result_score;
unordered_map<string,unordered_map<string,string> >synthesize;
unordered_map<string,unordered_map<string,bool> >can_syn;
bool syned[1005][1005];
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
	if(s=="CE")SetConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN);
	if(s=="JU")SetConsoleColor(FOREGROUND_BLUE);
	if(s=="RE")SetConsoleColor(FOREGROUND_RED|FOREGROUND_BLUE);
	if(s=="TLE")SetConsoleColor(FOREGROUND_BLUE);
	if(s=="MLE")SetConsoleColor(FOREGROUND_BLUE);
	if(s=="ILE")SetConsoleColor(FOREGROUND_BLUE);
	if(s=="OLE")SetConsoleColor(FOREGROUND_BLUE);
	if(s=="UKE")SetConsoleColor((FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE)|(0));
	if(s=="WA")SetConsoleColor(FOREGROUND_RED);
	if(s=="PC")SetConsoleColor(FOREGROUND_RED|(FOREGROUND_RED|FOREGROUND_GREEN));
	if(s=="AC")SetConsoleColor(FOREGROUND_GREEN);
	if(s=="PE")SetConsoleColor((FOREGROUND_RED)|(FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE));
	if(s=="DOJ")SetConsoleColor((FOREGROUND_RED|FOREGROUND_GREEN)|(0));
	if(s=="SJE")SetConsoleColor((FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE)|(0));
	if(s=="AU")SetConsoleColor(FOREGROUND_RED|FOREGROUND_GREEN);
	if(s=="AK")SetConsoleColor(FOREGROUND_BLUE);
	if(s=="_")SetConsoleColor(FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
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
	
	  synthesize["CE"]["CE"]="JU";
	  synthesize["JU"]["JU"]="RE";
	  synthesize["RE"]["RE"]="TLE";
	synthesize["TLE"]["TLE"]="MLE";
	synthesize["MLE"]["MLE"]="ILE";
	synthesize["ILE"]["ILE"]="OLE";
	synthesize["OLE"]["OLE"]="UKE";
	synthesize["UKE"]["UKE"]="WA";
	  synthesize["WA"]["WA"]="PC";
	  synthesize["PC"]["PC"]="AC";
	  synthesize["AC"]["AC"]="PE";
	  synthesize["PE"]["PE"]="DOJ";
	synthesize["DOJ"]["DOJ"]="SJE";
	synthesize["SJE"]["SJE"]="AU";
	  synthesize["AU"]["AU"]="AK";
	  synthesize["AK"]["AK"]="AK";
	    synthesize["#"]["#"]="O2";
	  synthesize["O2"]["O2"]="O3";
	
	 can_syn["CE"]["CE"]=1;
	 can_syn["JU"]["JU"]=1;
	 can_syn["RE"]["RE"]=1;
	can_syn["TLE"]["TLE"]=1;
	can_syn["MLE"]["MLE"]=1;
	can_syn["ILE"]["ILE"]=1;
	can_syn["OLE"]["OLE"]=1;
	can_syn["UKE"]["UKE"]=1;
	 can_syn["WA"]["WA"]=1;
	 can_syn["PC"]["PC"]=1;
	 can_syn["AC"]["AC"]=1;
	 can_syn["PE"]["PE"]=1;
	can_syn["DOJ"]["DOJ"]=1;
	can_syn["SJE"]["SJE"]=1;
	  can_syn["#"]["#"]=1;
	 can_syn["O2"]["O2"]=1;
	
	 synthesize["CE"]["#"]="CE";
	 synthesize["JU"]["#"]="JU";
	 synthesize["RE"]["#"]="RE";
	synthesize["TLE"]["#"]="TLE";
	synthesize["MLE"]["#"]="MLE";
	synthesize["ILE"]["#"]="ILE";
	synthesize["OLE"]["#"]="OLE";
	synthesize["UKE"]["#"]="UKE";
	 synthesize["WA"]["#"]="WA";
	 synthesize["PC"]["#"]="PC";
	 synthesize["AC"]["#"]="AC";
	 synthesize["PE"]["#"]="PE";
	synthesize["DOJ"]["#"]="DOJ";
	synthesize["SJE"]["#"]="SJE";
	 synthesize["AU"]["#"]="AU";
	 synthesize["AK"]["#"]="AK";
	
	 can_syn["CE"]["#"]=1;
	 can_syn["JU"]["#"]=1;
	 can_syn["RE"]["#"]=1;
	can_syn["TLE"]["#"]=1;
	can_syn["MLE"]["#"]=1;
	can_syn["ILE"]["#"]=1;
	can_syn["OLE"]["#"]=1;
	can_syn["UKE"]["#"]=1;
	 can_syn["WA"]["#"]=1;
	 can_syn["PC"]["#"]=1;
	 can_syn["AC"]["#"]=1;
	 can_syn["PE"]["#"]=1;
	can_syn["DOJ"]["#"]=1;
	can_syn["SJE"]["#"]=1;
	 can_syn["AU"]["#"]=1;
	 can_syn["AK"]["#"]=1;
	
	 synthesize["CE"]["O2"]="JU";
	 synthesize["JU"]["O2"]="RE";
	 synthesize["RE"]["O2"]="TLE";
	synthesize["TLE"]["O2"]="MLE";
	synthesize["MLE"]["O2"]="ILE";
	synthesize["ILE"]["O2"]="OLE";
	synthesize["OLE"]["O2"]="UKE";
	synthesize["UKE"]["O2"]="WA";
	 synthesize["WA"]["O2"]="PC";
	 synthesize["PC"]["O2"]="AC";
	 synthesize["AC"]["O2"]="PE";
	 synthesize["PE"]["O2"]="DOJ";
	synthesize["DOJ"]["O2"]="SJE";
	synthesize["SJE"]["O2"]="AU";
	 synthesize["AU"]["O2"]="AK";
	
	
	 can_syn["CE"]["O2"]=1;
	 can_syn["JU"]["O2"]=1;
	 can_syn["RE"]["O2"]=1;
	can_syn["TLE"]["O2"]=1;
	can_syn["MLE"]["O2"]=1;
	can_syn["ILE"]["O2"]=1;
	can_syn["OLE"]["O2"]=1;
	can_syn["UKE"]["O2"]=1;
	 can_syn["WA"]["O2"]=1;
	 can_syn["PC"]["O2"]=1;
	 can_syn["AC"]["O2"]=1;
	 can_syn["PE"]["O2"]=1;
	can_syn["DOJ"]["O2"]=1;
	can_syn["SJE"]["O2"]=1;
	 can_syn["AU"]["O2"]=1;
	
	 synthesize["CE"]["O3"]="RE";
	 synthesize["JU"]["O3"]="TLE";
	 synthesize["RE"]["O3"]="MLE";
	synthesize["TLE"]["O3"]="ILE";
	synthesize["MLE"]["O3"]="OLE";
	synthesize["ILE"]["O3"]="UKE";
	synthesize["OLE"]["O3"]="WA";
	synthesize["UKE"]["O3"]="PC";
	 synthesize["WA"]["O3"]="AC";
	 synthesize["PC"]["O3"]="PE";
	 synthesize["AC"]["O3"]="DOJ";
	 synthesize["PE"]["O3"]="SJE";
	synthesize["DOJ"]["O3"]="AU";
	synthesize["SJE"]["O3"]="AK";
	
	 can_syn["CE"]["O3"]=1;
	 can_syn["JU"]["O3"]=1;
	 can_syn["RE"]["O3"]=1;
	can_syn["TLE"]["O3"]=1;
	can_syn["MLE"]["O3"]=1;
	can_syn["ILE"]["O3"]=1;
	can_syn["OLE"]["O3"]=1;
	can_syn["UKE"]["O3"]=1;
	 can_syn["WA"]["O3"]=1;
	 can_syn["PC"]["O3"]=1;
	 can_syn["AC"]["O3"]=1;
	 can_syn["PE"]["O3"]=1;
	can_syn["DOJ"]["O3"]=1;
	can_syn["SJE"]["O3"]=1;
	
	walk[72][0]=-1;
	walk[72][1]=0;
	walk[80][0]=1;
	walk[80][1]=0;
	walk[75][0]=0;
	walk[75][1]=-1;
	walk[77][0]=0;
	walk[77][1]=1;
	
	ci[72][0]=1;
	ci[72][1]=4;
	ci[72][2]=1;
	cj[72][0]=1;
	cj[72][1]=4;
	cj[72][2]=1;
	
	ci[80][0]=4;
	ci[80][1]=1;
	ci[80][2]=-1;
	cj[80][0]=1;
	cj[80][1]=4;
	cj[80][2]=1;
	
	ci[75][0]=1;
	ci[75][1]=4;
	ci[75][2]=1;
	cj[75][0]=1;
	cj[75][1]=4;
	cj[75][2]=1;
	
	ci[77][0]=4;
	ci[77][1]=1;
	ci[77][2]=-1;
	cj[77][0]=4;
	cj[77][1]=1;
	cj[77][2]=-1;
	
	for(auto i:synthesize){
		for(auto j:i.second){
			synthesize[j.first][i.first]=j.second;
		}
	}
	for(auto i:can_syn){
		for(auto j:i.second){
			can_syn[j.first][i.first]=j.second;
		}
	}
}
void reset(){
	sr;
	score=0;
	over=0;
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
//	system("color F");
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
			print_result(a[i][j]);
		}
		if(i==1){
			SetConsoleColor(FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
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
bool pd(char c,int x,int y){
	if(c==72)return x>1;
	if(c==80)return x<4;
	if(c==75)return y>1;
	if(c==77)return y<4;
}
signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout<<"刷新间隔:(ms)";
	cin>>Refresh;
	sr;
	init();
//	reset();
//	printb();
//	return 0;
	while(!__exit){
		reset();
//		bool flag=0;
		while(!over){
			memset(syned,0,sizeof(syned));
			print();
			char c;
//			if(flag);
//			else 
			c=getch();
//			flag=0;
//			cout<<space<<"\n";
			if(c==72||c==80||c==75||c==77){
				bool change=0;
				for(int i=ci[c][0];ci[c][2]*i<=ci[c][2]*ci[c][1];i+=ci[c][2]){
					for(int j=cj[c][0];cj[c][2]*j<=cj[c][2]*cj[c][1];j+=cj[c][2]){
						if(b[i][j]=="_")continue;
						if(syned[i][j]==1)continue;
						bool syn=0;
						bool times=0;
						int x=i,y=j;
						string tmp=b[x][y];
						b[x][y]="_";
						bool tm=syned[x][y];
						syned[x][y];
						while(pd(c,x,y)){
							if(b[x+walk[c][0]][y+walk[c][1]]!="_"){
								cout<<x<<" "<<y<<"\n";
								if(can_syn[b[x+walk[c][0]][y+walk[c][1]]][tmp]&&!syned[x+walk[c][0]][y+walk[c][1]]){
									syn=1;
									change=1;
									b[x+walk[c][0]][y+walk[c][1]]=synthesize[b[x+walk[c][0]][y+walk[c][1]]][tmp];
									score+=result_score[b[x+walk[c][0]][y+walk[c][1]]];
									hi=max(hi,score);
								}
								break;
							}
							else {
								x+=walk[c][0];
								y+=walk[c][1];
								change=1;
							}
						}
						if(!syn)b[x][y]=tmp,syned[x][y]=tm;
						else syned[x][y]=1;
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
			}
			if(c==72||c==80||c==75||c==77){
				print();
				int x,y;
				space=0;
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						if(a[i][j]=="_"){
							space++;
							space_sqrare[space][0]=i;
							space_sqrare[space][1]=j;
						}
					}
				}
				int ran=(rand()-1)%space+1;
				x=space_sqrare[ran][0];
				y=space_sqrare[ran][1];
				bool r=rand()%4;
				Sleep(Refresh);
				if(r<1)a[x][y]="CE";
				else if(r<2)a[x][y]="JU";
				else if(r<3)a[x][y]="#";
				else if(r<4)a[x][y]="O2";
//				a[x][y]="#";
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
			bool ffff=0;
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
					if(a[i][j]=="_"||a[i][j]=="#"||a[i][j]=="O2"||a[i][j]=="O3"){
						ffff=1;
					}
				}
			}
			if(ffff)over=0;
			if(over){
				system("cls");
				SetConsoleColor(FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED);
				cout<<"Game over!\n";
				cout<<"score:"<<score<<"\n";
				for(int i=1;i<=4;i++){
					for(int j=1;j<=4;j++){
						print_result(a[i][j]);
					}
					cout<<"\n";
				}
				getch();
//				flag=1;
//				while((c=getch()));
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
