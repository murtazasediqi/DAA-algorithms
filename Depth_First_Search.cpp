#include<iostream>
#include <list>

using namespace std;
int start;

class Graph {
  int numVertices;
  list<int> *adjLists;
  bool *visited;

   public:
  Graph(int V);
  void addEdge(int src, int dest);
  void DFS(int vertex);
};

Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex +start<< " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}



int main()
{
	int nv,ne,dir,help,ep,stf,ext;
	begin:
	cout<<"Enter the no. of vertices : ";
	cin>>nv;
	
	cout<<"Enter the no. of edges : ";
	cin>>ne; 
	
	if(nv<0||ne<0){
		cout<<"\n\nError : no. of vertices or edges cannot be zero.\n\n";
		goto begin;
	}
	cout<<"Enter the no. from which graph starts : ";
	cin>>start;
	cout<<"Is the graph directional (0 = no/other number for yes) : ";
	cin>>dir;
	Graph g(nv);
	cout<<"Press 0 to enter edges manually or Press 1 to enter edges with help : ";
	cin>>help;
	cout<<endl;
	if(help==1){
    if(dir==0){
    	for(int i = 0;i<nv;i++){
    		for(int j = i;j<nv;j++){
    			cout<<"Is there a edge between "<<i+start<<" and "<<j+start<<" vertices :(0=n/1=y) : ";
    			cin>>ep;
    			if(ep==1){
    			g.addEdge(i,j);
				g.addEdge(j,i);	
				}
			}
		}
	}
	else{
		for(int i = 0;i<nv;i++){
    		for(int j = 0;j<nv;j++){
    			cout<<"Is there a edge between "<<i+start<<" and "<<j+start<<" vertices :(0=n/1=y) : ";
    			cin>>ep;
    			if(ep==1){
    			g.addEdge(i,j);	
				}
			}
		}
	}
   } 
   else if(help ==0){
	if(dir==0){
		while(ne!=0){
			int i,j;
			cout<<"Enter both vertices of an edge with a space between them : ";
			cin>>i>>j;
			g.addEdge(i-start,j-start);
			g.addEdge(j-start,i-start);
			ne--;
		}
	}
	else{
		while(ne!=0){
			int i,j;
			cout<<"Enter starting and ending vertices of an edge with a space between them : ";
			cin>>i>>j;
			g.addEdge(i-start,j-start);
			ne--;
		}
	}
   }  

    cout<<"\n\nEnter the vertex from which you want to start the traversal : ";
    cin>>stf;
	cout << "\n\nFollowing is Depth First Traversal "
		<< "(starting from vertex "<<stf<<") :   ";
	g.DFS(stf-start);
  cout<<"\n\nPress 1 to search again / any other key to exit : ";
  cin>>ext;
  if(ext == 1)
     goto begin;
	return 0;
}

