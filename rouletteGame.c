//Roulette Game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void showInstructions();
float getBetAmount();
void makeBet(int *, int *);
int spinWheel();
float figureWinnings(int *, int *, float, int);

int main()
{
	char replay;
	int betType, bet, spin;
	float betAmount, winnings;
	showInstructions();
	
	do{
		makeBet(&betType, &bet);
		betAmount=getBetAmount();
		spin=spinWheel();
		winnings = figureWinnings(&betType, &bet, betAmount, spin);
		printf("The number spun is: %d\n", spin);
		
		if(winnings > 0){
			printf("YOU WON %.2f DOLLARS!!!\n", winnings);
		}else{
			winnings= winnings * -1;
			printf("YOU lost %.2f DOLLARS!!!\n", winnings);
		}
		
		printf("\n\nPress 'Y' To Play Again\n");
		printf("Press Any Character To Quit\n");
		scanf(" %c", &replay);	
	} while (replay == 'Y' || replay == 'y');
	
	printf("Thank You for playing\n");
	
	return 0;
	
}
void showInstructions()
{
	printf("The roulette wheel has the numbers 0-36 on it.\n");
	printf("You can place your bet in one of three ways\n");
	printf("\t\t1.	Bet on a number (payout is 36 times the bet amount)\n");
	printf("\t\t2.	Bet on an odd or even (payout is 2 times the bet)\n");
	printf("\t\t3.	Bet on a dozen ~ first 1-12, second, 13-24, third 25-36 (payout is 3 times the bet)\n");
	printf("The number zero does not count for odd or even or dozen, but can count as a number bet\n\n");
}

void makeBet(int *betType, int *bet)
{
	*betType = 0;
	*bet = -1;
	
	while(*betType != 1 && *betType != 2 && *betType != 3 )	{
	
		printf("What type of bet would you like to place?\n");
		printf("1= Bet on a number\n");
		printf("2= Bet on an odd or even\n");
		printf("3= Bet on a dozen\n");
		printf("Please Pick a number (1-3): ");	
		scanf("%d", betType);		
	}
	
	if(*betType == 1){
		
		while(*bet < 0 || *bet > 36){
			printf("What number do you bet on?\n");
			printf("Please enter the number you bet on (0-36): ");
			scanf("%d", bet);	
		}
		
	} else if(*betType == 2){
		
		while(*bet != 1 && *bet != 2){
			printf("What parity do you bet on?\n");
			printf("1= Odd \n");
			printf("2= Even \n");
			scanf("%d", bet);
		}
		
	} else if(*betType == 3){
		
		while(*bet != 1 && *bet!= 2 && *bet != 3 ){
			printf("Which dozen do you bet on?");
			printf("1= First dozen (1-12)");
			printf("2= Second dozen (13-24)");
			printf("3= Third dozen (25-36)");
			scanf("%d", bet);
		}
	}
}

float getBetAmount()
{
	float betAmount=0.0;

	while(betAmount <= 0){
		printf("How much would you like to bet? $");
		scanf("%f", &betAmount);
	}
	
	return betAmount;
}

int spinWheel()
{
	srand(time(0));
	return rand() % 37;
}

float figureWinnings(int *betType, int *bet, float betAmount, int actualOutcome){
	float result = 0.0;
	
	if(*betType == 1){
		if(*bet == actualOutcome){
			result = 36.0 * betAmount;
		}	
		else{
			result = -1.0 * betAmount;
		}
	} else if(*betType == 2){
		if((*bet == 1 && actualOutcome%2 == 1)
		|| (*bet == 2 && actualOutcome%2 == 0 && actualOutcome != 0)){
			result = 2.0 * betAmount;
		} else {
			result = -1.0 * betAmount;
		}
	} else if(*betType == 3){
		if((*bet == 1 && actualOutcome>=1 &&  actualOutcome<=12)
		|| (*bet == 2 && actualOutcome>=13 &&  actualOutcome<=24)
		|| (*bet == 3 && actualOutcome>=25 &&  actualOutcome<=36)){
			result = 3 * betAmount;
		} else {
			result = -1.0 * betAmount;
		}
	}
	
	return result;
}


