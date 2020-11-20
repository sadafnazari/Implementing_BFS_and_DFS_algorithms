#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "Queuee.h"
using namespace std;
int map[10][10] = {{0, 0, 0, -1, 0, 0, 0, 0, 0,2},
                   {0, -1, -1, -1, -1, -1, 0, -1, -1,-1},
                   {0, -1, 0, -1, 0, 0, 0, 0, 0,0},
                   {0, -1, 0, -1, 0, -1, -1, -1, 0,-1},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0,-1},
                   {0, 0, -1, -1, -1, -1, -1, 0, -1,-1},
                   {-1, 0, 0, 0, 0, 0, -1, 0, -1,0},
                   {0, -1, 0, -1, 0, -1, -1, 0, -1,0},
                   {-1, -1, 0, -1, 0, 0, 0, 0, 0,0},
                   {1, 0, 0, -1, -1, -1, -1, -1, -1,0}}; //main map
bool marked[10][10];
int parent[10][10];
void print_map();
int convertor(int, int);
void bfs();
void dfs();
int main()
{
    for(int i=0 ; i<10 ; i++)
        for(int j=0 ; j<10 ; j++)
           {
               marked[i][j] = false;
               parent[i][j] = -1;
           }
    print_map();
    cout<<"solve with :\n1)bfs\n2)dfs\n";
    int c;
    cin>>c;
    if(c==1)
        bfs();
    else if(c==2)
        dfs();

    return 0;
}
void print_map()
{
    for(int i=0 ; i<40 ; i++)
    {
        cout<<"-";
    }
    cout<<endl;
    for(int i=0; i<10 ; i++)
    {
        cout<<"|";
        for(int j=0 ; j<10 ; j++)
        {
            cout<<" ";
            if(map[i][j] == 0 /*|| map[i][j] == 3*/)
                cout<<" ";
            else if(map[i][j] == -1)//wall
                cout<<"#";
            else if(map[i][j] == 1)//food
                cout<<"&";
            else if (map[i][j] == 2)//agent
                    cout<<"*";
            else if (map[i][j] == 3)//Path
                    cout<<"%";
            cout<<" |";
        }
        cout<<endl;
        for(int i=0 ; i<40 ; i++)
        {
            cout<<"-";
        }
        cout<<endl;
    }
    cout<<"* : Agent, &: Food, #: Wall, %: Path\n";
}
void bfs()
{
    Queuee q;
    int row , col ,row1, col1;
    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<10 ; j++)
        {
            if(map[i][j] == 2)
            {
                row = i;
                col = j;
                break;
            }
        }
    }
    marked[row][col] = true;
    int i = row , j = col;
    if(i-1 >= 0 && map[i-1][j] != -1)
    {
        q.Insert(convertor(i-1, j));
        parent[i-1][j] = convertor(i,j);
    }
    if(i+1 < 10 && map[i+1][j] != -1)
    {
        q.Insert(convertor(i+1, j));
        parent[i+1][j] = convertor(i,j);
    }
    if(j-1 >=0 && map[i][j-1] != -1)
    {
        q.Insert(convertor(i, j-1));
        parent[i][j-1] = convertor(i,j);
    }
    if(j+1 < 10 && map[i][j+1] != -1)
    {
        q.Insert(convertor(i, j+1));
        parent[i][j+1] = convertor(i,j);
    }
    q.Display();
    while(q.frontt != -1 )
    {
        i = (q.queuee[q.frontt]) /10;
        j = (q.queuee[q.frontt]) %10;
        //cout<<q.queuee[q.frontt]<<" "<<i<<" "<<j<<endl;
        if(map[i][j] == 1)
        {
            cout<<"Win\n";
            break;
        }
        marked[i][j] = true;
        if(i-1 >=0 && map[i-1][j] !=-1 && !marked[i-1][j] )
        {
            bool b1 = false;
            for(int m=q.frontt ; m<=q.rear ; m++)
            {
                if(q.queuee[m] == convertor(i-1,j))
                {
                    b1 = true;
                    break;
                }
            }
            if(!b1)
            {
                q.Insert(convertor(i-1, j));
                parent[i-1][j] = convertor(i,j);
            }
        }
        if(i+1 < 10 && map[i+1][j] !=-1 && !marked[i+1][j])
        {
            bool b2 = false;
            for(int m=q.frontt ; m<=q.rear ; m++)
            {
                if(q.queuee[m] == convertor(i+1,j))
                {
                    b2 = true;
                    break;
                }
            }
            if(!b2)
            {
                q.Insert(convertor(i+1, j));
                parent[i+1][j] = convertor(i,j);
            }
        }
        if(j-1 >=0 && map[i][j-1] !=-1 && !marked[i][j-1])
        {

            bool b3 = false;
            for(int m=q.frontt ; m<=q.rear ; m++)
            {
                if(q.queuee[m] == convertor(i,j-1))
                {
                    b3 = true;
                    break;
                }
            }
            if(!b3)
            {
                q.Insert(convertor(i, j-1));
                parent[i][j-1] = convertor(i,j);
            }
        }
        if(j+1 < 10 && map[i][j+1] ==0 && !marked[i][j+1])
        {
            bool b4 = false;
            for(int m=q.frontt ; m<=q.rear ; m++)
            {
                if(q.queuee[m] == convertor(i,j+1))
                {
                    b4 = true;
                    break;
                }
            }
            if(!b4)
            {
                q.Insert(convertor(i, j+1));
                parent[i][j+1] = convertor(i,j);
            }
        }
        q.Delete();
        //q.Display();
    }
    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<10 ; j++)
        {
            if(map[i][j] == 1)
            {
                row1 = i;
                col1 = j;
                break;
            }
        }
    }
    int m = row1 , n = col1;
    while(parent[row1][col1] != convertor(row, col))
    {
        int c = parent[row1][col1];
        row1 = c/10;
        col1 = c%10;
        map[row1][col1] = 3;
    }
    print_map();

}
void dfs()
{
    vector<int> q;
    int row , col ,row1, col1;
    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<10 ; j++)
        {
            if(map[i][j] == 2)
            {
                row = i;
                col = j;
                break;
            }
        }
    }
    marked[row][col] = true;
    int i = row , j = col;
    if(i-1 >= 0 && map[i-1][j] != -1)
    {
        q.push_back(convertor(i-1, j));
        parent[i-1][j] = convertor(i,j);
    }
    if(i+1 < 10 && map[i+1][j] != -1)
    {
        q.push_back(convertor(i+1, j));
        parent[i+1][j] = convertor(i,j);
    }
    if(j-1 >=0 && map[i][j-1] != -1)
    {
        q.push_back(convertor(i, j-1));
        parent[i][j-1] = convertor(i,j);
    }
    if(j+1 < 10 && map[i][j+1] != -1)
    {
        q.push_back(convertor(i, j+1));
        parent[i][j+1] = convertor(i,j);
    }
    while(q.size() != 0)
    {
        i = (q.at(q.size()-1)) /10;
        j = (q.at(q.size()-1)) %10;
        q.pop_back();
        if(map[i][j] == 1)
        {
            cout<<"Win\n";
            break;
        }
        marked[i][j] = true;
        if(i-1 >=0 && map[i-1][j] !=-1 && !marked[i-1][j] )
        {
            bool b1 = false;
            for(int l=0 ; l<q.size() ; l++)
            {
                if(q.at(l) == convertor(i-1,j))
                {
                    b1 = true;
                    break;
                }
            }
            if(!b1)
            {
                q.push_back(convertor(i-1, j));
                parent[i-1][j] = convertor(i,j);
            }
        }
        if(i+1 < 10 && map[i+1][j] !=-1 && !marked[i+1][j])
        {
            bool b2 = false;
            for(int l=0 ; l<q.size() ; l++)
            {
                if(q.at(l) == convertor(i+1,j))
                {
                    b2 = true;
                    break;
                }
            }
            if(!b2)
            {
                q.push_back(convertor(i+1, j));
                parent[i+1][j] = convertor(i,j);
            }
        }
        if(j-1 >=0 && map[i][j-1] !=-1 && !marked[i][j-1])
        {
            bool b3 = false;
            for(int l=0 ; l<q.size() ; l++)
            {
                if(q.at(l) == convertor(i,j-1))
                {
                    b3 = true;
                    break;
                }
            }
            if(!b3)
            {
                q.push_back(convertor(i, j-1));
                parent[i][j-1] = convertor(i,j);
            }
        }
        if(j+1 < 10 && map[i][j+1] ==0 && !marked[i][j+1])
        {
            bool b4 = false;
            for(int l=0 ; l<q.size() ; l++)
            {
                if(q.at(l) == convertor(i,j+1))
                {
                    b4 = true;
                    break;
                }
            }
            if(!b4)
            {
                q.push_back(convertor(i, j+1));
                parent[i][j+1] = convertor(i,j);
            }
        }
    }
    for(int i=0 ; i<10 ; i++)
    {
        for(int j=0 ; j<10 ; j++)
        {
            if(map[i][j] == 1)
            {
                row1 = i;
                col1 = j;
                break;
            }
        }
    }
    int m = row1 , n = col1;
    while(parent[row1][col1] != convertor(row, col))
    {
        int c = parent[row1][col1];
        row1 = c/10;
        col1 = c%10;
        map[row1][col1] = 3;
    }
    print_map();

}

int convertor(int i, int j)
{
    return i*10 + j;
}

