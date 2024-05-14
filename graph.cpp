#include "graph.h"


string queryBridgeWords(Graph& G, const string& word1, const string& word2){
	int id1=G.FindNum(word1);
	int id2=G.FindNum(word2);
	if(id1==-1||id2==-1){
		if(id1==-1&&id2==-1)
			return (string)"No \"" + word1 + "\" and \"" + word2 + "\" in the graph!";
		
		if(id1==-1)
			return (string)"No \"" + word1 + "\" in the graph!";
		
		if(id2==-1)
			return (string)"No \"" + word2 + "\" in the graph!";
		
	}
	return G.FindBridgeWords(id1,id2);
}

string generateNewText(Graph& G, const string& input){
	string res="";
	bool flag=0;
	string now="",last;
	int len=input.length();
	for(int i=0;i<len;i++){
		if(input[i]==' '){
			if(!flag)flag=1;
			else res=res+last+" "+G.RandomBridgeWords(G.FindNum(last),G.FindNum(now));
			last=now;
			now="";
		}
		else now=now+input[i];
	}
	res=res+last;
	return res;
}

string calcShortestPath(Graph& G, string word1, string word2){
	int id1=G.FindNum(word1);
	int id2=G.FindNum(word2);
	if(id1==-1||id2==-1)return "unreachable";
	
	queue<int>q;
	bool vis[MaxNum];
	int dis[MaxNum],last[MaxNum];
	memset(vis,0,sizeof(vis));
	memset(dis,63,sizeof(dis));
	memset(last,-1,sizeof(last));
	
	q.push(id2);
	dis[id2]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=0;i<G.get_v();i++)if(G.Edge[i][u]){
			if(dis[i]>dis[u]+G.Edge[i][u]){
				dis[i]=dis[u]+G.Edge[i][u];
				last[i]=u;
				if(!vis[i]){
					vis[i]=1;
					q.push(i);
				}
			}
		}
	}
	
	if(last[id1]==-1)return "unreachable";
	string res=G.Vex[id1];
	int now=id1;
	while(now!=id2){
		now=last[now];
		res=res+"->"+G.Vex[id2];
	}
	return res;
}

string calcShortestPath(Graph& G, string word){
	return calcShortestPath(G, word,G.Vex[rand()%G.get_v()]);
}

string randomWalk(Graph& G){
	int now=rand()%G.get_v();
	bool mark[MaxNum][MaxNum];
	memset(mark,0,sizeof(mark));
	string res=G.Vex[now];
	
	while(1){
		int cnt=0;
		int num[MaxNum];
		for(int i=0;i<G.get_v();i++)if(G.Edge[now][i]){
			num[++cnt]=i;
		}
		if(!cnt)break;
		int x=num[rand()%cnt];
		res=res+" "+G.Vex[x];
		if(mark[now][x])break;
		mark[now][x]=1;
		now=x;
	}
	return res;
}