#include <bits/stdc++.h>

using namespace std;

int main()
{
	int nop;
	bool enter = false;
	while(cin >> nop) {
		map<string, int> G;
		string name;
		vector <string> names(nop);
		for(int i = 0; i<nop; i++) {
			cin >> name;
			names[i] = name;
			G[name] = 0;
		}

		for(int i = 0; i<nop; i++) {
			int nor, amount;
			cin >> name >> amount >> nor;
			if(nor == 0) continue;
			int gift = amount / nor;
			G[name] += ((amount % nor) - amount);
			for(int j = 0; j<nor; j++) {
				cin >> name;
				G[name] += gift;
			}
		}

		if(enter) puts("");
		enter = true;
		for(int i = 0; i<names.size(); i++)
			cout << names[i] << " " << G[names[i]] << endl;

	}
	return 0;
}