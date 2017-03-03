#ifndef INTERACTION_H
#define INTERACTION_H

float distance(player rider, ball freedom);
bool check_contact(player &rider, ball &freedom);
bool check_contact_LT(ball & freedom);
bool check_contact_RT(ball & freedom);
bool check_contact_LB(ball & freedom);
bool check_contact_RB(ball & freedom);
//void move_system(player &rider, ball &freedom);
//void check_contact_ball(player &rider, ball &freedom);
void hit_ball(player &rider, ball &freedom);
bool check_contact_player(player & rider, player & enemy);

#endif