//Implementation of refined solution in C language
#include<stdio.h>

long long int dp[300][300][300];    //3D dp array for part 1; dp = dynamic programming
int done[300][300][300];  //Done array
long long int pwr[300][300][300];   //3D dp array for part 2

long long int count_allp(int n, int m);
long long int compute(int index, int num, int rem, int i);
long long int count_pwr(int n,int m,int pre);

//Main function
int main()
{
    int i,N;
    long long int c1,c2;

    //User Input
	printf("Enter a number : ");
	scanf("%d", &N);

	//c1 stores the count of all partitions
	//c2 stores the count of partitions without repetitions
	c1=0;
    for(i=1;i<=N;i++){
    	c1 += count_allp(N,i);     //calling the corresponding function
	}
	c2=count_pwr(N,N,10000);       //we need to pass a large number as the third argument

	printf("\nCount of all partitions : %lld\nCount of non - repetitive partitions : %lld",c1,c2);
}

//The below function returns the number of ways in which n can be partitioned as a sum of m numbers
long long int count_allp(int n, int m)
{
	int i,j,k,result;

    //Initialization of each element in 3D dp array to -1
    for(i=0;i<300;i++){
    	for(j=0;j<300;j++){
    		for(k=0;k<300;k++){
    			dp[i][j][k]=-1;
			}
		}
	}

	result=compute(0,1,n,m); //calling compute function
    return result;
}

/*The below function makes use of the dp array in solving identical subproblems
The number N is being partitioned as a sum of i numbers
index = position from 0 to i
num = the number at index position
rem = the remaining sum left after gradually reducing N*/
long long int compute(int index, int num, int rem, int i)
{
    int j,dp_value;

	//Base Condition
    if(index==i){
        if(rem==0)
            return 1;
        else
            return 0;
    }

    //If N is partitioned as a sum of less than i numbers
    if(rem==0)
        return 0;

    //Using the memoized value if a subproblem has already been solved
    if(dp[index][num][rem]!=-1)
        return dp[index][num][rem];

    dp_value = 0;
    for(j=num;j<=rem;j++) {
        dp_value+=compute(index+1,j,rem-j,i);   //recursive call
    }
    dp[index][num][rem]=dp_value;
    return dp[index][num][rem];
}

//The below function returns the number of partitions without repetitions
long long int count_pwr(int n,int m,int pre)
{
	//the partitioning is done and we have obtained the solution
	if(n==0)
	{
		return 1;
	}

 	//partitioning is not possible
	else if(n>0&&m==0)
	{
		return 0;
	}

	//If the result is already computed we will simply return it
	else if(done[n][m][pre]==1)
	{
		return pwr[n][m][pre];
	}

	//Start computation if required to
	//We will use Memoization here
	else
	{
		done[n][m][pre]=1;
		for (int i=0;i<=n;i++)
		{
			//we need to proceed if the current value is lower than the previous one
			if(i<pre)
			{
				pwr[n][m][pre]+=count_pwr(n-i,m-1,i);
			}
		}
		return pwr[n][m][pre];
	}

}


