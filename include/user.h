#ifndef USER_H
#define USER_H

#include <stdint.h>

typedef struct
{
    int id;
    char username[50];
    int xp_level;
    int achievements_count;
} User;

User* create_user (int id, char *username);

void display_user_info(const User *user);

#endif // USER_H