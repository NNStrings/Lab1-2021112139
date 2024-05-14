#include<graph.h>



void showDirectedGraph(Graph& G, const string& path = "./graph.png"){
	
}

string queryBridgeWords(Graph& G, const string& word1, const string& word2){
	int id1=G.FindNum(word1);
	int id2=G.FindNum(word2);
	if(id1==-1||id2==-1){
		if(id1==-1&&id2==-1)
			return (string)"No \"" + word1 + "\" and \"" + word2 + "\" in the graph!"
		
		if(id1==-1)
			return (string)"No \"" + word1 + "\" in the graph!"
		
		if(id2==-1)
			return (string)"No \"" + word2 + "\" in the graph!"
		
	}
	return G.FindBridgeWords(id1,id2);
}

string generateNewText(Graph& G, const string& input){
	string res="";
	bool flag=0;
	string now="",last;
	for(int i=0;i<input.length();i++){
		if(input[i]==' '){
			if(!flag)flag=1;
			else res=res+last+" "+RandomBridgeWords(G.FindNum(last),G.FindNum(now));
			last=now;
			now="";
		}
		else now=now+input[i];
	}
	res=res+last;
	return res;
}

string calcShortestPath(string word1, string word2){
	int id1=G.FindNum(word1);
	int id2=G.FindNum(word2);
	if(id1==-1||id2==-1)return "unreachable";
	
}

string calcShortestPath(string word){
	
}

string randomWalk(){
	
}
