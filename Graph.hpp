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
        // TODO: Intialization List
        Graph();

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

        Graph& operator+();
        Graph& operator-();

        Graph operator+(Graph &g1);
        //friend Graph operator+(Graph &g1,Graph &g2);
        Graph operator-(Graph &g1);

        bool operator>(Graph &g2);
        bool operator>=(Graph &g2);
        bool operator<(Graph &g2);
        bool operator<=(Graph &g2);
        bool operator==(Graph &g2);
        bool operator!=(Graph &g2);
        //++g && --g
        Graph& operator++();
        Graph& operator--();
        //g++ && g--
        Graph operator++(int);
        Graph operator--(int);

        Graph& operator*=(int n);
        Graph& operator/=(int n);
        Graph operator*(int n);

        Graph operator*(Graph &g1);

        friend std::ostream& operator<<(std::ostream& out,Graph &g);
    };


}
