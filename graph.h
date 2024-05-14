#ifndef __GRAPH__
#define __GRAPH__

#include <bits/stdc++.h>

#define MaxNum 100

using namespace std;

class Graph {
private:
	static void textPreprocess(string& str) {
		bool flag = false;
		for (char& c : str) {
			if (isalpha(c)) {
				c |= 0x20;
				flag = false;
			}
			else {
				if (!flag) {
					c = ' ';
					flag = true;
				}
				else {
					c = 0;
				}
			}
		}
		for (char& c : str) {
			if (isalpha(c)) break;
			c = 0;
		}
	}
	int v, e;
	const string path;
	map<string,int> mp;
public:
	Graph(const string& p);
	using vertex_t = string;
	using edge_t = int;
	vertex_t Vex[MaxNum];
	edge_t Edge[MaxNum][MaxNum];
	int get_v(){
		return v;
	}
	int get_e(){
		return e;
	}
	int FindNum(const string& word){
		for(int i=0;i<v;i++){
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

Graph::Graph(const string& p): path(p) {
	memset(Vex, 0, sizeof(Vex));
	memset(Edge, 0, sizeof(Edge));
	ifstream file(path);
    if (!file.is_open()) {
        cerr << "Error" << endl;
        exit(0);
    }
    stringstream buffer;
    buffer << file.rdbuf();
    string content = buffer.str();
	textPreprocess(content);
	buffer << content;
	string tmp;
	vector<string> vec;
	set<string> Set;
	while (buffer>>tmp) {
		vec.push_back(tmp);
		Set.insert(tmp);
	}
	for (auto& item : Set) {
		mp[item] = v;
		Vex[v++] = item;
	}
	e=vec.size() - 1;
	for (int i=0;i<e;i++) {
		Edge[mp[vec[i]]][mp[vec[i+1]]]++;
	}
}

void showDirectedGraph(Graph& G, const string& path = "./graph.png");
string queryBridgeWords(Graph& G, const string& word1, const string& word2);
string generateNewText(Graph& G, const string& input);
string calcShortestPath(Graph& G, string word1, string word2);
string calcShortestPath(Graph& G, string word);
string randomWalk(Graph& G);

#endif
