#include "player.h"

Player::Player(const char *name){

}

Player::~Player(){
	delete _name;
}

void Player::getName(char *str){
	strcpy(_name, str);
}
