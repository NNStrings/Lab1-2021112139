#include<bits/stdc++.h>
#include "graph.h"

int main(){
	Graph G("./test.txt");
	std::cout << G.get_v() << std::endl << G.get_e() << std::endl;
	return 0;
}
