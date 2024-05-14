#ifndef __GRAPH__
#define __GRAPH__

#include <string>

using namespace std;

#define MaxNum 100
class Graph {
private:
	static void textPreprocess(string& str);
	int v, e;
	string path;
public:
	Graph(string& p);
	using vertex_t = string;
	using edge_t = int;
	vertex_t Vex[MaxNum];
	edge_t Edge[MaxNum][MaxNum];
	int FindNum(const string& word){
		for(int i=1;i<=v;i++){
			if(word==Vex[i])return i;
		}
		return -1;
	}
	string FindBridgeWords(int id1,int id2){
		string res,last;
		bool flag=0,flag1=0;
		for(int i=1;i<=v;i++)if(Edge[id1][i]&&Edge[i][id2]){
			if(!flag){
				flag=1;
				res=Vex[i];
			}
			else{
				if(!flag1){
					flag1=1;
					last=Vex[i];
				}
				else res=res + ", " + last;
			}
		}
		if(!flag)return (string)"No bridge words from \"" + Vex[id1] + "\" to \"" + Vex[id2] + "\"!";
		if(flag1)res=res + ", and " + last + ".";
		return (string)"The bridge words from \"" + Vex[id1] + "\" to \"" + Vex[id2] + "\" is:" + res;
	}
	string RandomBridgeWords(int id1,int id2){
		if(id1==-1||id2==-1)return "";
		int cnt=0;
		string tmp[MaxNum];
		for(int i=1;i<=v;i++)if(Edge[id1][i]&&Edge[i][id2]){
			tmp[++cnt]=Vex[i];
		}
		return tmp[rand()%cnt+1]+" ";
	}
};

void showDirectedGraph(Graph& G, const string& path = "./graph.png");
string queryBridgeWords(Graph& G, const string& word1, const string& word2);
string generateNewText(Graph& G, const string& input);
string calcShortestPath(string word1, string word2);
string calcShortestPath(string word);
string randomWalk();

#undef MaxNum

#endif
