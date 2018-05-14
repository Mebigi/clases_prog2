#include<stdio.h>
#include<time.h>

void tiradaDado(int*);

int main()
{
	int vec[]={0,0,0,0,0,0};
	int i;
	tiradaDado(vec);
	
	for(i=0; i<6; i++)
	{
		printf("%d:%d\n", i+1, vec[i]);
	}
	system("pause");
	return 0;
}

void tiradaDado(int* dado)
{
	int i;
	srand(time(NULL));
	
	for(i=0; i<10000; i++)
	{
		*(dado+(rand()%6))+=1;
	}
}


