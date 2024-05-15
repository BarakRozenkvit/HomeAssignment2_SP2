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
            if(i!=j && _adjMatrix[i][j] == 0){
                _adjMatrix[i][j] = INF;
            }
        }
    }
}

string Graph::printGraph() {
    string result = "";
    for(int i=0;i<_adjMatrix.size();i++){
        result += "[";
        for(int j=0;j<_adjMatrix[i].size();j++){
            if(_adjMatrix[i][j] == INF){
                result += "0";
            }
            else{
                result += to_string(_adjMatrix[i][j]);
            }

            if(j!=_adjMatrix[i].size()-1){
                result+=", ";
            }
        }
        if(i!=_adjMatrix[i].size()-1){
            result+="]\n";
        }
        else {
            result += "]";
        }
    };
    return result;
}

void Graph::addS() {
    vector<vector<int>> new_mat(_adjMatrix.size() + 1, vector<int>(_adjMatrix.size() + 1));
    for (int i = 0; i < new_mat.size(); i++) {
        for (int j = 0; j < new_mat.size(); j++) {
            if (i == new_mat.size() - 1) { new_mat[i][j] = 0; }
            else if (j == new_mat.size() - 1) { new_mat[i][j] = INF; }
            else { new_mat[i][j] = _adjMatrix[i][j]; }
        }
    }
    new_mat[new_mat.size() - 1][new_mat.size() - 1] = 0;
    _adjMatrix = new_mat;
}

Graph& Graph::operator+=(Graph& g){
    if(_adjMatrix.size() != g.getAdjMatrix().size()){
        throw invalid_argument("The size of the first matrix must be equal to the size of the second matrix.");
    }
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}

            int gVal = g.getAdjMatrix()[i][j];
            int thisVal = _adjMatrix[i][j];
            if(gVal == INF){gVal=0;}
            if(thisVal == INF){thisVal=0;}
            _adjMatrix[i][j] = thisVal + gVal;
        }
    }

    this->loadGraph(_adjMatrix);
    return *this;
}

Graph& Graph::operator-=(Graph& g){
    if(_adjMatrix.size() != g.getAdjMatrix().size()){
        throw invalid_argument("The size of the first matrix must be equal to the size of the second matrix.");
    }
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}

            int gVal = g.getAdjMatrix()[i][j];
            int thisVal = _adjMatrix[i][j];
            if(gVal == INF){gVal=0;}
            if(thisVal == INF){thisVal=0;}
            _adjMatrix[i][j] = thisVal - gVal;
        }
    }
    this->loadGraph(_adjMatrix);
    return *this;
}

Graph& Graph::operator+() {
    return *this;
}

Graph& Graph::operator-() {
    return *this*=-1;
}

Graph Graph::operator+(Graph &g1){
    if(g1.getAdjMatrix().size() != this->getAdjMatrix().size()){
        throw invalid_argument("The size of the first matrix must be equal to the size of the second matrix.");
    }

    vector<vector<int>> newMat(g1.getAdjMatrix().size(),vector<int>(g1.getAdjMatrix().size()));
    for(int i=0;i<newMat.size();i++){
        for(int j=0;j<newMat[i].size();j++){
            int g1val = g1.getAdjMatrix()[i][j];
            int g2val = this->getAdjMatrix()[i][j];
            if(g1val == INF){g1val = 0;}
            if(g2val == INF){g2val = 0;}
            newMat[i][j] = g1val + g2val;
        }
    }
    Graph gRes;
    gRes.loadGraph(newMat);
    return gRes;
}

Graph Graph::operator-(Graph &g1){
    if(g1.getAdjMatrix().size() != this->getAdjMatrix().size()){
        throw invalid_argument("The size of the first matrix must be equal to the size of the second matrix.");
    }

    vector<vector<int>> newMat(g1.getAdjMatrix().size(),vector<int>(g1.getAdjMatrix().size()));
    for(int i=0;i<newMat.size();i++){
        for(int j=0;j<newMat[i].size();j++){
            int g1val = g1.getAdjMatrix()[i][j];
            int g2val = this->getAdjMatrix()[i][j];
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
            if(_adjMatrix[i][j]==INF){ continue;}
            _adjMatrix[i][j] = thisVal + 1;
        }
    }
    this->loadGraph(_adjMatrix);
    return *this;
}

Graph Graph::operator++(int n){
    vector<vector<int>> newMat(this->_adjMatrix.size(),vector<int>(this->_adjMatrix.size()));
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){
                newMat[i][j]=0;
                continue;
            }
            newMat[i][j] = thisVal;
            _adjMatrix[i][j] = thisVal + 1;
        }
    }
    Graph gRes;
    gRes.loadGraph(newMat);
    return gRes;
}

Graph& Graph::operator--() {
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){ continue;}
            _adjMatrix[i][j] = thisVal - 1;
        }
    }
    this->loadGraph(_adjMatrix);
    return *this;
}

Graph Graph::operator--(int n){
    vector<vector<int>> newMat(this->_adjMatrix.size(),vector<int>(this->_adjMatrix.size()));
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){
                newMat[i][j]=0;
                continue;
            }
            newMat[i][j] = thisVal;
            _adjMatrix[i][j] = thisVal - 1;
        }
    }
    Graph gRes;
    gRes.loadGraph(newMat);
    return gRes;
}

Graph& Graph::operator*=(int n) {
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){thisVal = 0;}
            _adjMatrix[i][j] = thisVal * n;

        }
    }
    this->loadGraph(_adjMatrix);
    return *this;
}

Graph& Graph::operator/=(int n) {
    for(int i=0;i<_adjMatrix.size();i++){
        for(int j=0;j<_adjMatrix.size();j++){
            if(i==j){continue;}
            int thisVal = _adjMatrix[i][j];
            if(_adjMatrix[i][j]==INF){thisVal = 0;}
            _adjMatrix[i][j] = thisVal / n;
        }
    }
    this->loadGraph(_adjMatrix);
    return *this;
}

Graph Graph::operator*(Graph &g1) {
    if(g1.getAdjMatrix().size() != this->getAdjMatrix().size()){
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
                int g1val = this->getAdjMatrix()[i][p];
                int g2val = g1.getAdjMatrix()[p][j];
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

Graph Graph::operator*(int n) {
    vector<vector<int>> newMat(this->getAdjMatrix().size(),vector<int>(this->getAdjMatrix().size()));
    for(int i=0;i<newMat.size();i++) {
        for (int j = 0; j < newMat[i].size(); j++) {
            int gVal = this->getAdjMatrix()[i][j];
            if (gVal == INF) { gVal = 0; }
            newMat[i][j] = gVal * n;
        }
    }
    Graph gRes;
    gRes.loadGraph(newMat);
    return gRes;
}

bool Graph::operator==(Graph &g2) {
    if(this->getAdjMatrix().size() != g2.getAdjMatrix().size()){
        return false;
    }
    for(int i=0;i<this->getAdjMatrix().size();i++){
        for(int j=0;j<this->getAdjMatrix()[i].size();j++){
            if(this->getAdjMatrix()[i][j] != g2.getAdjMatrix()[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool Graph::operator!=(Graph &g2) {
    return !(*this == g2);
}

bool Graph::operator<=(Graph &g2) {
    return *this<g2 || *this==g2;
}

bool Graph::operator>=(Graph &g2) {
    return *this>g2 || *this==g2;
}

bool Graph::operator<(Graph &g2) {
    return g2>*this;
}

bool Graph::operator>(Graph &g2){
    if(g2.getAdjMatrix().size() > this->getAdjMatrix().size()){
        return false;
    }
    // Only check this of matrix sizes are different
    if(this->getAdjMatrix().size()!=g2.getAdjMatrix().size()) {
        bool isSubMatrix;
        for (int k = 0; k <= this->getAdjMatrix().size() - g2.getAdjMatrix().size(); k++) {
            isSubMatrix = true;
            for (int i = 0; i < g2.getAdjMatrix().size(); i++) {
                for (int j = 0; j < g2.getAdjMatrix()[i].size(); j++) {
                    if (this->getAdjMatrix()[i + k][j + k] != g2.getAdjMatrix()[i][j]) {
                        isSubMatrix = false;
                    }
                }
            }
            // Check if subMatrix
            if (isSubMatrix) {return true;}
        }
    }

    if(this->getEdges() > g2.getEdges()){return true;}

    if(this->getAdjMatrix().size() > g2.getAdjMatrix().size()){return true;}

    return false;
}

std::ostream& ariel::operator<<(std::ostream& out,Graph &g){
    out << g.printGraph();
    return out;
}













