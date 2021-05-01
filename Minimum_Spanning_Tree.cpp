#include <bits/stdc++.h>
using namespace std;


int minKey(int key[], bool mstSet[], int V)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

void printMST(int parent[], int **graph, int V, int strt)
{
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout<<parent[i]+strt<<" - "<<i+strt<<" \t"<<graph[i][parent[i]]<<" \n";
}

void primMST(int **graph,int V, int strt)
{
	// Array to store constructed MST
	int parent[V];
	
	// Key values used to pick minimum weight edge in cut
	int key[V];
	
	// To represent set of vertices included in MST
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	// Always include first 1st vertex in MST.
	// Make key 0 so that this vertex is picked as first vertex.
	key[0] = 0;
	parent[0] = -1; // First node is always root of MST

	// The MST will have V vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum key vertex from the
		// set of vertices not yet included in MST
		int u = minKey(key, mstSet, V);

		// Add the picked vertex to the MST Set
		mstSet[u] = true;

		// Update key value and parent index of
		// the adjacent vertices of the picked vertex.
		// Consider only those vertices which are not
		// yet included in MST
		for (int v = 0; v < V; v++)

			// graph[u][v] is non zero only for adjacent vertices of m
			// mstSet[v] is false for vertices not yet included in MST
			// Update the key only if graph[u][v] is smaller than key[v]
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// print the constructed MST
	printMST(parent, graph, V, strt);
}

// Driver code
int main()
{
	int nv,ne,start,help,ew,ext;
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
	
	int **graph = new int*[nv];
	for(int i=0;i<nv;i++){
		graph[i]=new int[nv];
	}
    for(int i=0;i<nv;i++){
        for(int j=0;j<nv;j++){
        	graph[i][j]=0;
		}	
	}
	
	cout<<"Press 0 to enter edges manually or Press 1 to enter edges with help : ";
	cin>>help;
	cout<<endl;
	if(help==1){
		for(int i = 0;i<nv;i++){
    		for(int j = i;j<nv;j++){
    		  err1:
    			cout<<"Enter weight of the edge between "<<i+start<<" and "<<j+start<<" vertices :(0 if no edge present) : ";
    			cin>>ew;
    			if(ew>=0){
    				graph[i][j]=ew;
					graph[j][i]=ew;	
				}
				else{
					cout<<"\n\nError : weight of an edge cannot be zero.\n\n";
					goto err1;
				}
			}
		}
   } 
   else if(help ==0){
	
		while(ne!=0){
			int i,j;
			cout<<"Enter starting vertex, ending vertex  and weight of an edge with a space between all of them : ";
			cin>>i>>j>>ew;
			graph[i-start][j-start]=ew;
			graph[j-start][i-start]=ew;	
			ne--;
		}
	}  

   /* cout<<"\n\nEnter the vertex from which you want to start the traversal : ";
    cin>>stf;
	cout << "\n\nFollowing is Breadth First Traversal "
		<< "(starting from vertex "<<stf<<") :   ";
	g.BFS(stf-start,start);*/
	primMST(graph,nv,start);
  cout<<"\n\nPress 1 to search again / any other key to exit : ";
  cin>>ext;
  if(ext == 1)
     goto begin;
	return 0;

	// Print the solution

	return 0;
}

// This code is contributed by rathbhupendra

