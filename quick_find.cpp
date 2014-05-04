#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include<time.h>
using namespace std;

#define LENGTH 8192*2


void connected(int id[], int p, int q)             // whether two elements are connected
{
	if (id[p] == id[q])
		cout<<p<<" and "<<q<<" is connected"<<endl;     //connected
	else
		cout<<p<<" and "<<q<<" is not connected"<<endl;   //not connected
}
			


void union1(int id[], int p, int q)      //can not use the name of "union", so using "union1" instead
{
	int pid = id[p];
	int qid = id[q];
	for(int i = 0; i < 8192; i++)    //
	{
		if(id[i] == pid)
			id[i] = qid;
	}
}


void main()
{
	int a[LENGTH];
	int x = 0 ;
	int temp;  //temperary number in file.
	FILE *p;
	p = fopen("8192pair.txt","r");
	while(fscanf(p,"%d ",&temp)!= -1) //give the instance in file to the array "a"
	{ 
	a[x]=temp; 
	x++; 
	}
	int id[8192];
	for(int i = 0; i < 8192; i++)    //initializing the id array
		id[i] = i;
	clock_t start_time = clock();
//	for(int k = 0; k < 1000; k++)     // facing small N to loop 1000 times
	for(int j = 0; j < LENGTH; j = j + 2)
		union1(id,a[j],a[j+1]);     // union each pairs		
	clock_t end_time = clock();
	connected(id, a[0],a[7] );      // to test whether union successfully
	cout<<endl<<"Total time of unioning"<<LENGTH/2<<" is "<<(float)(end_time - start_time)<< " ms"<<endl;
}