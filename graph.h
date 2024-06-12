// Copyright 2024 <2021111230,2021112139>
#ifndef __GRAPH_H_
#define __GRAPH_H_

#include <bits/stdc++.h>
#include <map>
#include <string>
#define MaxNum 100

class Graph {
 private:
    static void textPreprocess(std::string&);
    int v, e;
    const std::string path;
    std::map<std::string, int> mp;
 public:
    explicit Graph(const std::string&);
    using vertex_t = std::string;
    using edge_t = int;
    vertex_t Vex[MaxNum];
    edge_t Edge[MaxNum][MaxNum];
    int get_v() const;
    int get_e() const;
    int FindNum(const std::string&) const;
    std::string FindBridgeWords(int, int) const;
    std::string RandomBridgeWords(int, int) const;
};

extern void showDirectedGraph(const Graph&, const std::string&);
extern std::string queryBridgeWords(const Graph&,
                                    const std::string&,
                                    const std::string&);
extern std::string generateNewText(const Graph&, const std::string&);
extern std::string calcShortestPath(const Graph&, 
                                    const std::string&, 
                                    const std::string&);
extern std::string calcShortestPath(const Graph&, const std::string&);
extern std::string randomWalk(const Graph&);

#endif // __GRAPH_H_
