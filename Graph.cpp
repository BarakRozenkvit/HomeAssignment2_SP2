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

Graph& Graph::operator+=(Graph& g){
    if(_adjMatrix.size() != g.getAdjMatrix().size()){
        throw invalid_argument("Graphs Vertics number don't match");
    }
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}

            int gVal = g.getAdjMatrix()[i][j];
            int thisVal = _adjMatrix[i][j];
            if(gVal == INF){gVal=0;}
            if(thisVal == INF){thisVal=0;}

            if(thisVal + gVal == 0){_adjMatrix[i][j] = INF;}
            else{_adjMatrix[i][j] = thisVal + gVal;}
        }
    }
    return *this;
}

Graph& Graph::operator-=(Graph& g){
    if(_adjMatrix.size() != g.getAdjMatrix().size()){
        throw invalid_argument("Graphs Vertics number don't match");
    }
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}

            int gVal = g.getAdjMatrix()[i][j];
            int thisVal = _adjMatrix[i][j];
            if(gVal == INF){gVal=0;}
            if(thisVal == INF){thisVal=0;}

            if(thisVal - gVal == 0){_adjMatrix[i][j] = INF;}
            else{_adjMatrix[i][j] = thisVal - gVal;}
        }
    }
    return *this;
}

Graph& Graph::operator+() {
    return *this;
}

Graph& Graph::operator-() {
    return *this*=-1;
}

Graph ariel::operator+(Graph &g1,Graph &g2){
    if(g1.getAdjMatrix().size() != g2.getAdjMatrix().size()){
        throw invalid_argument("number of Vertices is not equal");
    }

    vector<vector<int>> newMat(g1.getAdjMatrix().size(),vector<int>(g1.getAdjMatrix().size()));
    for(int i=0;i<newMat.size();i++){
        for(int j=0;j<newMat[i].size();j++){
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

Graph ariel::operator-(Graph &g1,Graph &g2){
    if(g1.getAdjMatrix().size() != g2.getAdjMatrix().size()){
        throw invalid_argument("number of Vertices is not equal");
    }

    vector<vector<int>> newMat(g1.getAdjMatrix().size(),vector<int>(g1.getAdjMatrix().size()));
    for(int i=0;i<newMat.size();i++){
        for(int j=0;j<newMat[i].size();j++){
            int g1val = g1.getAdjMatrix()[i][j];
            int g2val = g2.getAdjMatrix()[i][j];
            if(g1val == INF){g1val = 0;}
            if(g2val == INF){g2val = 0;}
            newMat[i][j] = g1val - g2val;
        }
    }
    Graph gRes;
    gRes.loadGraph(newMat);
    return gRes;
}

Graph& Graph::operator++() {
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){thisVal = 0;}

            if(thisVal + 1 == 0){_adjMatrix[i][j] = INF;}
            else{_adjMatrix[i][j] = thisVal + 1;}
        }
    }
    return *this;
}

Graph& Graph::operator--() {
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){thisVal = 0;}

            if(thisVal - 1 == 0){_adjMatrix[i][j] = INF;}
            else{_adjMatrix[i][j] = thisVal - 1;}
        }
    }
    return *this;
}

Graph& Graph::operator*=(int n) {
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){thisVal = 0;}

            if(thisVal * n == 0){_adjMatrix[i][j] = INF;}
            else{_adjMatrix[i][j] = thisVal * n;}
        }
    }
    return *this;
}

Graph& Graph::operator/=(int n) {
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){thisVal = 0;}

            if(thisVal / n == 0){_adjMatrix[i][j] = INF;}
            else{_adjMatrix[i][j] = thisVal / n;}
        }
    }
    return *this;
}

Graph ariel::operator*(Graph &g1,Graph &g2) {
    if(g1.getAdjMatrix().size() != g2.getAdjMatrix().size()){
        throw invalid_argument("The number of columns in the first matrix must be equal to the number of rows in the second matrix.");
    }
    vector<vector<int>> newMat(g1.getAdjMatrix().size(),vector<int>(g1.getAdjMatrix().size()));
    for(int i=0;i<newMat.size();i++) {
        for (int j = 0; j < newMat[i].size(); j++) {
            if(i==j){
                newMat[i][j] = 0;
                continue;
            }
            int res = 0;
            for(int p=0;p<newMat.size();p++){
                int g1val = g1.getAdjMatrix()[i][p];
                int g2val = g2.getAdjMatrix()[p][j];
                if(g1val == INF){g1val = 0;}
                if(g2val == INF){g2val = 0;}
                res += g1val * g2val;
            }
            newMat[i][j] = res;
        }
    }
    Graph gRes;
    gRes.loadGraph(newMat);
    return gRes;
}

Graph ariel::operator*(Graph &g, int n) {
    vector<vector<int>> newMat(g.getAdjMatrix().size(),vector<int>(g.getAdjMatrix().size()));
    for(int i=0;i<newMat.size();i++) {
        for (int j = 0; j < newMat[i].size(); j++) {
            int gVal = g.getAdjMatrix()[i][j];
            if (gVal == INF) { gVal = 0; }
            newMat[i][j] = gVal * n;
        }
    }
    Graph gRes;
    gRes.loadGraph(newMat);
    return gRes;
}

bool ariel::operator==(Graph &g1, Graph &g2) {
    if(g1.getAdjMatrix().size() != g2.getAdjMatrix().size()){
        return false;
    }
    for(int i=0;i<g1.getAdjMatrix().size();i++){
        for(int j=0;j<g1.getAdjMatrix()[i].size();j++){
            if(g1.getAdjMatrix()[i][j] != g2.getAdjMatrix()[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool ariel::operator!=(Graph &g1, Graph &g2) {
    return !(g1==g2);
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
        result += "]\n";
    }
    out << result;
    return out;
}












