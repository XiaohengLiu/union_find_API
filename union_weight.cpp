#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<time.h>
using namespace std;
#define LENGTH 1024

int id[16384];			//including all the possible id
int sz[16384];

int root(int i)
{
	while(i != id[i])
		i = id[i];
	return i;
}

void connected(int p, int q)
{
	if (root(p) == root(q))
		cout<<p<<" and "<<q<<" is connected"<<endl;
	else
		cout<<p<<" and "<<q<<" is NOT connected"<<endl;
}

void union1(int p, int q)      //union weight
{
	int i = root(p);
	int j = root(q);
	if(sz[i] <sz[j])
	{
		id[i] = j; sz[j] += sz[i];
	}
	else
	{
		id[j] = i; sz[i] += sz[j];
	}

}


void main()
{
	int a[LENGTH*2];
	int x = 0 ;
	int temp;  //temperary number in file.
	FILE *p;
	p = fopen("1024pair.txt","r");
	while(fscanf(p,"%d ",&temp)!= -1) //give the instance in file to the array "a"
	{ 
	a[x]=temp; 
	x++; 
	}
	for(int i = 0; i < 16384; i++)    //initializing the id array
	id[i] = i;
	for(int x = 0; x < 16384; x++)	//initializing the sz array
		sz[x] = 1;
	clock_t start_time = clock();
	for(int k = 0; k < 1000; k++)     //loop 1000 times, since the time of one simulation is too small
	{
		for(int j = 0; j < LENGTH; j = j + 2)
			union1(a[j],a[j+1]);     // union each pairs
	}
	clock_t end_time = clock();
	cout<<"After unioning all pairs, to test the connection : "<<endl;
	connected(a[0],a[1] );      // to test whether union successfully
	cout<<endl<<"Total time of unioning"<<LENGTH<<" is "<<(float)(end_time - start_time)<< " ms"<<endl;
}