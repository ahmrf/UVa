#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#include <set>

using namespace std;

vector<string> dictionary[30];
map <string, vector<string> > adj;

bool are_doublets(string a, string b)
{
	int len = a.length();
	
	int c = 0;
	for(int i = 0; i < len; i++) {
		if(a[i] != b[i]) c++;
	}
	return c == 1;
}

void compute(vector<string> words)
{
	int sz = words.size();
	for(int i = 0; i<sz; i++) {
		for(int j = i+1; j<sz; j++) {
			if(are_doublets(words[i], words[j])) {
				adj[words[i]].push_back(words[j]);
				adj[words[j]].push_back(words[i]);
			}
		}
	}
}

bool solved(string s, string t, vector<string> &ret)
{
	map<string, string> parent;
	set<string> seen;
	bool found = false;
	seen.insert(s);
	queue<string> Q;
	parent[s] = "";
	Q.push(s);

	while(!Q.empty()) {
		string u = Q.front();
		Q.pop();


		int sz = adj[u].size();
		for(int i = 0; i<sz; i++) {
			string v = adj[u][i];
			if(seen.find(v) == seen.end()) {
				parent[v] = u;
				seen.insert(v);
				Q.push(v);
				if(v == t) {

					found = true;
					break;
				}
			}
		}
	}

	if(found) {
		while(1) {
			ret.push_back(t);
			if(t == s) break;
			t = parent[t];
		}
	}

	return found;
}

int main()
{
	string word;
	bool alreadySolved[30] = {false};
	while(getline(cin, word)) {
		if(word == "") break;
		dictionary[word.length()].push_back(word);
	}

	string a, b;
	bool enter = false;
	while(cin >> a >> b) {
		if(enter) puts("");
		enter = true;
		int len = a.length();
		if(len != b.length()) puts("No solution.");
		else {
			vector<string> ret;
			if(!alreadySolved[len]) {
				alreadySolved[len] = true;
				compute(dictionary[len]);
			}

			if(solved(a, b, ret)) {
				for(int i = ret.size()-1; i>=0; i--) {
					cout << ret[i] << endl;
				}
			}
			else puts("No solution.");
		}
	}
	return 0;
}