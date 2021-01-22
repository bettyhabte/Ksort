#include <string>
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <random>


using namespace std;

/*prototypes*/
void build_min_heap(int	arr[], int n);
void min_heapify(int arr[],int n, int i );
void swap(int arr[], int x, int y);
void heapsort(int arr[],int n);


/*the bild minheap function 
 brings the smallest to the parent node*/
void build_min_heap(int	 arr[], int n)
{
	int start = floor(n/2);
	
	for(int i =start; i>=0;i--)
	{
		min_heapify(arr, n, i);
	}
	
}
/*left function returns the index of the left child*/
int left(int i)
{
	return (2*(i+1)-1);
	
}
/*right function returns the index of the right child*/
int right(int i)
{
	return (2*(i+1));
}
/*the min-heapify function checks the left and the right value of the parent
 check with the left(the smallest)
 check with the right(the smallest)
 check if the parent is the smallest
 if the children is the smallest
 then swap, and minheapify the smallest*/
 
void min_heapify(int  arr[],int n, int i )
{
	int l = left(i);
	int r = right(i);
	int smallest;
	
	if( l < n && (arr[l]<arr[i]))
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}
	if( r < n && (arr[r] < arr[smallest]))
	{
		smallest = r;
	}
	
	if( smallest != i)
	{
		swap(arr,i, smallest);
		
		
		min_heapify(arr, n, smallest);
	}
}
/*swap the two numbers*/
void swap(int  arr[], int  x, int  y)
{
	
	int temp;
	
	temp = arr[x];
	arr[x]=arr[y];
	arr[y] = temp;
	
}
void heapsort(int  arr[], int n)
{
	/*first builds the array into min heap
	 then sort*/
	build_min_heap(arr, n);
	
	/*cout<<"after build"<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<arr[i]<<endl;
	}*/
	
	/*sort it by swaping the first and the last number
	 then min-heapify the rest(remove the last item*/
	for(int i = n-1; i>=0; i--)
	{
		
		swap(arr, i, 0);
		
		min_heapify(arr, i, 0);
		
	}
}

int main()
{
	/*first rwquest the input
	 then parse it*/
	cout << "please enter the numbers" << endl;
	string input;
	
	
	
	getline(cin, input);//gets the entire line until hit enter
	/*this will count the numbers
	 by checking the spaces*/
	int n = 1;
	for( int i= 0; i< input.length(); i++)
	{
		if (input[i] == ' ')
		{
			n++;
		}
	}

	/*gets the numbers
	 place it in temp*/
	int *numbers = new int[n];
	
	istringstream stream(input);
	int temp;
	int i=0;
	while( stream >> temp)
	{
		
		numbers[i] = temp;
		i++;
		
	}
	
	cout <<"please enter your k value"<<endl;
	int k;
	cin>>k;
	/*calls heap sort
	 prints out the sorted array*/
	heapsort(numbers, n);
	
		/*revers the array to make it accending order*/
	
	for(i=0; i<((n)/2); i++)
	{
		swap(numbers, i, n-1-i);
		
	}
	/*cout<<"after sort"<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<numbers[i]<<endl;
	}*/

	
	
	
	/*we have the sorted array,randomize it into k-sorted*/
	int r;
	for( int i=0; i<n-k-1;)
	{
		r = rand()%k;
		swap(numbers, numbers[i], numbers[i+r]);
		i = i + k + 1;
	}
	cout<<"random k"<<endl;
	
	for(int i = 0; i < n; i++)
	{
		cout<<numbers[i]<<endl;
	}
	
	heapsort(numbers, n);
	
	
	/*revers the array to make it accending order*/
	
	for(i=0; i<((n)/2); i++)
	{
		swap(numbers, i, n-1-i);
		
	}
	cout<<"sort after k-sort"<<endl;
	for(int i = 0; i < n; i++)
	{
		cout<<numbers[i]<<endl;
	}

	
	
	
	
}