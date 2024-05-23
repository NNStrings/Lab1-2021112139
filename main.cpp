#include<bits/stdc++.h>
#include "graph.h"

int main(int argc, char** argv){
	if (argc != 2) {
		perror("parameters error\n");
		exit(1);
	}
	srand(time(NULL));
	Graph G(argv[1]);
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
		std::cout << ">>> ";
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
		else if (cmd == "bnw") {
			std::string s;
			char str[1000];
			getchar();
			fgets(str, 1000, stdin);
			s = str;
			std::cout<<generateNewText(G, s);
		}
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
			printf("************** Menu **************\n");
			printf("v - 返回图节点数\
			\ne - 返回图边数\
			\nshowg - 展示图结构\
			\nbw w1 w2 - 查询桥接词\
	 		\nbnw input - 根据bridge word生成新文本\
	 		\nshortp1 w - 计算两个单词之间的最短路径\
	 		\nshortp2 w1 w2 - 计算两个单词之间的最短路径\
	 		\nrwalk - 随机游走\
	 		\nexit - 退出\n");
			printf("**********************************\n");
		}
		else {
			printf("Not found cmd \"%s\"!!!\n", cmd.c_str());
		}
	}
	return 0;
}