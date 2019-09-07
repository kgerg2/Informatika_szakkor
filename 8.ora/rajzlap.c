#include <stdio.h>

struct pont{
	int x, y;
};

int main(){
	int i, j;
	FILE *fa;
	struct pont bf;
	bf.x = 0;
	bf.y = 0;
	
	fa = fopen("tabla.svg","w");
	fprintf(fa, "<svg width='430' height='430' xmlns='http://www.w3.org/2000/svg' version='1.1'>\n");
	//Négyzetrács
	for(i=0;i<41;i++){
		bf.x = bf.x+10;
		for(j=0;j<41;j++){
			bf.y = bf.y+10;
			fprintf(fa, "\t<rect x='%d' y='%d' width='10' height='10' stroke='black' fill='white'>\n\t</rect>", bf.x, bf.y);
		}
		bf.y = 0;
	}
	//Kör
	srand((unsigned int) time(NULL));
	fprintf(fa, "\n\t<circle cx='215' cy='215' r='4' stroke='white' fill='white'>\n\t\t<animate\n\t\tattributeName='fill'\n\t\tattributeType='XML'\n\t\tfrom='white' to='black'\n\t\tbegin='1s' dur='1s'\n\t\tfill='freeze'\n\t\t/>\n\t</circle>\n");
	
	fprintf(fa, "</svg>");
	fclose(fa);
	return 0;
}
