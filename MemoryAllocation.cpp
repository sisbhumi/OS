#include<iostream>
using namespace std;

class MemoryAllocation
{
	public:
	int amtProcess , amtBlocks ;
	int *blockSize , *processSize , *allocation , *flag ;
	void input() ;
	void First_Fit() ;
	void output() ;
};

void MemoryAllocation :: input()
{
	cout<<"Enter the number of memory blocks available :" ;
	cin>>amtBlocks;
	
	blockSize = new int [amtBlocks] ;
	flag = new int[amtBlocks] ;
	
	cout<<"\nEnter the size of each block.";
	for(int i = 0 ; i<amtBlocks ; i++)
	{
		cin>>blockSize[i];
		flag[i] = 0 ; //no process allocated
	}
	
	cout<<"\nEnter the number of processes : ";
	cin>>amtProcess;
	
	processSize = new int [amtBlocks] ;
	allocation = new int [amtProcess] ;
	
	cout<<"\nEnter the size of each process.\n";
	for( int i=0 ; i<amtProcess ; i++ )
	{
		cin>>processSize[i];
		allocation[i] = -1 ; //not allocated memory
	}
}

void MemoryAllocation :: First_Fit()
{
	for( int i=0 ; i<amtProcess ; i++)
		for(int j = 0 ; j<amtBlocks ; j++)
		{
			if( processSize[i] <= blockSize[j] && flag[j] == 0  )
			{
				allocation[i] = j ;
				flag[j] = 1;
				break; // ith process is allocated to jth memory block
			}
		}
}

void MemoryAllocation :: output()
{
	cout<<"Process no.\tProcess size\tMemory Block\tMemory Size\n";
	for( int i=0 ; i<amtProcess ; i++ )
	{
		cout<<i<<"\t"<<processSize[i]<<"\t";
		if( flag[allocation[i]] == 1 )
		{
			cout<<allocation[i]<<"\t\t"<<blockSize[allocation[i]]<<"\n";
		}
		else cout<<"NOT Allocated.\n";
	}
}

int main()
{
	MemoryAllocation pc;
	pc.input();
	pc.First_Fit();
	pc.output();
	
	
}
