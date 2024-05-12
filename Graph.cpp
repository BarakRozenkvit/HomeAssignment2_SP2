//// @author:314638669, Barak10101998@gmail.com
#include "Graph.hpp"
#include <iostream>

using namespace ariel;

Graph::Graph() {}

void Graph::loadGraph(vector <vector<int>> graph) {
    if(graph.size() == 1){
        throw invalid_argument("Invalid graph: The graph is has only one Vertice.");
    }

    if (graph.size() != graph[0].size()){
        throw invalid_argument("Invalid graph: The graph is not a square matrix.");
    }

    _adjMatrix = graph;
    _edges = 0;

    for(int i=0; i < _adjMatrix.size(); i++) {
        for (int j = 0; j < _adjMatrix[i].size(); j++) {
            if(i==j && _adjMatrix[i][j] !=0){
                throw invalid_argument("Invalid graph: i -> i has edge.");
            }

            if(_adjMatrix[i][j] != _adjMatrix[j][i]){
                _isDirected = true;
            }
            if (_adjMatrix[i][j] != 0) {
                _edges++;
            }
            if(_adjMatrix[i][j] < 0){
                _isNegativeEdges = true;
            }
        }
    }

    for(int i=0; i < _adjMatrix.size(); i++) {
        for (int j = 0; j < _adjMatrix[i].size(); j++) {
            if(i!=j && _adjMatrix[i][j] == 0 || _adjMatrix[i][j] == -INF){
                _adjMatrix[i][j] = INF;
            }
        }
    }
}

void Graph::printGraph() {
    std::cout << "Graph with " << _adjMatrix.size() << " vertices and " << _edges << " edges." << std::endl;
}

void Graph::addS(){
    vector<vector<int>> new_mat(_adjMatrix.size()+1,vector<int>(_adjMatrix.size()+1));
    for(int i=0;i<new_mat.size();i++) {
        for (int j = 0; j < new_mat.size(); j++) {
            if(i==new_mat.size() -1 ){new_mat[i][j] = 0;}
            else if(j==new_mat.size() - 1){new_mat[i][j] = INF;}
            else{new_mat[i][j] = _adjMatrix[i][j];}
        }
    }
    new_mat[new_mat.size() - 1][new_mat.size() - 1] = 0;
    _adjMatrix = new_mat;
}

std::ostream& ariel::operator<<(std::ostream& out,Graph &g){
    string result = "";
    for(int i=0;i<g.getAdjMatrix().size();i++){
        result += "[";
        for(int j=0;j<g.getAdjMatrix()[i].size();j++){
            if(g.getAdjMatrix()[i][j] == INF){
                result += "0";
            }
            else{
                result += to_string(g.getAdjMatrix()[i][j]);
            }

            if(j!=g.getAdjMatrix()[i].size()-1){
            result+=",";
            }
        }
        result += "] ";
    }
    out << result;
    return out;
}

Graph ariel::operator+(Graph &g1,Graph &g2){
    if(g1.getAdjMatrix().size() != g2.getAdjMatrix().size()){
        throw invalid_argument("number of Vertices is not equal");
    }
    int v = g1.getAdjMatrix().size();
    vector<vector<int>> newMat(g1.getAdjMatrix().size(),vector<int>(g1.getAdjMatrix().size()));
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            int g1val = g1.getAdjMatrix()[i][j];
            int g2val = g2.getAdjMatrix()[i][j];
            if(g1val == INF){g1val = 0;}
            if(g2val == INF){g2val = 0;}
            newMat[i][j] = g1val + g2val;
            }
        }

    Graph gRes;
    gRes.loadGraph(newMat);
    return gRes;
}

Graph& Graph::operator+=(Graph &g1){
    int v = this->_adjMatrix.size();
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(this->_adjMatrix[i][j] == INF || g1.getAdjMatrix()[i][j] == INF){
                _adjMatrix[i][j] = INF;
            }
            else{
                _adjMatrix[i][j] += g1.getAdjMatrix()[i][j];
            }
        }
    }
    return this;
}






