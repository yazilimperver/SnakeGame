#include <Player.h>

Player::Player(const PlayerData& playerData) 
	: mPlayerData{ playerData }
{

}

PlayerData& Player::GetPlayerData()
{
	return mPlayerData;
}
