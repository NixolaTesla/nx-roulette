#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

int chamber;
int turn;
int bullet;
int alive1 = 1;
int alive2 = 1;
int choice1;
int choice2;
char buffer[256];

// play orange roulette!

int main(){

	// seed with the time
	srand(time(NULL));

	turn = rand() % 2; 
	bullet = (rand() % 6) + 1;
	chamber = (rand() % 6) + 1;

	printf("\n\nWELCOME TO NX ROULETTE\n\n");

	while(1){

	  if(turn == 0){
	
	   printf("1. Shoot Yourself\n");
	   printf("2. Shoot Other\n");
           printf("Choice: ");
	   scanf("%d", &choice1);

	   if(choice1 == 1){
		if(chamber == bullet){
			FILE *death = fopen("death.txt", "r");
			if(death != NULL){
				while(fgets(buffer, sizeof(buffer), death)){
					printf("%s", buffer);
				}
			}
			printf("\nYOU DIED.\n\n");
			exit(0);
		}

		else if(chamber != bullet){
			turn = 1;
			chamber++;
			if(chamber > 6){
				chamber = 1;
			}
			printf("The revolver clicks. Nothing happened. The game goes on...\n\n");
		}	
	   }

	   else if(choice1 == 2){
		if(chamber == bullet){
			FILE *victory = fopen("victory.txt", "r");
			if(victory != NULL){
				while(fgets(buffer, sizeof(buffer), victory)){
					printf("%s", buffer);
				}
			}
			printf("\nBANG!! The gun rings out, and now your opponent lays in front of you, lifeless. But you won!\n\n");
			exit(0);
		}

		else if(chamber != bullet){
			turn = 1;
			chamber++;
			if(chamber > 6){
				chamber = 1;
			}
			printf("The revolver clicks. Now suffer the potential consequences. (You proceed to point it at yourself)\n");
			printf("You raise the revolver and point it at your head...\n\n");
			sleep(3);
			if(chamber == bullet){
				FILE *deathh = fopen("death.txt", "r");
				if(deathh != NULL){
					while(fgets(buffer, sizeof(buffer), deathh)){
						printf("%s", buffer);
					}
				}
				printf("\n\nYOU DIED.\n\n");
				exit(0);
			}

			else if(chamber != bullet){
				chamber++;
				if(chamber > 6){
					chamber = 1;
				}

				printf("The revolver clicks yet again. You are safe.. for now..\n\n");
			}
		}
	 }

	   else{
		printf("NOT A VALID CHOICE!!! BOOM YOU'RE DEAD!!!!!");
		// 67
		exit(0);
	   }

       }


	  else if(turn == 1){

		printf("Opponent is thinking... and fearing for their life...\n\n");
		sleep(4);

		choice2 = (rand() % 2) + 1;

		printf("Opponent chose: %d\n\n", choice2);
		
		if(choice2 == 1){

			printf("Your opponent fearfully puts the gun to their head...\n\n");
			sleep(4);

			 if(chamber == bullet){
			FILE *vic = fopen("victory.txt", "r");
			if(vic != NULL){
				while(fgets(buffer, sizeof(buffer), vic)){
					printf("%s", buffer);
				}
			}
			printf("\nBANG! Your opponent is gone, you win!\n\n");
			exit(0);
		}

		   else if(chamber != bullet){
			turn = 0;
			chamber++;
			if(chamber > 6){
				chamber = 1;
			}
			printf("The revolver clicks. Nothing happened. The game goes on...\n\n");
		}	

		}

		else if(choice2 == 2){

		 	if(chamber == bullet){
			FILE *deth = fopen("death.txt", "r");
			if(deth != NULL){
				while(fgets(buffer, sizeof(buffer), deth)){
					printf("%s", buffer);
				}
			}
			printf("\nYOU DIED. Your opponent lives to see another day.\n\n");
			exit(0);
		}

		else if(chamber != bullet){
			turn = 0;
			chamber++;
			if(chamber > 6){
				chamber = 1;
			}
			printf("The revolver clicks. Your opponent's luck wasn't as good as they anticipated, and so now they must suffer the potential consequences.\n");
			printf("They raise the revolver and point it at their head...\n\n");
			sleep(3);
			if(chamber == bullet){
				FILE *vicc = fopen("victory.txt", "r");
				if(vicc != NULL){
					while(fgets(buffer, sizeof(buffer), vicc)){
						printf("%s", buffer);
					}
				}
				printf("\n\nBANG! Your opponent lays there lifeless. You win!\n\n");
				exit(0);
			}

			else if(chamber != bullet){
				chamber++;
				if(chamber > 6){
					chamber = 1;
				}

				printf("The revolver clicks yet again. They are safe.. for now..\n\n");
			}
		  }
		}
	  }

	}

	return 0;

}
