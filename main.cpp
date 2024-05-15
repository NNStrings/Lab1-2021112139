#include<bits/stdc++.h>
#include "graph.h"

int main(int argc, char** argv){
	Graph G(argv[1]);
	std::cout << G.get_v() << std::endl << G.get_e() << std::endl;
	showDirectedGraph(G, "./graph.png");
	return 0;
}
