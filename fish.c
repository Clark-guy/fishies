// Fish ASCII animation in C 
//
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define ASCII_ESC 27
#define SCREEN_WIDTH 20
#define SCREEN_HEIGHT 10
#define SLEEP_TIME 100000

//for the life of me, I can't recall why I made the directions chars. Seems really stupid now if you ask me
typedef struct{
	int xLoc;
	int yLoc;
	char xDir;
	char yDir;
} fish;


int updateScreen(fish *fishy){
    int skipTwo = 0;
	//print all the shit
    for(int y=0;y<SCREEN_HEIGHT;y++){
		printf("\n");
		fflush(stdout);
		usleep(10);
		for(int x=0;x<SCREEN_WIDTH;x++){
			if(fishy->xLoc==x && fishy->yLoc==y){
                skipTwo = 2;
                if(fishy->xDir == 'l')
                    printf("<><");
                else
                    printf("><>");
            }
            else if(skipTwo > 0){
                skipTwo--;
            }
            else{
                if(y==0) 
                    printf("_");
                else if(x==0 || x==SCREEN_WIDTH-1 || y==SCREEN_HEIGHT-1)
                    printf("|");
                else
                    printf(" "); //better way to do this - add to a char[] and then print that? use put maybe?
                fflush(stdout);
            }
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
    //turning fish around
	if(fishy->xLoc>=xSize-4){
		fishy->xDir = 'l';
	}
	else if(fishy->xLoc<=1){
		fishy->xDir = 'r';
	}
    if(fishy->yLoc>=ySize-2){
        fishy->yDir = 'u';
    }
    else if(fishy->yLoc<=1){
        fishy->yDir = 'd';
    }
    //moving fish forward
	if(fishy->yDir=='u')
		fishy->yLoc--;
	else
		fishy->yLoc++;
	if(fishy->xDir=='l')
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
