#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<time.h>
using namespace std;
#define LENGTH 8*2

int id[8192];			//including all the possible id

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

void union1(int p, int q)
{
	int i = root(p);
	int j = root(q);
	id[i] = j;
}


void main()
{
	int a[LENGTH*2];
	int x = 0 ;
	int temp;  //temperary number in file.
	FILE *p;
	p = fopen("8pair.txt","r");
	while(fscanf(p,"%d ",&temp)!= -1) //give the instance in file to the array "a"
	{ 
	a[x]=temp; 
	x++; 
	}
	for(int i = 0; i < 8192; i++)    //initializing the id array
	id[i] = i;
//	for(int k = 0; k < 1000; k++)     //loop 1000 times, since the time of one simulation is too small
		for(int j = 0; j < LENGTH; j = j + 2)
			union1(a[j],a[j+1]);     // union each pairs
	cout<<"After unioning all pairs, to test the connection : "<<endl;	
	clock_t start_time = clock();
	for(int k = 0; k < 1000; k++)
	connected(a[0],a[1] );      // to test whether union successfully
	clock_t end_time = clock();
	cout<<endl<<"Total time of unioning"<<LENGTH/2<<" is "<<(float)(end_time - start_time)<< " ms"<<endl;
}