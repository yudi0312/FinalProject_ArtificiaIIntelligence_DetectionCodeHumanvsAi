// Libraries that were used
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <list>
#include <utility>

using namespace std;

// Global Variables
stack<int> pilha;
vector< list<int> > scc_table, table;
bool *inStack;
int *low, *d, *scc, *minNodes, points, discTime = 1, n_scc = 0;

/* ---------------------- getMinNode --------------------------------
| Returns the minimal node for a certain strongly connected component
------------------------------------------------------------------ */
int getMinNode(int scc_id) {
	for(int i = 0; i < points; i++) {
		if (scc[i] == scc_id)
			return ++i;
	}
	return -1;
}

/* ---------------------------- dfs ---------------------------------
| Searchs connections between strongly connected components
------------------------------------------------------------------ */
void dfs(vector<list<int> > table) {
	for(int linha = 0; linha < points; linha++) {
		for (int &i: table[linha]) {
			if (scc[linha] != scc[i - 1]) {
				scc_table[scc[linha]].push_back(scc[i - 1]);
			}
		}
	}
}

/* ------------------------- tarjan ---------------------------------
| Applies Tarjan algorithm to the graph that was inputed by the user
------------------------------------------------------------------ */
void tarjan(int current) {
	if (d[current] == -1) {
		d[current] = discTime;
		low[current] = discTime++;
		pilha.push(current + 1);
		inStack[current] = true;
	}

	for (int &i: table[current]) {
		if(d[i - 1] == -1){
			tarjan(i - 1);
			low[current] = min(low[current], low[i - 1]);
		}
		else if(inStack[i - 1])
			low[current] = min(low[current], low[i - 1]);
	}
	if (d[current] == low[current]){
		int v = 0;
		do {
			v = pilha.top();
			pilha.pop();
			inStack[v - 1] = false;
			scc[v - 1] = n_scc;
		} while (current + 1 != v && !pilha.empty());
		n_scc++;
	}
}

/* ----------------------- print_scc --------------------------------
| Used to print a strongly connected component
------------------------------------------------------------------ */
void print_scc() {
	int i = 0;
	for(list<int> l: scc_table) {
		cout << i++ << ": ";
		for(int &x: l)
			cout << x << " ";
		cout << "\n";
	}
}

bool comparator(const pair<int,int>* v1, const pair<int,int>* v2){
	return  v1->first < v2->first;
}

/* -------------------------- mySort --------------------------------
| Function that is used in the sort to compare between the minimum
| node of each strongly connected component
------------------------------------------------------------------ */
bool mySort(const int i1, const int i2){
	return minNodes[i1] < minNodes[i2];
}


/* --------------------------- main ---------------------------------
| Executes the program
------------------------------------------------------------------ */
int main() {
	int connections, init, end, i, linha, n_con = 0;
	list<int> *l = new list<int>();
	vector<pair<int,int>*> coordenadas;

	scanf("%d", &points);
	scanf("%d", &connections);

	if(points < 2 || connections < 1) {
		printf("First argument must be greater than 2 and second argument must be greater than 1\n");
		exit(1);
	}

	for(i = 0; i < points; i++)
		table.push_back(*l);

	while (connections-- != 0) {
		scanf("%d %d", &init, &end);
		table[init - 1].push_back(end);
	}

	scc = new int[points];
	low = new int[points];
	d = new int[points];
	inStack = new bool[points];

	for(i = 0; i < points; i++) {
		d[i] = -1;
		low[i] = 0;
		inStack[i] = false;
	}

	for(i = 0; i < points; i++) {
		if (d[i] == -1)
			tarjan(i);
	}

	for(i = 0; i < n_scc; i++)
		scc_table.push_back(*l);

	dfs(table);
	free(d);
	free(low);
	free(inStack);
	minNodes = new int[n_scc];
	for (i = 0; i<  n_scc; i++)
		minNodes[i] = getMinNode(i);
	for(i = 0; i < n_scc; i++) {
		scc_table[i].sort();
		scc_table[i].unique();
		scc_table[i].sort(mySort);
		n_con += scc_table[i].size();
	}
	free(minNodes);
    	pair<int,int> *pares;
	for(i = 0; i < n_scc; i++) {
		pares->first = getMinNode(i);
		pares->second = i;
		coordenadas.push_back(pares);
	}
	sort(coordenadas.begin(), coordenadas.end(), comparator);
	printf("%d\n%d\n", n_scc, n_con);
	for(i = 0; i < n_scc; i++) {
		linha = coordenadas[i]->first;
		for(int &x: scc_table[coordenadas[i]->second])
			printf("%d %d\n", linha, getMinNode(x));
	}
	free(scc);
	return  0;
}
