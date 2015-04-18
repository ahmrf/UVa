#include <string.h>
#include <stdio.h>

int main() {
	int cases, i, j, enter = 0;
	char replace[200], original[100], cypher[100], text[100];
	scanf("%d\n", &cases);
	while(cases--) {
		gets(original);
		gets(cypher);
		int sl = strlen(original);
		memset(replace, 1, sizeof replace);
		for(i = 0; i < sl; i++) {
			replace[original[i]] = cypher[i];
		}
		if(enter) puts("");
		puts(cypher);
		puts(original);
		enter = 1;
		while(gets(text)) {
			if(!strcmp(text, "")) break;
			sl = strlen(text);
			for(i = 0; i < sl; i++) { 
				if(replace[text[i]] == 1) 
					printf("%c", text[i]);
				else printf("%c", replace[text[i]]);
			}
			puts("");

		}
	}
	return 0;
}