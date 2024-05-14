#include "graph.h"

void Graph::textPreprocess(std::string& str) {
	bool flag = false;
	for (size_t i = 0; i < str.size(); ++i) {
		if (std::isalpha(str[i])) {
			str[i] |= 0x20;
			flag = false;
		}
		else {
			if (flag) {
				str.erase(i, 1);
				--i;
			}
			else {
				str[i] = ' ';
				flag = true;
			}
		}
	}
	for (char& c : str) {
		if (std::isalpha(c)) break;
		c = 0;
	}
}

Graph::Graph(const std::string& p) : path(p) {
	memset(Vex, 0, sizeof(Vex));
	memset(Edge, 0, sizeof(Edge));
	std::ifstream file(path);
	if (!file.is_open()) {
		std::cerr << "Error" << std::endl;
		exit(0);
	}
	std::stringstream buffer;
	buffer << file.rdbuf();
	std::string content = buffer.str();
	textPreprocess(content);
	buffer.str("");
	buffer << content;
	std::string tmp;
	std::vector<std::string> vec;
	std::set<std::string> Set;
	while (buffer >> tmp) {
		vec.push_back(tmp);
		Set.insert(tmp);
	}
	for (auto& item : Set) {
		mp[item] = v;
		Vex[v++] = item;
	}
	e = vec.size() - 1;
	for (int i = 0; i < e; i++) {
		Edge[mp[vec[i]]][mp[vec[i + 1]]]++;
	}
}

int Graph::get_v() {
	return v;
}

int Graph::get_e() {
	return e;
}

int Graph::FindNum(const std::string& word) {
	for (int i = 0; i < v; i++) {
		if (word == Vex[i])return i;
	}
	return -1;
}

std::string Graph::FindBridgeWords(int id1, int id2) {
	std::string res, last;
	bool flag = 0, flag1 = 0;
	for (int i = 1; i <= v; i++)if (Edge[id1][i] && Edge[i][id2]) {
		if (!flag) {
			flag = 1;
			res = Vex[i];
		}
		else {
			if (!flag1) {
				flag1 = 1;
				last = Vex[i];
			}
			else res = res + ", " + last;
		}
	}
	if (!flag)return (std::string)"No bridge words from \"" + Vex[id1] + "\" to \"" + Vex[id2] + "\"!";
	if (flag1)res = res + ", and " + last + ".";
	return (std::string)"The bridge words from \"" + Vex[id1] + "\" to \"" + Vex[id2] + "\" is:" + res;
}

std::string Graph::RandomBridgeWords(int id1, int id2) {
	if (id1 == -1 || id2 == -1)return "";
	int cnt = 0;
	std::string tmp[MaxNum];
	for (int i = 1; i <= v; i++)if (Edge[id1][i] && Edge[i][id2]) {
		tmp[++cnt] = Vex[i];
	}
	return tmp[rand() % cnt + 1] + " ";
}

std::string queryBridgeWords(Graph& G, const std::string& word1, const std::string& word2) {
	int id1 = G.FindNum(word1);
	int id2 = G.FindNum(word2);
	if (id1 == -1 || id2 == -1) {
		if (id1 == -1 && id2 == -1)
			return (std::string)"No \"" + word1 + "\" and \"" + word2 + "\" in the graph!";

		if (id1 == -1)
			return (std::string)"No \"" + word1 + "\" in the graph!";

		if (id2 == -1)
			return (std::string)"No \"" + word2 + "\" in the graph!";

	}
	return G.FindBridgeWords(id1, id2);
}

std::string generateNewText(Graph& G, const std::string& input) {
	std::string res = "";
	bool flag = 0;
	std::string now = "", last;
	int len = input.length();
	for (int i = 0; i < len; i++) {
		if (input[i] == ' ') {
			if (!flag)flag = 1;
			else res = res + last + " " + G.RandomBridgeWords(G.FindNum(last), G.FindNum(now));
			last = now;
			now = "";
		}
		else now = now + input[i];
	}
	res = res + last;
	return res;
}

std::string calcShortestPath(Graph& G, std::string& word1, std::string& word2) {
	int id1 = G.FindNum(word1);
	int id2 = G.FindNum(word2);
	if (id1 == -1 || id2 == -1)return "unreachable";

	std::queue<int>q;
	bool vis[MaxNum];
	int dis[MaxNum], last[MaxNum];
	memset(vis, 0, sizeof(vis));
	memset(dis, 63, sizeof(dis));
	memset(last, -1, sizeof(last));

	q.push(id2);
	dis[id2] = 0;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		vis[u] = 0;
		for (int i = 0; i < G.get_v(); i++)if (G.Edge[i][u]) {
			if (dis[i] > dis[u] + G.Edge[i][u]) {
				dis[i] = dis[u] + G.Edge[i][u];
				last[i] = u;
				if (!vis[i]) {
					vis[i] = 1;
					q.push(i);
				}
			}
		}
	}

	if (last[id1] == -1)return "unreachable";
	std::string res = G.Vex[id1];
	int now = id1;
	while (now != id2) {
		now = last[now];
		res = res + "->" + G.Vex[id2];
	}
	return res;
}

std::string calcShortestPath(Graph& G, std::string& word) {
	return calcShortestPath(G, word, G.Vex[rand() % G.get_v()]);
}

std::string randomWalk(Graph& G) {
	int now = rand() % G.get_v();
	bool mark[MaxNum][MaxNum];
	memset(mark, 0, sizeof(mark));
	std::string res = G.Vex[now];

	while (1) {
		int cnt = 0;
		int num[MaxNum];
		for (int i = 0; i < G.get_v(); i++)if (G.Edge[now][i]) {
			num[++cnt] = i;
		}
		if (!cnt)break;
		int x = num[rand() % cnt];
		res = res + " " + G.Vex[x];
		if (mark[now][x])break;
		mark[now][x] = 1;
		now = x;
	}
	return res;
}
