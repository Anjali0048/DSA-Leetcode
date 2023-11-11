class Graph {
public:
    vector<vector<pair<int,int>>> adjList;

    Graph(int n, vector<vector<int>>& edges) {
        adjList.resize(n);
        for(auto edge : edges){
            adjList[edge[0]].emplace_back(edge[1],edge[2]);
        }
    }
    
    void addEdge(vector<int> edge) {
        adjList[edge[0]].emplace_back(edge[1],edge[2]);   
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);   
    }

    int dijkstra(int start, int end){
        int n = adjList.size();
        vector<int> dist(n, INT_MAX);
        dist[start] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> priorityQueue;
        priorityQueue.push({0,start});

        while(!priorityQueue.empty()){
            int currNode = priorityQueue.top().second;
            int currCost = priorityQueue.top().first;
            priorityQueue.pop();

            if(currCost > dist[currNode])
                continue;

            if(currNode == end)
                return currCost;
            
            for(auto edge : adjList[currNode]){
                int neigh = edge.first;
                int edgeLength = edge.second;
                int newRouteCost = edgeLength + dist[currNode];

                if(dist[neigh] > newRouteCost){
                    dist[neigh] = newRouteCost;
                    priorityQueue.push({ newRouteCost, neigh });
                }
            }
        }
        return ((dist[end] == INT_MAX) ? -1 : dist[end]);
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */