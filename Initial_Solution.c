#include <stdio.h>

//declaring the required functions
void partitions(int arr[], int arr1[], int counter[], int N);
void count_allp(int a, int arr[], int counter[], int index, int N);
void count_pwr(int a, int arr[], int counter[], int index, int N);

int main()
{
	//taking input from user
	int N;
	printf("Enter the Number: ");
	scanf("%d", &N);

	//Declaring and Initialising the required array elements to 0
	int counter[2] = {0};
	int arr[N], arr1[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = 0;
		arr1[i] = 0;
	}

	//calling the funciton which does the job of partitioning
	partitions(arr,arr1,counter,N);

	// giving the output
	printf("Count of All Partitions = %d\n", counter[0]);
	printf("Count of Partitions without Repetitions = %d\n", counter[1]);

}

void partitions(int arr[], int arr1[], int counter[], int N )
{
	//we will be adding all the computations from 1 to N when repititions are allowed
	for (int i = 1 ; i <= N; i++)
	count_allp(i, arr, counter, 0, N);
	// we will do the same procedure but here repitions are not allowed
	for (int i = 1 ; i <= N; i++)
	count_pwr(i, arr1, counter, 0, N);

}

void count_allp(int summand, int arr[], int counter[], int index, int N)
{
	/*summand = starting summand,
	arr = the values upto now in a partial particular partition,
	counter = an array to store the count of partitions,
	index = denotes the index in an array,
	N = our number of interest i.e. user inputted number*/

	//using a new array named arr_new to store the values of arr
	//This is done to preserve the values of arr and we will start counting with arr_new
	int arr_new[N];
	for (int i = 0; i < N; i++)
	{
		arr_new[i] = arr[i];
	}

	arr_new[index] = summand;

	//using a variable sum which stores the sum of all the elements in arr_new
	//will be usefull to terminate the function call when sum reaches N
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr_new[i];
	}
	//partitioning is no longer possible as sum crosses N
	if (sum > N)
		return;
	//If sum=N then a partition is obtained
	else if (sum == N)
	{
		//we will increment counter vlaue by 1
		counter[0]++;
		return;
	}
	//computing the number of partitions with starting summand as i for N - 1 while the starting summand for N is still summand
	//here i starts from summand so that all partitions are counted
	else
	{
		for (int i = summand; i <= N; i++)
		{
			count_allp(i, arr_new, counter, index + 1, N);
		}
	}

}

void count_pwr(int summand, int arr[], int counter[], int index, int N)
{
	/*summand = starting summand,
	arr = the values upto now in a partial particular partition,
	counter = an array to store the count of partitions,
	index = denotes the index in an array,
	N = our number of interest i.e. user inputted number*/

	//using a new array named _arr to store the values of arr
	//This is done to preserve the values of arr and we will start counting with _arr
	int _arr[N];
	for (int i = 0; i < N; i++)
	{
		_arr[i] = arr[i];
	}

	_arr[index] = summand;

	//using a variable sum which stores the sum of all the elements in _arr
	//will be usefull to terminate the function call when sum reaches N
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += _arr[i];
	}
	//partitioning is no longer possible as sum crosses N
	if (sum > N)
		return;
	//If sum=N then a partition is obtained
	else if (sum == N)
	{
		//we will increment counter vlaue by 1
		counter[1]++;
		return;
	}
	//computing the number of partitions with starting summand as i for N - 1 while the starting summand for N is still summand
	//here i starts from summand + 1 so that no repetition is ensured
	else
	{
		for (int i = summand + 1; i <= N; i++)
		{
			count_pwr(i, _arr, counter, index + 1, N);
		}
	}

}
