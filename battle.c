
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include "battle.h"
#include <stdlib.h>
void ocean() {
    printf(" %c%c%c ", 176, 176, 176);
}

void ship() {
    printf(" |%c| ", 219);
}

void hit() {
    printf(" %c%c%c ", 176, 254, 176);
}
void direct_hit() {
    printf(" %c%c%c ", 176, 4, 176);
}
void clear() {
    while (getchar() != '\n');
}

void welcome(size map) {
    printf("\n"
           "    ____        __  __  __          __    _                                   \n"
           "   / __ )____ _/ /_/ /_/ /__  _____/ /_  (_)___     ____ _____ _____ ___  ___ \n"
           "  / __  / __ `/ __/ __/ / _ \\/ ___/ __ \\/ / __ \\   / __ `/ __ `/ __ `__ \\/ _ \\\n"
           " / /_/ / /_/ / /_/ /_/ /  __(__  ) / / / / /_/ /  / /_/ / /_/ / / / / / /  __/\n"
           "/_____/\\__,_/\\__/\\__/_/\\___/____/_/ /_/_/ .___/   \\__, /\\__,_/_/ /_/ /_/\\___/ \n"
           "                                       /_/       /____/                       ");
    printf("\n\n");
    printf("\n"
           "  _____            _                      _ \n"
           " |  __ \\          (_)                    | |\n"
           " | |  | | ___  ___ _  __ _ _ __   ___  __| |\n"
           " | |  | |/ _ \\/ __| |/ _` | '_ \\ / _ \\/ _` |\n"
           " | |__| |  __/\\__ \\ | (_| | | | |  __/ (_| |\n"
           " |_____/ \\___||___/_|\\__, |_| |_|\\___|\\__,_|\n"
           "                      __/ |                 \n"
           "                     |___/                  ");
    printf("\n\n");
    printf("\n"
           "  _           \n"
           " | |          \n"
           " | |__  _   _ \n"
           " | '_ \\| | | |\n"
           " | |_) | |_| |\n"
           " |_.__/ \\__, |\n"
           "         __/ |\n"
           "        |___/ ");

    printf("\n"
           "  _  __                                \n"
           " | |/ /                                \n"
           " | ' / __ _ _   _ ___  __ _  __ _ _ __ \n"
           " |  < / _` | | | / __|/ _` |/ _` | '__|\n"
           " | . \\ (_| | |_| \\__ \\ (_| | (_| | |   \n"
           " |_|\\_\\__,_|\\__, |___/\\__,_|\\__,_|_|   \n"
           "             __/ |                     \n"
           "            |___/                      ");
    printf("\n");
    getch();
    printf("Rules of game\n");
    printf("1. Player 1 place ships on board according to  rules\n");
    printf("2. Player 2 objective is shooting ships on borad. He can only give coordinates from 1 to 10 like '1 10'"
           "The map looks like:\n");
    fog_of_war(map);
    printf("\n3. Whoever possesses most points wins\nYou only got 10 shots to use. "
           "If you hit ship your shot won't be used");

    printf("\nHave a good game and also remember to report bugs. It's nice to help people\n");

}

void game_placement_phase(size map) {
    int battleship_lenght = 5;
    int cruiser_lenght = 4;
    int destroyer1_lenght = 3;
    int corvette_lenght = 2;
    printf("It's time to place battleship\n");
   ship_placement_phase(map, battleship_lenght);
    player_view_map(map);
    printf("It's time to place cruiser\n");
    ship_placement_phase(map, cruiser_lenght);
    player_view_map(map);
    printf("It's time to place destroyer\n");
    ship_placement_phase(map, destroyer1_lenght);
    player_view_map(map);
    printf("It's time to place corvette  \n");
    ship_placement_phase(map, corvette_lenght);
    player_view_map(map);

}

void player_view_map(size map) {
    printf("  ");
    for (int board_index = 1; board_index <= 10; board_index++) {
        printf("  %d  ", board_index);
    }
    printf("\n");
    for (int i = 0; i < POLE; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < POLE; j++) {
            if (map[i][j] == 0) {
                ocean();
            } else {
                ship();
            }
        }
        printf("\n");
    }
}

void fog_of_war(size map) {
    printf("  ");
    for (int board_index = 1; board_index <= 10; board_index++) {
        printf("  %d  ", board_index);
    }
    printf("\n");
    for (int i = 0; i < POLE; i++) {
        printf("%2d", i + 1);
        for (int j = 0; j < POLE; j++) {
            if (map[i][j] != 1&& map[i][j]!=9) {
                ocean();
            }
            else if (map[i][j]==9) {
                direct_hit();
            }
            else{
                hit();
            }
        }
        printf("\n");
    }
}

int ship_placement_option() {
    int result = 0;
    printf("Do you want to place ship upright(1) or horizontally(2)");
    if (scanf("%d", &result) != 1) {
        printf("Incorrect data please input data again \n ");
        clear();
        return 0;
    }
    if (result != 1 && result != 2) {
        printf("Incorrect data please input data again\n ");
        return 0;
    }
    return result;
}

int ship_placement_phase(size map, int ship_class) {
    int option;
    int correct = 0;
    int ship_size =ship_class ;
    int placement;
    while (correct == 0) {
        int check_x=0;
        int check_y=0;
        correct = 1;
        option =ship_placement_option();
        if (option == 1) {
            printf("Insert collumne number from 1 to 10   ");
            if((scanf("%d", &check_y)!=1|| check_y<1||check_y>10)){
                printf("You have chosen.... poorly");
                exit(1);
            }
            clear();
            printf("Insert line from which ship can be placed you can choose max from line  %d \n", 11-ship_class);
            if((scanf("%d", &check_x)!=1|| check_x<1||check_x>10)){
                printf("You have chosen.... poorly");
                exit(1);
            }
            clear();
            for (int s_size = ship_size; s_size > 0; s_size--) {
                if (map[check_x - 1][check_y - 1] != 0) {
                    printf("blad\n");
                    correct = 0;
                    break;
                } else {
                    map[check_x - 1][check_y - 1] = ship;
                    check_x++;
                }
            }
        }
        if (option == 2) {
            printf("Insert line \n");
            if((scanf("%d", &check_x)!=1|| check_x<1||check_x>10)){
                printf("You have chosen.... poorly");
                exit(1);
            }
            clear();
            printf("Insert collumne from which ship can be placed you can choose max from line  %d \n", 11 - ship_class);
            if((scanf("%d", &check_y)!=1|| check_y<1||check_y>10)){
                printf("You have chosen.... poorly");
                exit(1);
            }
            for (int s_size = ship_size; s_size > 0; s_size--) {
                if (map[check_x - 1][check_y - 1] != 0) {
                    printf("Error\n");
                    correct = 0;
                    break;
                } else {
                    map[check_x - 1][check_y - 1] = ship;
                    check_y++;
                }
            }
        }
        if (option != 1 && option != 2) {
            correct = 0;
        }
    }
    return 1;
}

int game_shooting_phase(size map) {
    int firepower, fire_crd_x, fire_crd_y;
    int battleship_hp = 5;
    int cruiser_hp = 4;
    int destroyer_1_hp = 3;
    int corvette_hp = 2;
    int score = 0;
    int cor_sunk = 1;
    int des_sunk = 1;
    int cru_sunk = 1;
    int bship_sunk = 1;
    for (firepower = 10; firepower > 0; firepower--) {
        int dumb = 0;
        printf("Give coordinates x(collumne) and y(line) from  0 to 10 \n");
        if (scanf("%d %d", &fire_crd_x, &fire_crd_y) != 2 || fire_crd_x > 10 || fire_crd_x < 1 || fire_crd_y > 10 ||
            fire_crd_y < 0) {
            printf("It's not nice to troll author. Your shot missed \n");
            firepower--;
            dumb = 1;
        }
        clear();
        if (map[fire_crd_x - 1][fire_crd_y - 1] == 1 && dumb == 0) {
            printf("..... You already shot here\n");
            fog_of_war(map);
        }
        if (map[fire_crd_x - 1][fire_crd_y - 1] == 0 && dumb == 0) {
            printf("You missed \n");
            map[fire_crd_x - 1][fire_crd_y - 1] = 1;
            fog_of_war(map);
        }
        if (map[fire_crd_x - 1][fire_crd_y - 1] == 2 && dumb == 0) {
            printf("Hit\n");
            map[fire_crd_x - 1][fire_crd_y - 1] = 9;
            fog_of_war(map);
            corvette_hp--;
            firepower++;
        }
        if (map[fire_crd_x - 1][fire_crd_y - 1] == 3 && dumb == 0) {
            printf("Hit\n");
            map[fire_crd_x - 1][fire_crd_y - 1] = 9;
            fog_of_war(map);
            destroyer_1_hp--;
            firepower++;
        }
        if (map[fire_crd_x - 1][fire_crd_y - 1] == 4 && dumb == 0) {
            printf("Hit\n");
            map[fire_crd_x - 1][fire_crd_y - 1] = 9;
            fog_of_war(map);
            cruiser_hp--;
            firepower++;
        }
        if (map[fire_crd_x - 1][fire_crd_y - 1] == 5 && dumb == 0) {
            printf("Hit\n");
            map[fire_crd_x - 1][fire_crd_y - 1] = 9;
            fog_of_war(map);
            battleship_hp--;
            firepower++;
        }
        if (corvette_hp == 0 && dumb == 0 && cor_sunk == 1) {
            printf("Corvette sunk +3 points\n");
            score += 3;
            cor_sunk = 0;
        }
        if (destroyer_1_hp == 0 && dumb == 0 && des_sunk == 1) {
            printf("Destroyer got destroyed +4 points\n");
            score += 4;
            des_sunk = 0;
        }
        if (cruiser_hp == 0 && dumb == 0 && cru_sunk == 1) {
            printf("Cruiser sinked  +6 points\n");
            score += 6;
            cru_sunk = 0;
        }
        if (battleship_hp == 0 && dumb == 0 && bship_sunk == 1) {
            printf("O sh....flag ship destroyed +8 points\n ");
            bship_sunk = 0;
            score += 8;
        }
        if (battleship_hp == 0 && cruiser_hp == 0 && destroyer_1_hp == 0 && corvette_hp == 0) {
            printf("Congratulations you have sunked entire strike fleet\n");
            break;
        }
    }
    return score + firepower;
}