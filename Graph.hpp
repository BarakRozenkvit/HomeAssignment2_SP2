//// @author:314638669, Barak10101998@gmail.com
#include <vector>
#pragma once
#define INF INT32_MAX

using namespace std;

namespace ariel {

    class Graph {

        vector<vector<int>> _adjMatrix;
        int _edges = 0;
        bool _isDirected = false;
        bool _isNegativeEdges = false;


    public:

        Graph();

        void loadGraph(vector<vector<int>> graph);

        void printGraph();

        vector<vector<int>>& getAdjMatrix(){
            return _adjMatrix;
        }
        bool isDirected(){
            return _isDirected;
        }
        int getEdges(){
            return _edges;
        }
        bool getisNegativeEdges(){
            return _isNegativeEdges;
        }
        void addS();

        // 6 Arithmetiacl
        Graph& operator+=(Graph &g);
        Graph& operator-=(Graph &g1);
        Graph& operator+();
        Graph& operator-();
        friend Graph operator+(Graph &g1,Graph &g2);
        friend Graph operator-(Graph &g1,Graph &g2);

        // 6 Comperison
        friend bool operator>(Graph &g1,Graph &g2);
        friend bool operator>=(Graph &g1,Graph &g2);
        friend bool operator<(Graph &g1,Graph &g2);
        friend bool operator<=(Graph &g1,Graph &g2);
        friend bool operator==(Graph &g1,Graph &g2);
        friend bool operator!=(Graph &g1,Graph &g2);

        // Inc and Dec
        Graph& operator++();
        Graph& operator--();

        // Multiply by Scalar
        Graph& operator*=(int n);
        Graph& operator/=(int n);
        friend Graph operator*(Graph &g,int n);

        // Graph Multiplication
        friend Graph operator*(Graph &g1,Graph &g2);

        // Output
        friend std::ostream& operator<<(std::ostream& out,Graph &g);
    };
}
