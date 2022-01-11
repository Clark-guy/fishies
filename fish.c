// Animation in C 
//
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define ASCII_ESC 27
#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 10
#define SLEEP_TIME 300000

typedef struct{
	int xLoc;
	int yLoc;
	char dir;
} fish;


int updateScreen(fish *fishy){
	//print all the shit
    for(int y=0;y<SCREEN_HEIGHT;y++){
		printf("\n");
		fflush(stdout);
		usleep(10);
		for(int x=0;x<SCREEN_WIDTH;x++){
			if(fishy->xLoc==x && fishy->yLoc==y)
				printf(" ");
			else
				printf("o"); //better way to do this - add to a char[] and then print that? use put maybe?
			fflush(stdout);
		}
	}
	
    usleep(SLEEP_TIME);
	printf("\n");
	fflush(stdout);
	for(int x=0;x<400;x++){
		printf("%c[2J", ASCII_ESC);
		fflush(stdout);
	}
	return 0;
}

int updateFish(fish *fishy, int xSize, int ySize){
	if(fishy->xLoc>=xSize-1){
		fishy->dir = 'l';
	}
	else if(fishy->xLoc<=0){
		fishy->dir = 'r';
	}
	if(fishy->dir=='l')
		fishy->xLoc--;
	else
		fishy->xLoc++;
	return 0;
}

void printDebug(fish *fishy){
    printf("x loc: %d\n", fishy->xLoc);
    printf("y loc: %d\n", fishy->yLoc);
}

int main(){
	int rc;
	fish *fishy = (fish*)malloc(sizeof(fish));

	for(;;){
        printDebug(fishy);
		rc = updateScreen(fishy);
		rc = updateFish(fishy, SCREEN_WIDTH, SCREEN_HEIGHT);
	}
	return 0;
}
