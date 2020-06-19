/*
Graph.cpp
*/
#include<iostream>
#include<list>
#include<set>
#include<vector>
#include<stack>
using namespace std;

class Graph {
	int nodes;
	int edges;
	list<int> *adj;
public:
	Graph() {
		adj = NULL;
		nodes = 0;
	}
	Graph(int numberOfNodes) {
		nodes = numberOfNodes;
		adj = new list<int>[nodes];
	}

	void addEdge(int u, int v) {
		adj[u].push_back(v);
	}

	void topoSortUtil(vector<bool> &visited, stack<char> &container, int u) {
		if (visited[u] == false) {
			visited[u] = true;
			for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
				topoSortUtil(visited, container, *it);
			}
			container.push(u + 'a');
		}
	}
	vector<char> topologicalSort() {
		vector<char> result;
		stack<char> container;
		vector<bool> visited(nodes, false);
		for (int i = 0; i < nodes; i++) {
			if (visited[i] == false) {
				topoSortUtil(visited, container, i);
			}
		}
		while (!container.empty()) {
			char data = container.top();
			container.pop();
			result.push_back(data);
		}
		return result;
	}
};
/*
main.cpp
*/
#include<iostream>
#include<set>
#include "Graph.cpp"

using namespace std;
vector<char> printDictionary(Graph &G, string words[], int n) {
	vector<char> result;
	int l = words->size();
	if (l <= 0)
		return result;

	for (int i = 0; i < l - 1; i++) {
		string word1 = words[i];
		string word2 = words[i + 1];
		int l1 = word1.length();
		int l2 = word2.length();
		//Taken the smaller size
		int len = (l1 < l2) ? l1 : l2;

		//we will compare the consecutive two words character by character and 
		//create the Graph where edge will be from smaller to the higher value
		for (int k = 0; k < len; k++) {
			if(word1[k] != word2[k])
				G.addEdge(word1[k] - 'a', word2[k] - 'a');
		}
	}
	
	result = G.topologicalSort();
	return result;
}
int main() {
	string words[] = { "caa", "aaa", "aab" };
	//We have simple assumption that the value we pass to Graph we have that many character in the
	//alphabet and from english lower case i.e. here for 3 we have a, b and c in alphabet and we 
	//always have a valid result
	Graph G(3);
	vector<char> result = printDictionary(G, words, 3);

	for (auto it = result.begin(); it != result.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	return 0;
}
