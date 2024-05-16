#include<bits/stdc++.h>
#include "graph.h"

int main(int argc, char** argv){
	Graph G("./test.txt");
	std::cout << G.get_v() << std::endl << G.get_e() << std::endl;
	/*
	 *  help			// ������Ϣ 
	 *  v				// ����ͼ�ڵ��� 
	 *  e				// ����ͼ���� 
	 *  showg			// չʾͼ�ṹ 
	 *  bw w1 w2		// ��ѯ�ŽӴ�
	 *  bnw input		// ����bridge word�������ı�
	 *  shortp1 w		// ������������֮������·��
	 *  shortp2 w1 w2	// ������������֮������·��
	 *  rwalk			// �������
	 *  exit			// �˳� 
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
			printf("*  v - ����ͼ�ڵ���\n\
			e - ����ͼ����\n\
			showg - չʾͼ�ṹ\n\
			bw w1 w2 - ��ѯ�ŽӴ�\n\
	 		bnw input - ����bridge word�������ı�\n\
	 		shortp1 w - ������������֮������·��\n\
	 		shortp2 w1 w2 - ������������֮������·��\n\
	 		rwalk - �������\n\
	 		exit - �˳�\n");
		}
		else {
			printf("Not found cmd!!!\n");
		}
	}
	return 0;
}