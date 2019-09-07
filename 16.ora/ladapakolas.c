#include <stdio.h>

int main(){
	int i, hossz, j, k, l, marad;
	marad = 0;
	scanf("%d", &hossz);
	char lada[hossz+1];
	scanf("%s", lada);
	/*for(i=0;i<hossz;i++){
		//for(j=hossz-1;j>=0;j--){
			
		//}
		j = hossz;
		while(lada[j]!='C' && j>=0){
			j--;
		}
		if(j>0){
			k = j-1;
			while(lada[k]!='B' && k>=0){
				k--;
			}
			if(k>0){
				lada[j] = 'c';
				lada[k] = 'X';
				l = k-1;
				while(lada[l]!='A' && l>=0){
					l--;
				}
				if(lada[l]=='A'){
					lada[l] = 'X';
				}
			}
		}
	}
	for(i=0;i<hossz;i++){
		j = hossz;
		while(lada[j]!='C' && j>=0){
			j--;
		}
		if(j>0){
			k = j-1;
			while(lada[k]!='A' && k>=0){
				k--;
			}
			if(k>0){
				lada[j] = 'c';
				lada[k] = 'X';
			}
		}
	}
	for(i=0;i<hossz;i++){
		j = hossz;
		while(lada[j]!='B' && j>=0){
			j--;
		}
		if(j>0){
			lada[j] = 'b';
			k = j-1;
			while(lada[k]!='A' && k>=0){
				k--;
			}
			if(k>0){
				lada[k] = 'X';
			}
		}
	}*/
	for(i=0;i<hossz;i++){
		j = 0;
		while(lada[j]!='C' && j<=hossz+1){
			j++;
		}
		if(j<hossz+1){
			k = j+1;
			while(lada[k]!='B' && k<=hossz+1){
				k++;
			}
			if(k<hossz+1){
				lada[j] = 'X';
				lada[k] = 'b';
			}
		}
	}
	for(i=0;i<hossz;i++){
		j = 0;
		while(lada[j]!='b' && j<=hossz+1){
			j++;
		}
		if(j<hossz+1){
			k = j+1;
			while(lada[k]!='A' && k<=hossz+1){
				k++;
			}
			if(k<hossz+1){
				lada[j] = 'X';
				lada[k] = 'a';
			}
		}
	}
	for(i=0;i<hossz;i++){
		j = 0;
		while(lada[j]!='B' && j<=hossz+1){
			j++;
		}
		if(j<hossz+1){
			k = j+1;
			while(lada[k]!='A' && k<=hossz+1){
				k++;
			}
			if(k<hossz+1){
				lada[j] = 'X';
				lada[k] = 'a';
			}
		}
	}
	for(i=0;i<hossz;i++){
		j = 0;
		while(lada[j]!='C' && j<=hossz+1){
			j++;
		}
		if(j<hossz+1){
			k = j+1;
			while(lada[k]!='A' && k<=hossz+1){
				k++;
			}
			if(k<hossz+1){
				lada[j] = 'X';
				lada[k] = 'a';
			}
		}
	}
	for(i=0;i<hossz;i++){
		printf("%c", lada[i]);
		if(lada[i]=='A' || lada[i]=='B' || lada[i]=='b' || lada[i]=='C' || lada[i]=='a'){
			marad++;
		}
	}
	printf("%d\n", marad);
	return 0;
}
