//263 Numbers Chains
#include <stdio.h>
#include <map>
#include <string.h>
using namespace std;

char number[15],a1[15],a2[15];
int a,b,c;
map<int,int> mapa;

void sort1()
{
	char t;
		for(int i=0; number[i]!='\0'; i++)
			for(int j=i+1; number[j]!='\0'; j++)
				if(number[i]>number[j])
				{
					t = number[i];
					number[i] =  number[j];
					number[j] = t;
				}
}

int sort2()
{
	char t;
	for(int i=0; number[i]!='\0'; i++)
		for(int j=i+1; number[j]!='\0'; j++)
			if(number[i]<number[j])
			{
				t = number[i];
				number[i] =  number[j];
				number[j] = t;
			}
}

void copy(char *v)
{
	int i;
	for( i=0; number[i]!='\0'; i++)
		v[i] = number[i];
	v[i] = '\0';	
}

int main()
{
	int cont;
	while(scanf("%s", number), number[0]!='0')
	{
		cont = 1;
		mapa.clear();
		printf("Original number was %s\n", number);
		while(1)
		{
			sort1();
			copy(a2);
			sort2();
			copy(a1);
			sscanf(a1,"%d", &a);
			sscanf(a2,"%d", &b);
			c = a-b;
			printf("%d - %d = %d\n",a,b,c);
			if(mapa[c]==1)
				break;
			else mapa[c] = 1;
			sprintf(number,"%d",c);
			cont ++;
		}
		printf("Chain length %d\n\n", cont);
	}
	
	return 0;
}
