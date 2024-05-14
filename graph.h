#ifndef __GRAPH__
#define __GRAPH__

#include <string>

using namespace std;

class Graph {
public:
	Graph(string& p);
	using vertex_t = char;
	using edge_t = int;
	vertex_t Vex[MaxNum];
	edge_t Edge[MaxNum][MaxNum];
private:
	static void textPreprocess(string& str);
	const int MaxNum = 100;
	int v, e;
	string path;
};

void showDirectedGraph(Graph& G, const string& path = "./graph.png");
string queryBridgeWords(Graph& G, const string& word1, const string& word2);
string generateNewText(Graph& G, const string& input);
string calcShortestPath(string word1, string word2);
string calcShortestPath(string word);
string randomWalk();

#endif