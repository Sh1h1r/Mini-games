#include <stdio.h>
#define ROWS 3
/* 
	1 2 3
	4 5 6
	7 8 9
diagonal = 0,0  1,1 2,2
	
*/
 
// two player 

typedef struct{
	char choice;
	char sign;
}player;

int check_winner(char arr[ROWS][ROWS], player player1,player player2){
	for (int i = 0; i < ROWS; i++) {
	        if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2]) {
	            if (arr[i][0] == player1.sign) return 1;
	            if (arr[i][0] == player2.sign) return 2;
	        }
	    }
	    for (int i = 0; i < ROWS; i++) {
	        if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i]) {
	            if (arr[0][i] == player1.sign) return 1;
	            if (arr[0][i] == player2.sign) return 2;
	        }
	    }
	    if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]) {
	        if (arr[0][0] == player1.sign) return 1;
	        if (arr[0][0] == player2.sign) return 2;
	    }
	    if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) {
	        if (arr[0][2] == player1.sign) return 1;
	        if (arr[0][2] == player2.sign) return 2;
	    }
	return -1;
}

int main(){
	player player1,player2;
	player1.sign = 'X';
	player2.sign = 'O';
	char arr[ROWS][ROWS] = {
	
			{ '1' , '2' , '3' },		
			{ '4' , '5' , '6' },
			{ '7' , '8' , '9' }
			
					};
	printf("\n");
	while(1){
		for(int row = 0; row < ROWS; row++){
			for(int col = 0; col < ROWS; col++){
				
				printf(" ");
				printf("%c",arr[row][col]);
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
		printf("choice for player 1:");
		scanf(" %c",&player1.choice);
		for(int row = 0; row < ROWS; row++){
			for(int col = 0; col < ROWS; col++){
				if(arr[row][col] == player1.choice){
					arr[row][col] = player1.sign;
				}
				printf(" ");
				printf("%c",arr[row][col]);
				printf(" ");
			}
			printf("\n");
		}
		int result = check_winner(arr, player1, player2);
		if(result == 1) {
            printf("Player 1 wins!\n");
            break;
		}
		printf("\n");
		printf("choice for player 2:");
		scanf(" %c",&player2.choice);
		for(int row = 0; row < ROWS; row++){
			for(int col = 0; col < ROWS; col++){
				if(arr[row][col] == player2.choice){
					arr[row][col] = player2.sign;
				}
				printf(" ");
				printf("%c",arr[row][col]);
				printf(" ");
			}
			printf("\n");
		}
		printf("\n");
		int assign = check_winner(arr, player1, player2);
		if(assign == 2) {
           printf("Player 2 wins!\n");
           break;
        }
	}
}


