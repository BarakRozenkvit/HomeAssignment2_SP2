//// @author:314638669, Barak10101998@gmail.com
#include <vector>
#include <string>
#include <iostream>
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
        Graph(): _edges(0), _isDirected(false), _isNegativeEdges(false), _adjMatrix({}){};

        void loadGraph(vector<vector<int>> graph);

        string printGraph();

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

        Graph& operator+=(Graph &g);
        Graph& operator-=(Graph &g1);

        Graph operator+();
        Graph operator-();

        Graph operator+(Graph &g);
        Graph operator-(Graph &g);

        bool operator>(Graph &g2);
        bool operator>=(Graph &g2);
        bool operator<(Graph &g2);
        bool operator<=(Graph &g2);
        bool operator==(Graph &g2);
        bool operator!=(Graph &g2);

        Graph& operator++();
        Graph& operator--();
        Graph operator++(int);
        Graph operator--(int);

        Graph& operator*=(int n);
        Graph& operator/=(int n);
        Graph operator*(int n);

        Graph operator*(Graph &g1);

        friend ostream& operator<<(ostream& out, Graph &g){
            out << g.printGraph() << endl;
            return out;
        }
    };
}
