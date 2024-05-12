//// @author:314638669, Barak10101998@gmail.com
#include "Graph.hpp"
#include <string>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

namespace ariel{

    class Algorithms{

    private:
        /**
         * The single source shortest path algorithm of Dijkstra for non negative weighted and non weighted graph
         * Reference: https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/
         * @param g Graph
         * @param src Source Vertex
         * @return List of Pie for each v
         */
        static vector<int> Dijkstra(Graph &g,int src);
        /**
         * the 2-Coloring-Graph algorithm
         * Reference: Algorithms 1 - Tirgul 4
         * @param g Graph
         * @return tree of data:
         *          data.first = boolean if it possible
         *          data.second = Array of diviation of 2 groups
         */
        static pair<bool,vector<int>> twoColoringGraph(Graph &g);
        /**
         * this Function Transposes the graph
         * @param g Graph
         * @return gT - Transposed Graph
         */
        static Graph Transpose(Graph &g);
        /**
         * this function is edge relaxation on edge e=(u,v)
         * Referance: Algorithms 1 - Lecture 10 (Based on slides by Prof. Dana Shapira)
         * @param g Graph
         * @param u Vertice
         * @param v Vertice
         * @param d List of Distances for each v to Source Vertice
         * @param pie List of Pie for each v (the Pie is vertice before v that is in the shortestPath) Source Vertice
         * @return true or false if edge is relaxed
         */
        static bool relax(Graph &g,int u, int v,vector<int> &d,vector<int> &pie);
        /**
         * The single source shortest path algorithm of Bellman Ford for non negative and negative weighted graph
         * Referance: Algorithms 1 - Lecture 10 (Based on slides by Prof. Dana Shapira)
         * @param g Graph
         * @param src Source Vertice
         * @return Tree of data
         *         data.first.first = List of Pie for each v
         *         data.first.second = List of d for each v
         *         data.second.first = boolean if there is a negative cycle
         *         data.second.second = the v that is start and the end of the negative cycle
         */
        static pair<pair<vector<int>,vector<int>>,pair<bool,int>> BellmanFord(Graph &g,int src);
        /**
         * this function creates the path String
         * @param vertices List of Pie for each v
         * @param src Source Vertice
         * @param dest Destination Vertice
         * @return String of path "src->...->dest"
         */
        static string pathString(vector<int> &vertices ,int src,int dest);
        /**
         * The Depth-first-search algorithm
         * Referance: Algorithms 1 - Lecture 6 (Based on slides by Prof. Dana Shapira)
         * @param g Graph
         * @param orderOfVertices order of vertices to scan DFS
         * @return Tree of data
         *         data.first.first = List of f(final time) for each v
         *         data.first.second = List of Pie for each v
         *         data.second.first = Vertice of Cycle
         *         data.second.second = Vertice of Cycle
         */
        static pair<pair<stack<int>,vector<int>>,pair<int,int>> DFS(Graph &g,stack<int> &orderOfVertices);
        /**
         * The DFS_Visit part of DFS algorithm
         * Referance: Algorithms 1 - Lecture 6 (Based on slides by Prof. Dana Shapira)
         * @param g Graph
         * @param u Source Vertice
         * @param d List of d(start time) for each v
         * @param f List of f(finish time) for each v
         * @param pie List of Pie for each v
         * @param color List of color for each v
         * @param time current time
         * @param isCycle boolean if there is a cycle in graph
         * @param vStartCycle the v that is start and the end of the cycle
         */
        static void DFS_Visit(Graph &g,int u,
                              vector<int> &d,stack<int> &f,
                              vector<int> &pie,vector<string> &color,
                              int &time,int &vStartCycle,int &vEndCycle);

    public:
        /**
         * Reference: Algorithms 1 - Lecture 6 (Based on slides by Prof. Dana Shapira)
         * the Kosaraju algorithm for strongly connection components - checking if only one strongly connected component
         * @param g Graph
         * @return true or false
         */
        static bool isConnected(Graph &g);
        /**
         * This function calculates the shortest path from src to dest
         * @param g: Graph
         * @param src: Source Vertice
         * @param dest: Destination Vertice
         * @return String of path "src->...->dest", if no path "-1"
         */
        static string shortestPath(Graph &g,int src,int dest);
        /**
         * This function calculate if there is a cycle in the graph
         * @param g Graph
         * @return String of cycle "a->...->a" if there is a negative cycle, "0" if there isn't
         */
        static string isContainsCycle(Graph &g);
        /**
         * this function calculate if the graph is Bipartite
         * @param g Graph
         * @return String of two groups of vertices "A={...}, B={...}", if not "0";
         */
        static string isBipartite(Graph &g);
        /**
         * This function calculates if there's a negative cycle in the graph
         * @param g Graph
         * @return String of cycle "a->...->a" if there is a negative cycle, "0" if there isn't
         */
        static string negativeCycle(Graph g);
    };
}