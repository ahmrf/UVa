#include <bits/stdc++.h>

using namespace std;

int main()
{
	char o = 243;
	string nos = "n";
	nos += o;
	nos += "s      ";
	string vos = "v";
	vos += o;
	vos += "s      ";

	string pronouns[] = {"eu       ", "tu       ", "ele/ela  ", nos, vos, "eles/elas"};
	string suffix[] = {"ar", "er", "ir"};
	string ar[3][6] = {{"o", "as", "a", "amos", "ais", "am"},
						{"o", "es", "e", "emos", "eis", "em"},
						{"o", "es", "e", "imos", "is", "em"}};
	string portuguese, english;
	bool blank = false;
	while(cin >> portuguese >> english)
	{
		if(blank) puts("");
		blank = true;
		cout << portuguese << " (to " << english << ")" << endl;
		int len = portuguese.length();
		
		if(len < 2) puts("Unknown conjugation");
		else
		{ 
			string root = "", s = "";
			for(int i = 0; i < len-2; i++)
			{
				root += portuguese[i];
			}
			s += portuguese[len-2];
			s += portuguese[len-1];

			bool notfound = true;
			for(int i = 0; i < 3; i++)
			{
				if(s == suffix[i])
				{
					notfound = false;
					for(int j = 0; j < 6; j++)
					{
						cout << pronouns[j] << " " << root+ar[i][j] << endl;
					}
				}
			}
			if(notfound) puts("Unknown conjugation");
		}
		
	}
	return 0;

}