#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include "battle.h"

int main() {

    size map = {{0}};
    int score_player1;
    int score_player2;
    welcome(map);
    getch();
    game_placement_phase(map);
    printf("Placement phase completed . Setting fog of war...\n");
    sleep(5);
    system("cls");
    score_player1 = game_shooting_phase(map);
    printf("\n Your score is  %d\nPress Enter\n", score_player1);
    getch();
    printf("It's time to switch sides. Player 2\n ");
    for(int zero_x=0;zero_x<POLE;zero_x++){
        for(int zero_y=0;zero_y<POLE;zero_y++){
            map[zero_x][zero_y]=0;
        }
    }
    game_placement_phase(map);
    printf("Placement phase completed . Setting fog of war...\n");
    sleep(5);
    system("cls");

    score_player2 = game_shooting_phase(map);
    printf("\n Your score is  %d\nPress Enter", score_player2);
    getch();
    if(score_player1>score_player2){
        printf("Player 1 wins");
    }
    else if(score_player2>score_player1){
        printf("Player 2 wins");
    }
    else{
        printf("Tie");
    }
    getch();
    return 0;
}



