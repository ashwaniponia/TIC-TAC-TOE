#include<bits/stdc++.h>
using namespace std;
class game{
  int sx,sy;
  int chance;
  int *ar;
public:
  game(){
  chance=-1;
  sx=sy=0;
  ar=new int[9];
    for(int i=0;i<9;i++)
      ar[i]=-1;
  }
  ~game(){
    delete [] ar;
  }
  void grid();
  void game_over();
  void new_game();
  void load_menu();
  void printToCoordinates(int x, int y);
  void get_data(int);
  void reset();
  bool all_full();
  bool win(int);
  int mode_select();
  int v_s_comp();

};

int game::v_s_comp(){
  int mov=rand()%9;
  while(ar[mov]!=-1){
   mov=rand()%8;
  }
return mov;
}

int game:: mode_select(){
int ch;
cout<<"\n\n+++++++++++++++++++++++\n";
cout<<"\n1. 2 Player Mode";
cout<<"\n2. V/s COMPUTER";
cout<<"\nEnter your choice:";
cin>>ch;
return ch;
}

bool game::win(int temp){
int w[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

for(int i=0;i<8;i++){
  if(ar[w[i][0]]==temp && ar[w[i][1]]==temp && ar[w[i][2]]==temp )
  return true;
}
return false;
}

void game::reset(){
  for(int i=0;i<9;i++)
        ar[i]=-1;
}

bool game::all_full(){
  int count=0;
  for(int i=0;i<9;i++)
      if(ar[i]==-1)
    return false;
return true;
}

void game::get_data(int ch){
  int x,y;
  if(ch!=2){
  if(ch==0)
  cout<<"\nEnter your MOVE Player 1:";
  else
  cout<<"\nEnter your MOVE Player 2:";
  cin>>x>>y;
  int temp=x*3+y;
  if(ar[temp]==-1)
  {if(ch==0){
    ar[temp]=0;
    return;
  }else if(ch==1){
    ar[temp]=1;
    return;
  }
  }
  else{
    cout<<"\nINVALID CHOICE.....PLS ENTER VALID MOVE:";
    get_data(ch);
  }
}else{
    if(chance==-1){
    ar[v_s_comp()]=1;
    chance=1;
    return;
    }
   else if(chance==1){
     cout<<"\nEnter your MOVE Player 1:";
     cin>>x>>y;
     int temp=x*3+y;
     if(ar[temp]==-1){
       ar[temp]=0;
       chance=-1;
       return;
     }
   }else{
       cout<<"\nINVALID CHOICE.....PLS ENTER VALID MOVE:";
       get_data(ch);
     }
   }
}



void game::printToCoordinates(int x, int y)
{
    printf("\033[%d;%dH\n", x, x);
}

void game::load_menu(){
using namespace std::this_thread;
using namespace std::chrono;
int i,j=0;
int var;
for( i=0;i<=50;i++){
  system("clear");
  var=i*2;
   cout<<"\n\t\t\t    Loading "<<var<<"%"<<'\n'<<'\t';
  if(i==50)
  break;
  for( j=1;j<i;j++)
    cout<<"#";
  sleep_for(milliseconds(150-i*3));
}

if(var==100)
  cout<<"\t\t LOADING COMPLETED "<<'\n';
  sleep_for(milliseconds(1000));
    new_game();
}

void game::new_game(){
  reset();
  int mod=mode_select();
  grid();
  int x,y;
  cout<<"\n-------------------------------------------------------------------\n";
  if(mod==1)
  mod=0;
  while(1){
   get_data(mod);
   grid();
   if(win(1)){sx++;
    break;
  }else if(win(0)){
    sy++;
    break;
  }else if(all_full()){
    cout<<"\t\t\t\t\nDRAW\n";
    break;
  }
   if(mod==0)
   mod=1;
   else if(mod==1)
   mod=0;
   }
  game_over();
}

void game::grid(){
  map<int,char>m;
  m[0]='O';
  m[1]='X';
  m[-1]='E';
  system("clear");
  cout<<"\n\n\n";

  cout<<"\t\t  TIC TAC TOE"<<endl;
  cout<<"            |                    |            "<<endl;
  cout<<"\t"<<m[ar[0]]<<"   |"<<"\t\t"<<m[ar[1]]<<"        |"<<"\t"<<m[ar[2]]<<" "<<endl;
  cout<<"            |                    |            "<<endl;
  cout<<"----------------------------------------------"<<endl;
  cout<<"            |                    |            "<<endl;
cout<<"\t"<<m[ar[3]]<<"   |"<<"\t\t"<<m[ar[4]]<<"        |"<<"\t"<<m[ar[5]]<<" "<<endl;
  cout<<"            |                    |            "<<endl;
  cout<<"----------------------------------------------"<<endl;
  cout<<"            |                    |            "<<endl;
cout<<"\t"<<m[ar[6]]<<"   |"<<"\t\t"<<m[ar[7]]<<"        |"<<"\t"<<m[ar[8]]<<" "<<endl;
  cout<<"            |                    |            "<<endl;
}

void game::game_over(){
  int choice;
  cout<<"\n\n";
  cout<<"\t\t\tGAME OVER "<<endl;
  cout<<"\n-----------------\n";
  if(sx!=sy){
  if(sx>sy)
  cout<<"First Player Won";
  else
  cout<<"Second Player Won";
  cout<<"! CONGRATULATIONS....:>)";
  cout<<"\nYOUR SCORE:"<<sx<<"\nSCORE OF SECOND PLAYER:"<<sy<<endl;
}
  while(1){
  cout<<"\n\t\tWANT TO CONTINUE ?"<<endl;
  cout<<"1.YES 2.NO:";
  cin>>choice;
  if(choice == 1)
  new_game();
  else if(choice==2){
    cout<<"\n...........EXITING....................\n"<<endl;
     break;
  }
  else if(choice!=1 && choice!=2 )
  cout<<"\nPLS ENTER A VALID CHOICE.......:<(";
}
}

int main(){
  game obj;
  obj.load_menu();
  return 0;
}
