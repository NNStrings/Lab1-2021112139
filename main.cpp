#include<bits/stdc++.h>
#include "graph.h"

int main(int argc, char** argv){
	Graph G("./test.txt");
	std::cout << G.get_v() << std::endl << G.get_e() << std::endl;
	/*
	 *  help			// 帮助信息 
	 *  v				// 返回图节点数 
	 *  e				// 返回图边数 
	 *  showg			// 展示图结构 
	 *  bw w1 w2		// 查询桥接词
	 *  bnw input		// 根据bridge word生成新文本
	 *  shortp1 w		// 计算两个单词之间的最短路径
	 *  shortp2 w1 w2	// 计算两个单词之间的最短路径
	 *  rwalk			// 随机游走
	 *  exit			// 退出 
	 */ 
	std::string cmd; 
	while (1) {
		std::cin>>cmd; 
		if (cmd == "exit") break;
		else if (cmd == "v") std::cout<<G.get_v()<<std::endl;
		else if (cmd == "e") std::cout<<G.get_e()<<std::endl;
		else if (cmd == "showg") showDirectedGraph(G,"./graph.png");
		else if (cmd == "bw") {
			std::string s1,s2;
			std::cin>>s1>>s2;
			std::cout<<queryBridgeWords(G,s1,s2)<<std::endl;
		}
		else if (cmd == "bnw") std::cout<<G.get_e()<<std::endl;
		else if (cmd == "shortp1") {
			std::string s;
			std::cin>>s;
			std::cout<<calcShortestPath(G,s)<<std::endl;
		}	
		else if (cmd == "shortp2") {
			std::string s1,s2;
			std::cin>>s1>>s2;
			std::cout<<calcShortestPath(G,s1,s2)<<std::endl;
		}	
		else if (cmd == "rwalk") {
			std::cout<<randomWalk(G)<<std::endl;
		}
		else if (cmd == "help") {
			printf("*  v - 返回图节点数\n\
			e - 返回图边数\n\
			showg - 展示图结构\n\
			bw w1 w2 - 查询桥接词\n\
	 		bnw input - 根据bridge word生成新文本\n\
	 		shortp1 w - 计算两个单词之间的最短路径\n\
	 		shortp2 w1 w2 - 计算两个单词之间的最短路径\n\
	 		rwalk - 随机游走\n\
	 		exit - 退出\n");
		}
		else {
			printf("Not found cmd!!!\n");
		}
	}
	return 0;
}