#include<iostream>
using namespace std;
 
void func(long A[],long l)
{
	long B[l];
	for(long i=0;i<l;i++)
	B[i]=0;
 
	for(long i=0;i<l;i++)
	{
	long m=5;
	while (A[i]/m!=0)
	 { 
		B[i]=B[i]+A[i]/m;
		m=m*5;
	 } 
    }
	for(long i=0;i<l;i++)
	cout<<B[i]<<"\n";
	
}
int main()
{
	long l,i;
	cin>>l;
	long A[l];
	for(i=0;i<l;i++)
	{
		cin>>A[i];
		
    }
    func(A,l);
    return 0;
}   
