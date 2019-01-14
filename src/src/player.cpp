#include "player.h"

Player::Player(){
}

Player::~Player(){
}

void Player::setName(const char *name){
	strcpy(_name, name);
}

void Player::getName(char *str){
	strcpy(str, _name);
}
