#include<iostream>
#include<vector>
using namespace std;
class graph
{
    private:
    int vertices;
    vector<vector<int>>adjlist;
    public:
    graph(int vertices)
    {
        this->vertices=vertices;
        adjlist.resize(vertices,vector<int>(vertices,0));
    }
    void addedge(int v,int w)
    {
        adjlist[v][w]=1;
        adjlist[w][v]=1;
    }
    void printadjacencymatrix()
    {
        for(int i=0;i<vertices;++i)
        {
            for(int j=0;j<vertices;++j)
            {
                cout<<adjlist[i][j]<<"  ";
            }
            cout<<endl;
        }
    }   
};
int main()
{
    int v=8;
    graph g(v);
    g.addedge(1,0);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,0);
    g.addedge(2,2);
    g.addedge(2,5);
    g.addedge(6,7);
    g.addedge(5,6);
    g.addedge(5,7);
    g.printadjacencymatrix();
    return 0;
}