#ifndef __GRAPH__
#define __GRAPH__

#include <bits/stdc++.h>

#define MaxNum 100

class Graph {
private:
	static void textPreprocess(std::string&);
	int v, e;
	const std::string path;
	std::map<std::string, int> mp;
public:
	Graph(const std::string&);
	using vertex_t = std::string;
	using edge_t = int;
	vertex_t Vex[MaxNum];
	edge_t Edge[MaxNum][MaxNum];
	int get_v();
	int get_e();
	int FindNum(const std::string&);
	std::string FindBridgeWords(int, int);
	std::string RandomBridgeWords(int, int);
};

extern void showDirectedGraph(Graph&, const std::string&);
extern std::string queryBridgeWords(Graph&, const std::string&, const std::string&);
extern std::string generateNewText(Graph&, const std::string&);
extern std::string calcShortestPath(Graph&, std::string&, std::string&);
extern std::string calcShortestPath(Graph&, std::string&);
extern std::string randomWalk(Graph& G);

#endif
