#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    CHECK(g3.printGraph() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]");
}
TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, 2},
        {1, 0, 1},
        {1, 0, 0}};
    CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");
}
TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1, 1},
        {1, 0, 2, 1},
        {1, 2, 0, 1}};
    CHECK_THROWS(g2.loadGraph(weightedGraph));
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
}
TEST_CASE("Test Operators: + , += , ++ , -- , - , -=")
{
    ariel::Graph g0;
    vector<vector<int>> gM0 = {
            {0, -8, 4, 6,  0},
            {1, 0,  1, -9, 1},
            {0, 0,  0, -4, 22},
            {0, 1,  1, 0,  0},
            {1, -9, 1, 0,  0}
    };
    g0.loadGraph(gM0);
    ariel::Graph g1;
    vector<vector<int>> gM1 = {
            {0, 0,   0, -6,   0},
            {1, 0,   1, -100, 2},
            {0, 0,   0, 1,    -22},
            {0, 0,   0, 0,    0},
            {1, -89, 1, 0,    0}
    };
    g1.loadGraph(gM1);
    ariel::Graph g2 = g0 + g1;
    CHECK(g2.printGraph() ==
          "[0, -8, 4, 0, 0]\n[2, 0, 2, -109, 3]\n[0, 0, 0, -3, 0]\n[0, 1, 1, 0, 0]\n[2, -98, 2, 0, 0]");
    g0 += g2;
    CHECK(g0.printGraph() ==
          "[0, -16, 8, 6, 0]\n[3, 0, 3, -118, 4]\n[0, 0, 0, -7, 22]\n[0, 2, 2, 0, 0]\n[3, -107, 3, 0, 0]");
    ++g1;
    CHECK(g1.printGraph() ==
          "[0, 0, 0, -5, 0]\n[2, 0, 2, -99, 3]\n[0, 0, 0, 2, -21]\n[0, 0, 0, 0, 0]\n[2, -88, 2, 0, 0]");
    +g1;
    CHECK(g1.printGraph() ==
          "[0, 0, 0, -5, 0]\n[2, 0, 2, -99, 3]\n[0, 0, 0, 2, -21]\n[0, 0, 0, 0, 0]\n[2, -88, 2, 0, 0]");
    -g1;
    CHECK(g1.printGraph() ==
          "[0, 0, 0, -5, 0]\n[2, 0, 2, -99, 3]\n[0, 0, 0, 2, -21]\n[0, 0, 0, 0, 0]\n[2, -88, 2, 0, 0]");

    ariel::Graph f = g1--;
    CHECK(g1.printGraph() ==
          "[0, 0, 0, -6, 0]\n"
          "[1, 0, 1, -100, 2]\n"
          "[0, 0, 0, 1, -22]\n"
          "[0, 0, 0, 0, 0]\n"
          "[1, -89, 1, 0, 0]");

    CHECK(f.printGraph() != g1.printGraph());
    --f;
    CHECK(f.printGraph() == g1.printGraph());

    ariel::Graph g4;
    vector<vector<int>> gM2 = {
            {0, -2, -2, 4, -2},
            {-3, 0, -3, 98, -4},
            {-2, -2, 0, -3, 20},
            {-2, -2, -2, 0, -2},
            {-3, 87, -3, -2, 0}
    };
    g4.loadGraph(gM2);
    ariel::Graph g10 = -g4;
    ariel::Graph g5 = g10 + g1;
    CHECK(g5.printGraph() ==
            "[0, 2, 2, -10, 2]\n"
            "[4, 0, 4, -198, 6]\n"
            "[2, 2, 0, 4, -42]\n"
            "[2, 2, 2, 0, 2]\n"
            "[4, -176, 4, 2, 0]");
}
TEST_CASE("Test Operators: * , *=r , /=r")
{
    ariel::Graph g0;
    vector<vector<int>> gm0 = {
            {0, 2, -4, 0},
            {1, 0, 1, 2},
            {-1, 0, 0, 1},
            {9, 0, -88, 0}
    };
    g0.loadGraph(gm0);
    g0*=-5;
    CHECK(g0.printGraph() == "[0, -10, 20, 0]\n"
                             "[-5, 0, -5, -10]\n"
                             "[5, 0, 0, -5]\n"
                             "[-45, 0, 440, 0]");
    g0/=5;
    CHECK(g0.printGraph() == "[0, -2, 4, 0]\n"
                            "[-1, 0, -1, -2]\n"
                            "[1, 0, 0, -1]\n"
                            "[-9, 0, 88, 0]");
    ariel::Graph g1 = g0 * g0;
    CHECK(g1.printGraph() == "[0, 0, 2, 0]\n"
                             "[17, 0, -180, 1]\n"
                             "[9, -2, 0, 0]\n"
                             "[88, 18, -36, 0]");
}
TEST_CASE("Test Operators: <= , >= , > , < , != , ==")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
            {0, 5, 5, 5, 0},
            {0, 0, 6, 0, 0},
            {0, 0, 0, 5, 0},
            {0, 0, 0, 0, 0},
            {0, 5, 0, 0, 0}

    };
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
            {0, 5, 5, 5},
            {0, 0, 0, 0},
            {0, 0, 0, 5},
            {0, 0, 0, 0},

    };
    g2.loadGraph(weightedGraph);
    CHECK(g1 > g2);
    CHECK_FALSE(g2 > g1);
    CHECK(g1 >= g2);
    CHECK(g1 != g2);

    ariel::Graph g3;
    vector<vector<int>> gm3 ={
            {0, 1, 2},
            {0, 0, 1},
            {0 ,0, 0}
    };
    g3.loadGraph(gm3);

    ariel::Graph g4;
    vector<vector<int>> gm4 = {
            {0, 2},
            {2, 0}
    };
    g4.loadGraph(gm4);
    CHECK(g4 != g3);
    CHECK(g3 >= g4);

    ariel::Graph g5;
    vector<vector<int>> gm5 = {
            {0, 1, 2},
            {1, 0, 2},
            {-1, 2, 0}
    };
    g5.loadGraph(gm5);

    CHECK(g5 != g3);
    CHECK(g5 > g4);
    CHECK_FALSE(g5 <= g4);
    ++g4;
    CHECK(g5 > g4);
    CHECK_FALSE(g4 > g5);

    ariel::Graph g6;
    vector<vector<int>> gm6 = {
            {0, 1, 2},
            {1, 0, 3},
            {-1, 2, 0}
    };
    g6.loadGraph(gm6);

    CHECK_FALSE(g5 > g6);
    CHECK_FALSE(g5 <= g6);
    CHECK(g5 !=g6);
    --g6;
    CHECK(g5>=g6);
    CHECK_FALSE(g5>g5);
    CHECK_FALSE(g5<g5);
    CHECK(g5==g5);



}
TEST_CASE("Test All Operators")
{
    ariel::Graph g0;
    vector<vector<int>> m0 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    g0.loadGraph(m0);
    ariel::Graph g1;
    vector<vector<int>> m1 = {
            {0, 0, 0},
            {-2, 0, 3},
            {0, 0, 0}
    };
    g1.loadGraph(m1);
    ariel::Graph g2 = g0 + g1;
    CHECK(g2.printGraph() == "[0, 0, 0]\n"
                             "[-2, 0, 3]\n"
                             "[0, 0, 0]");
    g2 = g2 - g2;
    CHECK(g2.printGraph() == "[0, 0, 0]\n"
                            "[0, 0, 0]\n"
                            "[0, 0, 0]");
    g2 = g2 * g2;
    CHECK(g2.printGraph() == "[0, 0, 0]\n"
                             "[0, 0, 0]\n"
                             "[0, 0, 0]");
    g2 = g0 * g1;
    CHECK(g2.printGraph() == "[0, 0, 0]\n"
                             "[0, 0, 0]\n"
                             "[0, 0, 0]");
    g2 = g1 * 16;
    CHECK(g2.printGraph() == "[0, 0, 0]\n"
                              "[-32, 0, 48]\n"
                              "[0, 0, 0]");
    g2 = g1++;
    CHECK(g2.printGraph() == "[0, 0, 0]\n"
                             "[-2, 0, 3]\n"
                             "[0, 0, 0]");
    g2 = g1--;
    CHECK(g2.printGraph() == "[0, 0, 0]\n"
                             "[-1, 0, 4]\n"
                             "[0, 0, 0]");
    CHECK(g1.printGraph() == "[0, 0, 0]\n"
                             "[-2, 0, 3]\n"
                             "[0, 0, 0]");
    ariel::Graph g3;
    vector<vector<int>> m3 = {
            {0, 5, 0},
            {-2, 0, 3},
            {7, 0, 0}
    };
    g3.loadGraph(m3);
    g1+=g3;
    CHECK(g1.printGraph() == "[0, 5, 0]\n"
                             "[-4, 0, 6]\n"
                             "[7, 0, 0]");
    g1-=g1;
    CHECK(g1.printGraph() == "[0, 0, 0]\n"
                             "[0, 0, 0]\n"
                             "[0, 0, 0]");
    g1=-g3;
    CHECK(g3.printGraph() == "[0, 5, 0]\n"
                             "[-2, 0, 3]\n"
                             "[7, 0, 0]");
    CHECK(g1.printGraph() == "[0, -5, 0]\n"
                             "[2, 0, -3]\n"
                             "[-7, 0, 0]");
    ++g3;++g3;
    CHECK(g3.printGraph() == "[0, 7, 0]\n"
                             "[0, 0, 5]\n"
                             "[9, 0, 0]");
    --g3;
    CHECK(g3.printGraph() == "[0, 6, 0]\n"
                             "[0, 0, 4]\n"
                             "[8, 0, 0]");
    g3*=3;
    CHECK(g3.printGraph() == "[0, 18, 0]\n"
                             "[0, 0, 12]\n"
                             "[24, 0, 0]");
    g3/=2;
    CHECK(g3.printGraph() == "[0, 9, 0]\n"
                             "[0, 0, 6]\n"
                             "[12, 0, 0]");

    bool res = g3 == g2;
    CHECK_FALSE(g3 == g2);
    CHECK(g3 != g2);
    CHECK(g3 > g2);
    CHECK(g3 >= g2);

    ariel::Graph g5;
    vector<vector<int>> m5 = {
            {0, 6},
            {1, 0}
    };
    g5.loadGraph(m5);

    CHECK(g2 > g5);
    CHECK(g3 > g5);

    ariel::Graph g6;
    vector<vector<int>> m6 = {
            {0, 0, 8},
            {0, 0, 0},
            {0, 0, 0}
    };
    g6.loadGraph(m6);

    CHECK(g6 > g5);
    CHECK_FALSE(g6 < g5);

    ariel::Graph g7;
    vector<vector<int>> m7 = {
            {0, 8},
            {0, 0}
    };
    g7.loadGraph(m7);
    CHECK(g6 > g7);

    ariel::Graph g8;
    vector<vector<int>> m8 = {
            {0, 5},
            {0, 0}
    };
    g8.loadGraph(m8);

    ariel::Graph g9;
    vector<vector<int>> m9 = {
            {0, 0, 5},
            {1, 0, 0},
            {3, 1, 0}
    };
    g9.loadGraph(m9);

    ariel::Graph g9B;
    vector<vector<int>> m9B = {
            {0, 0, 3, 1},
            {0, 0, 0, 9},
            {0, 5, 0, 9},
            {0, 0 ,6, 0}
    };
    g9B.loadGraph(m9B);

    ariel::Graph g9C;
    vector<vector<int>> m9C = {
            {0, 0, 3, 1},
            {0, 0, 5, 9},
            {1, 0, 0, 9},
            {3, 1 ,0, 0}
    };
    g9C.loadGraph(m9C);

    ariel::Graph g9D;
    vector<vector<int>> m9D = {
            {0, 0, 3, 1},
            {0, 0, 5, 9},
            {1, 0, 0, 9},
            {3, 1 ,1, 0}
    };
    g9D.loadGraph(m9D);

    CHECK(g9 > g8);
    CHECK(g9B > g8);
    CHECK(g9C > g9);
    CHECK(g9D > g9B);

    ariel::Graph g10;
    vector<vector<int>> m10 = {
            {0, 3},
            {1, 0}
    };
    g10.loadGraph(m10);

    ariel::Graph g11;
    vector<vector<int>> m11 = {
            {0, 4, 3},
            {1, 0, -7},
            {0, 6, 0}
    };
    g11.loadGraph(m11);
    CHECK(g11>g10);


















}
TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);

    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
}
TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->2->0");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
            {0, 1, 2, 0, 0},
            {1, 0, 3, 0, 0},
            {2, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph4 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}
    };
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={1, 2}, B={0}");


}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 0},
            {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test Negative Cycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, -9, 0, 0},
            {0, 0, -8, 0},
            {0, 0, 0, -10},
            {-7, 0, 0, 0},

    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::negativeCycle(g) == "0->1->2->3->0");
}
TEST_CASE("Test Directed and Undirected Graphs")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 0, 0, 8},
            {0, 0, 0, 8},
            {0, 0, 0, 8},
            {8, 8, 8, 0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph2 = {
            {0, 0, 0, 7},
            {0, 0, 0, 8},
            {0, 0, 0, 8},
            {8, 8, 8, 0}
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) != "0");

    vector<vector<int>> graph3 = {
            {0, 2},
            {0, 0}
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");

    vector<vector<int>> graph4 = {
            {0, 2},
            {2, 0}
    };
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) != "0");

    vector<vector<int>> graph5 = {
            {0, 2},
            {4, 0}
    };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::isContainsCycle(g) != "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0}, B={1}");
}
TEST_CASE("TestAll Directed - No Weights")
{
    // 1.
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 1, 0},
            {0, 0, 0, 1, 1, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0},
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,2,6) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,7,2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,4,5) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");
    // 2.
    vector<vector<int>> graph2 = {
            {0, 1, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 1},
            {1, 0, 0, 0, 0, 0, 0, 0},
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,2,6) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,7,2) == "7->0->5->3->2");
    CHECK(ariel::Algorithms::shortestPath(g,4,5) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->1->3->7->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");
    // 3.
    vector<vector<int>> graph3 = {
            {0, 1, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0, 0},
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,2,6) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,7,2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,4,5) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2, 3, 6}, B={1, 4, 5, 7}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");
    // 4.
    vector<vector<int>> graph4 = {
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0},
    };
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,2,6) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,7,2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,4,5) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={4, 5, 6, 7}, B={0, 1, 2, 3}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");
}
TEST_CASE("TestAll Directed - Non Negative Weights")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 0, 5, 0, 0},
            {6, 0, 0, 0, 0},
            {0, 8, 0, 4, 0},
            {1, 0, 0, 0, 0},
            {2, 0, 2, 0, 0},
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,0,3) == "0->2->3");
    CHECK(ariel::Algorithms::shortestPath(g,2,3) == "2->3");
    CHECK(ariel::Algorithms::shortestPath(g,1,4) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->2->3->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph2 = {
            {0, 8, 5, 11, 2},
            {6, 0, 11, 7, 4},
            {3, 8, 0, 4, 7},
            {1, 4, 1, 0, 4},
            {2, 11, 2, 22, 0},
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g,0,3) == "0->4->2->3");
    CHECK(ariel::Algorithms::shortestPath(g,2,3) == "2->3");
    CHECK(ariel::Algorithms::shortestPath(g,1,4) == "1->4");
    CHECK(ariel::Algorithms::isContainsCycle(g) != "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph3 = {
            {0, 0, 5, 0, 2},
            {6, 0, 0, 0, 4},
            {3, 8, 0, 0, 0},
            {1, 0, 1, 0, 0},
            {2, 11, 2, 22, 0},
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g,0,3) == "0->4->3");
    CHECK(ariel::Algorithms::shortestPath(g,2,3) == "2->0->4->3");
    CHECK(ariel::Algorithms::shortestPath(g,1,4) == "1->4");
    CHECK(ariel::Algorithms::isContainsCycle(g) != "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");
}
TEST_CASE("TestAll Directed - Negative Weights")
{
    ariel::Graph g;
    vector<vector<int>> graph = {

            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 6, 0},
            {0, 0, 0, 0, 5, 0},
            {1, 0, 0, 0, 8, -8},
            {0, 6, 0, -8, 0, 0},
            {4, 0, 0, 0, 0, 0},
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,0,4) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,1,5) == "1->4->3->5");
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == "2->4->3->5->0");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "4->3->4");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph2 = {
            {0, 0, -2, 0},
            {1, 0, 7, -8},
            {0, -8, 0, 0},
            {4, 0, 0, 0},
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,1,3) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->2->1->3->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "1->0->2->1");

    vector<vector<int>> graph3 = {
            {0, 0, -2, 0},
            {0, 0, 7, -8},
            {0, -8, 0, 0},
            {4, 0, 0, 0},
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,1,3) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->2->1->3->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1}, B={2, 3}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0->2->1->3->0");

    vector<vector<int>> graph4 = {
            {0, 0, -2, 0},
            {0, 0, 7, 88},
            {0, -8, 0, 0},
            {4, 0, 0, 0},
    };
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,1,3) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->2->1->3->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1}, B={2, 3}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "1->2->1");

    vector<vector<int>> graph5 = {
            {0, 0, -2, 0},
            {0, 0, 7, 0},
            {0, -8, 0, 0},
            {4, 88, 0, 0},
    };
    g.loadGraph(graph5);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,1,3) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "2->1->2");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1}, B={2, 3}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "1->2->1");

    vector<vector<int>> graph6 = {
            {0, 0, -2, 0},
            {0, 0, 8, 0},
            {0, -8, 0, 0},
            {4, 88, 0, 0},
    };
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "0->2");
    CHECK(ariel::Algorithms::shortestPath(g,1,3) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "2->1->2");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1}, B={2, 3}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph7 = {
            {0, 0, 10, 0, 0, 0, 0},
            {74, 0, 0, 0, 0, 0, 0},
            {0, 38, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 3, 0},
            {0, 0, 0, 5, 0, 0, 0},
            {0, 0, 0, 0, -10, 0, 22},
            {0, 0, 0, 0, 0, 0, 0}
    };
    g.loadGraph(graph7);
    CHECK(ariel::Algorithms::shortestPath(g,0,1) == "-1");
    CHECK(ariel::Algorithms::isConnected(g) == false);



}
TEST_CASE("TestAll Undirected - No Weights")
{
    ariel::Graph g;
    vector <vector<int>> graph = {
            {0, 1, 0, 1, 1, 0},
            {1, 0, 0, 0, 1, 1},
            {0, 0, 0, 0, 1, 1},
            {1, 0, 0, 0, 0, 0},
            {1, 1, 1, 0, 0, 0},
            {0, 1, 1, 0, 0, 0},
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g,0,4) == "0->4");
    CHECK(ariel::Algorithms::shortestPath(g,1,5) == "1->5");
    CHECK(ariel::Algorithms::shortestPath(g,2,0) == "2->4->0");
    CHECK(ariel::Algorithms::isContainsCycle(g) != "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector <vector<int>> graph2 = {
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->3->1->4->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={3, 4}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector <vector<int>> graph3 = {
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 0},
            {1, 1, 1, 0, 0},
            {1, 1, 0, 0, 0},
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "0->3->2");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0->3->1->4->0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={3, 4}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector <vector<int>> graph4 = {
            {0, 1, 1, 1},
            {1, 0, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 0}
    };
    g.loadGraph(graph4);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g,0,2) == "0->2");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "1->2->3->1");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

}
TEST_CASE("TestAll Undirected - Non Negative Weights")
{
    ariel::Graph g;
    vector <vector<int>> graph = {
            {0,  12, 0, 1, 10, 0},
            {12, 0,  0, 0, 1,  1},
            {0,  0,  0, 0, 1,  2},
            {1,  0,  0, 0, 0,  0},
            {10, 1,  1, 0, 0,  0},
            {0,  1,  2, 0, 0,  0},
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == true);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "0->4");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 5) == "1->5");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 0) == "2->4->0");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "1->4->2->5->1");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector <vector<int>> graph2 = {
            {0,  12, 0, 1, 0, 0},
            {12, 0,  0, 0, 0, 0},
            {0,  0,  0, 0, 1, 2},
            {1,  0,  0, 0, 0, 0},
            {0,  0,  1, 0, 0, 0},
            {0,  0,  2, 0, 0, 0}
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 5) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 2, 5) == "2->5");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1, 3, 4, 5}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector <vector<int>> graph3 = {
            {0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 1, 2},
            {1, 0, 0, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 2, 0, 0, 0}
    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 1, 5) == "-1");
    CHECK(ariel::Algorithms::shortestPath(g, 0, 1) == "-1");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "0");
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 1, 2}, B={3, 4, 5}");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");
}
TEST_CASE("TestAll Undirected - Negative Weights")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 0, 0,   1, 0,  0},
            {0, 0, 0,   0, 0,  0},
            {0, 0, 0,   0, -1, -22},
            {1, 0, 0,   0, 0,  0},
            {0, 0, -1,  0, 0,  8},
            {0, 0, -22, 0, 8,  0}
    };
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 3) == "0->3");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "2->4->5->2");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "2->5->4->2");

    vector<vector<int>> graph2 = {
            {0, 0, 0,  1, 0,  0},
            {0, 0, 0,  0, 0,  0},
            {0, 0, 0,  0, -1, 22},
            {1, 0, 0,  0, 0,  0},
            {0, 0, -1, 0, 0,  8},
            {0, 0, 22, 0, 8,  0}
    };
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == false);
    CHECK(ariel::Algorithms::shortestPath(g, 2, 4) == "2->4");
    CHECK(ariel::Algorithms::isContainsCycle(g) == "2->4->5->2");
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph3 = {
            {0, 7,  0,  0,  0},
            {7, 0,  -1, 10, 0},
            {0, -1, 0,  10, 7},
            {0, 10, 10, 0,  0},
            {0, 0,  7,  0,  0}

    };
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::negativeCycle(g) == "0");

    vector<vector<int>> graph6={{0, 10, -1, 1, 0},
                                {10, 0, 10, 0, 0},
                                {-1, 10, 0, 0, 2},
                                {1, 0, 0, 0, 0},
                                {0, 0, 2, 0, 0}};
    g.loadGraph(graph6);
    CHECK(ariel::Algorithms::shortestPath(g,1,0)=="1->2->0");

}
TEST_CASE("TestAll invalid graphs")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
            {0, 1, 2, 0},
            {1, 0, 3, 0},
            {2, 3, 0, 4},
            {0, 0, 4, 1}
    };
    CHECK_THROWS(g.loadGraph(graph));

    vector<vector<int>> graph2 = {
            {0,1,1,1,1}
    };
    CHECK_THROWS(g.loadGraph(graph2));

    vector<vector<int>> graph3 = {
            {0,1},
            {1,0}
    };
    CHECK_NOTHROW(g.loadGraph(graph3));

    vector <vector<int>> graph4 = {
            {0}
    };
    CHECK_THROWS(g.loadGraph(graph4));
}