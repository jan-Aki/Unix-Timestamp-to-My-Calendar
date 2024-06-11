#include<stdio.h>
#include<stdlib.h>

int main()
{
	long input;
	long period=1;
	long month=1;
	printf("Enter a Unix timestamp in seconds: ");
	scanf("%ld",&input);
	
	//convert epoch time to days since January 11 2024
	input=86400*((input-1704931200)/86400);
	long intermediate=1+input/86400;
	//printf("%ld\n",intermediate);



	while(intermediate>503)//find period
	{
		if((period-1)%50==0)
		{
			intermediate=intermediate-503;
		}else
		{
			intermediate=intermediate-502;
		}
		period++;
	}
	if((period-1)%50!=0  &&  intermediate==503)//edge case
	{
		printf("%ld/01/01\n",period+1);
		return 0;
	}
	//intermediate now holds the number of days into the period in question
	//printf("%ld\n",intermediate);



	//getting rid of the complications at the beginning of a period
	if(intermediate<30)
	{
		printf("%ld/1/%ld\n",period,intermediate);
		return 0;
	}
	if(intermediate==30  &&  (period-1)%50==0)
	{
		printf("%ld/1/30\n",period);
		return 0;
	}
	if((period-1)%50==0)
	{
		intermediate=intermediate-30;
	}else
	{
		intermediate=intermediate-29;
	}
	month++;


	while(intermediate>30)
	{
		if(month%17==0 || month%2==0)
		{
			intermediate=intermediate-30;
		}else
		{
			intermediate=intermediate-29;
		}
		month++;
	}
	if (intermediate==30  &&  (month%17!=0 || month%2!=0))
	{
		printf("%ld,%ld,1\n",period,month+1);
		return 0;
	}

	printf("%ld/%ld/%ld\n",period,month,intermediate);
	return 0;
}