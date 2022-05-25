#include <bits/stdc++.h>
#include <fstream>
#include <time.h>
using namespace std;

const int V=80;   

class station_code{
    public:
    string station_name;
    int code;
    string color;
};
station_code station[V];
float graph[V][V];

class node1{
    public:
    vector <float>p;
};
node1 P[V];

string capitalize(string str){
    for(int i=0;i<str.length();++i)
    {
        if(str[i]>96&&str[i]<123)
            str[i]=str[i]-32;
    }
    return str;
}


void take_input();

void clrscreen(){
    system("cls");   
}

void delay(unsigned int msec){
    clock_t time = msec + clock();
    while( time > clock() );   
}

int timeconsumed(float distance){
    float velocity=0.70;
    return ceil(distance/velocity);
}

int cost(float distance){
    if(distance<=2)
        return 15;
    else if(distance > 2 && distance <= 5)
        return 25;
    else if(distance > 5 && distance <= 12)
        return 35;
    else if(distance > 12 && distance <= 21)
        return 45;
    else if(distance > 21 && distance <= 32)
        return 55;
    else
        return 70;
}

void Path(float distance,int dest,int st){
    int t=dest,s;
    
    cout<<"THE SHORTEST PATH IS : ";
    
    vector <int> path;
    path.push_back(t);
    while(t!=st){
        s=P[t].p.size();
        t=P[t].p[s-1];
        path.push_back(t);
    }
    vector <int>::iterator i=path.end();
    string str;
    string color;
    
    vector<int>::iterator i2=path.end();
    i2--;
    int n_of_stations=0;
    while(i!=path.begin())
    {
        i--;
        color=station[*i].color;
        
        if(i!=i2){
            if(station[*(i2)].color!=station[*(i)].color){
            cout<<"{change from "<<station[*i2].color<<" to "<<station[*i].color<<"}";   
        }
        i2--;
        }
        str=station[*i].station_name;
        cout<<" ->> "<<str;
        n_of_stations++;
        delay(700);
    }

    delay(700);
    
    cout<<endl<<"PATH LENGTH IS :";
    
    cout<<distance<<" KM"<<endl;
    delay(700);
   
    cout<<"AVERAGE TIME : ";
    
    cout<<timeconsumed(distance)<<" MIN"<<endl;
    delay(700);
   
    cout<<"AVERAGE FARE : ";
    
    cout<<" Rs. "<<cost(distance)<<endl;
    delay(700);
    
    cout<<"NO OF STATIONS : ";
    
    cout<<n_of_stations-1<<endl;
    return;
}

int distance_min(float distance[], bool visited[]){
   float min = INT_MAX;
   int min_index;

   for (int v = 0; v < V; v++)
     if (visited[v] == false && distance[v] <= min)
         min = distance[v], min_index = v;

   return min_index;
}

void dijkstra(float graph[V][V], int src,int targ){
     float distance[V];
     bool visited[V];
     for (int i = 0; i < V; i++)        
        distance[i] = INT_MAX, visited[i] = false;
     distance[src] = 0;
     for (int count = 0; count < V-1; count++)
     {
    int u = distance_min(distance, visited);
       visited[u] = true;
       for (int v = 0; v < V; v++)
         if (!visited[v] && graph[u][v] && distance[u] != INT_MAX
                                       && distance[u]+graph[u][v] < distance[v])
            {
                distance[v] = distance[u] + graph[u][v];
                P[v].p.push_back(u);
            }
     }
     Path(distance[targ],targ,src);
}

void window2(){
    clrscreen();
    take_input();
}

void take_input(){
        char ch;
        
        string startStation,endStation,line,col;
        int startcode,endcode;
       
        cout<<"ENTER THE STARTING POINT:";
       
    
        getline(cin,startStation);
       
        cout<<"ENTER THE DESTINATION POINT:";
        
        getline(cin,endStation);

        startStation=capitalize(startStation);
        endStation=capitalize(endStation);

        int flag_start=0,flag_end=0;

        for(int i=0;i<V;i++)
        {
            if(station[i].station_name==startStation)
            {
                startcode=station[i].code;
                flag_start=1;
            }
            if(station[i].station_name==endStation)
            {
                endcode=station[i].code;
                flag_end=1;
            }
        }
        int fault=0;
        if(flag_start==0)
        {
            cout<<"WRONG STARTING STATION NAME ENTERED"<<endl;
            fault=1;
        }

        if(flag_end==0)
        {   
            cout<<"WRONG DESTINATION STATION NAME ENTERED"<<endl;
            fault=1;
        }

        
        cin.get(ch);

      
        if(fault){
          window2();
        }

        dijkstra(graph, startcode,endcode);
}

void intro(){   
    cout<<endl; 
    cout<<"\t\t-----------------------------"<<endl;
    cout<<"\t\t|THIS PROJECT IS CREATED BY:|"<<endl;
    cout<<"\t\t|PRANAY YADAV - 9920103031  |"<<endl;
    cout<<"\t\t|NALIN BANGA - 9920103034   |"<<endl;
    cout<<"\t\t|AYUSH ANAND - 9920103043   |"<<endl;
    cout<<"\t\t|AYUSHI BAWARI - 9920103216 |"<<endl;
    cout<<"\t\t----------------------------"<<endl;

    cout<<"**************************************************************************************";
    cout<<endl;
    cout<<"\t\t WELCOME TO MINI DMRC"<<endl;
    cout<<endl<<"\t\t PRESS ENTER TO CONTINUE"<<endl;
    cout<<"**************************************************************************************";
    
    char ch;
    cin.get(ch);
    window2();
}


int main(){
    int temp,n1,n2;
    float dis;
    ifstream fin;
    ifstream code;
    ifstream color;
    code.open("stationname.txt");
    color.open("colorcodes.txt");
    fin.open("distvalues.txt");
    for(int i=0;i<V;++i){
       for(int j=0;j<V;++j)
        graph[i][j]=0;
    }

    for(int i=1;i<=V;++i){
        fin>>temp;
        fin>>n1;
        for(int j=0;j<temp;++j){
           fin>>n2;
           fin>>dis;
           graph[n1-1][n2-1]=dis;
        }
    }
    
    string name,col;
    for(int i=0;i<V;++i){
        getline(color,col);
        station[i].color=col;
        getline(code, name);
        station[i].code=i;
        station[i].station_name=name;
    }

    intro();
}
