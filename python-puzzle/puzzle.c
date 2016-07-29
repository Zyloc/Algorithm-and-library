#include <stdio.h>
int main(){
	char s;
	while(1){
		scanf("%c",&s);
		if ((int)s!=32 && s!="." && s!="'" && s!="(" && s!=")" ){
			if (s=='z'){
				printf("b");
			}
			else if(s=='y'){
				printf("a");
			}
			else
				printf("%c",(char)s+2);
		}
		else{
			printf(" ");
		}
	}
	return 0;
}