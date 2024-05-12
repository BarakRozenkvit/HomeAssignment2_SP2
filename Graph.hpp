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
        // Print operators
        // 1. <<
        friend std::ostream& operator<<(std::ostream& out,Graph &g);

        // Plus Operators
        // 1. +
        friend Graph operator+(Graph &g1,Graph &g2);
        // 2. +=
        Graph& operator+=(Graph &g1);
        // 3. ++
        // 4. Plus Unary

        // Minus Operators
        // 1. -
        // 2. -=
        // 3. --
        // Minus Unary

        // Multiply Operators
        // 1. *= Scalar
        // 2. *
    };
}
