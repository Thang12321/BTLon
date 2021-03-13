#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void nhapdulieu(int &n,int &m,int &k)
{
    cin>>n>>m>>k;
}
char **sinhbandoHienMin (int n,int m,int k)
{
    char **bando = new char*[n+5];
    for(int i=0; i<m+5; i++)
        bando[i]=new char;
    for(int i=0; i<=n+2; i++)
        for(int j=0; j<=m+2; j++)
            bando[i][j]='#';
    for(int i=0; i<k; i++)
    {
        int x,y;
        do
        {
            x=rand()%n +1;
            y=rand()%m +1;
        }
        while(bando[x][y]!='#');
        bando[x][y]='*';
    }
    return bando;
}
char ** sinhbandoKhongHienMin(int n,int m)
{
    char **bando = new char*[n+5];
    for(int i=0; i<m+5; i++)
        bando[i]=new char;
    for(int i=0; i<=n+2; i++)
        for(int j=0; j<=m+2; j++)
            bando[i][j]='#';
    return bando;
}
bool **sinhmangKiemTraDaMo(int n,int m)
{
    bool **DaMo= new bool *[n+5];
    for(int i=0;i<m+5;i++)
        DaMo[i]=new bool;
    for(int i=0; i<=n+2; i++)
        for(int j=0; j<=m+2; j++)
           DaMo[i][j]=false;

           return DaMo;
}
void inbando(char **bando,int n,int m)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cout<<bando[i][j]<<' ';
        cout<<endl;
    }
}
int demxungquanh(char ** Map,int x,int y )
{
    int demminxungquanh=0;
    if(Map[x+1][y]=='*')
        demminxungquanh++;
    if(Map[x+1][y+1]=='*')
        demminxungquanh++;
    if(Map[x+1][y-1]=='*')
        demminxungquanh++;
    if(Map[x][y+1]=='*')
        demminxungquanh++;
    if(Map[x][y-1]=='*')
        demminxungquanh++;
    if(Map[x-1][y]=='*')
        demminxungquanh++;
    if(Map[x-1][y-1]=='*')
        demminxungquanh++;
    if(Map[x-1][y+1]=='*')
        demminxungquanh++;
    return demminxungquanh;
}
void Modiem(char **Map, char **MapDisplay, int x,int y)
{
     int demmin=demxungquanh(Map,x,y);
            MapDisplay[x][y]=char(demmin+48);
}
bool damphaimin(char **Map,int x,int y)
{
    if(Map[x][y]=='*')
        return true;
        else return false;
}
void loang(char **Map,char ** MapDisplay, int x,int y, int n,int m,bool ** DaMo)
{
// x+1
if(DaMo[x+1][y]==0&&x+1<=n&&Map[x+1][y]=='#')
{DaMo[x+1][y]=1;
    Modiem(Map,MapDisplay,x+1,y);
    int demmin=demxungquanh(Map,x+1,y);
  if(demmin==0)  loang(Map,MapDisplay,x+1,y,n,m,DaMo);
}
if(DaMo[x+1][y+1]==0&&x+1<=n&&y+1<=m&&Map[x+1][y+1]=='#')
{DaMo[x+1][y+1]=1;
    Modiem(Map,MapDisplay,x+1,y+1);
      int demmin=demxungquanh(Map,x+1,y+1);
  if(demmin==0)   loang(Map,MapDisplay,x+1,y+1,n,m,DaMo);
}
if(DaMo[x+1][y-1]==0&&x+1<=n&&y-1>=1&&Map[x+1][y-1]=='#')
{DaMo[x+1][y-1]=1;
     Modiem(Map,MapDisplay,x+1,y-1);
      int demmin=demxungquanh(Map,x+1,y-1);
  if(demmin==0)   loang(Map,MapDisplay,x+1,y-1,n,m,DaMo);
}
//x
if(DaMo[x][y+1]==0&&y+1<=m&&Map[x][y+1]=='#')
{DaMo[x][y+1]=1;
    Modiem(Map,MapDisplay,x,y+1);
      int demmin=demxungquanh(Map,x,y+1);
  if(demmin==0)   loang(Map,MapDisplay,x,y+1,n,m,DaMo);
}
if(DaMo[x][y-1]==0&&y-1>=1&&Map[x][y-1]=='#')
{DaMo[x][y-1]=1;
    Modiem(Map,MapDisplay,x,y-1);
      int demmin=demxungquanh(Map,x,y-1);
  if(demmin==0)   loang(Map,MapDisplay,x,y-1,n,m,DaMo);
}
//x-1
if(DaMo[x-1][y]==0&&x-1>=1&&Map[x-1][y]=='#')
{DaMo[x-1][y]=1;
    Modiem(Map,MapDisplay,x-1,y);
      int demmin=demxungquanh(Map,x-1,y);
  if(demmin==0)   loang(Map,MapDisplay,x-1,y,n,m,DaMo);
}
if(DaMo[x-1][y-1]==0&&x-1>=1&&y-1>=1&&Map[x-1][y-1]=='#')
{DaMo[x-1][y-1]=1;
    Modiem(Map,MapDisplay,x-1,y-1);
      int demmin=demxungquanh(Map,x-1,y-1);
  if(demmin==0)   loang(Map,MapDisplay,x-1,y-1,n,m,DaMo);
}
if(DaMo[x-1][y+1]==0&&x-1>=1&&y+1<=m&&Map[x-1][y+1]=='#')
{DaMo[x-1][y+1]=1;
    Modiem(Map,MapDisplay,x-1,y+1);
      int demmin=demxungquanh(Map,x-1,y+1);
  if(demmin==0)   loang(Map,MapDisplay,x-1,y+1,n,m,DaMo);
}

}
void choigame(char ** Map, char ** MapDisplay, int n,int m,bool ** DaMo)
{
    while(true)
    {
        inbando(MapDisplay,m,n);
        int x,y;
        cout<<"Nhap toa do (x;y) :";
        cin>>x>>y;
        if(damphaimin(Map,x,y)==true)
        {
            cout<<"YOU'RE DEAD!"<<endl;
            inbando(Map,n,m);
            exit(0);
        }
        else
        {
        int demmin=demxungquanh(Map,x,y);
Modiem(Map,MapDisplay,x,y);
if(demmin==0) loang(Map,MapDisplay,x,y,n,m,DaMo);


        }
    }
}
int main()
{
    srand(time(0));
    int n,m,k;


    nhapdulieu(n,m,k);
bool **DaMo=sinhmangKiemTraDaMo(n,m);
    char ** Map=sinhbandoHienMin(n,m,k);
    inbando(Map,n,m);
    cout<<endl;
    char ** MapDisplay=sinhbandoKhongHienMin(n,m);
    choigame(Map,MapDisplay,n,m,DaMo);

}
