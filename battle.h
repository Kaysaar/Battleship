//
// Created by wikto on 27.04.2022.
//

#ifndef BATTLESHIP_BATTLE_H
#define BATTLESHIP_BATTLE_H
#define POLE 10
typedef int size[POLE][POLE];
void clear();
void player_view_map();
void ocean();
void ship();
void direct_hit();
void welcome(size);// just simple Welcome :3
void game_placement_phase(size);// Placement phase for player 1.
int ship_placement_phase(size, int);
int ship_placement_option();
void fog_of_war(size);
int game_shooting_phase(size);

#endif //BATTLESHIP_BATTLE_H
