/**
 * \file    PlayerData.h
 * \date    2018/10/29
 * \author  yazilimperver
 * \brief   
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef PLAYERDATA_H__
#define PLAYERDATA_H__

#include <string>
#include <Color.h>

struct PlayerData
{
	/// Name of player
	std::string mName = "Player_01";

	/// Player unique id
	int32_t mPlayerId = 1;

	/// Color
	Color mPlayerColor = Color::eColor_red;

	/// Score
	int32_t mScore = 0;

	/// Alive status
	bool mIsAlive = true;

	/// TODO: NETWORK DATA (IP, CONNECTION STATUS, LAST RECEIVE DATA)
};

#endif // PLAYERDATA_H__

/*
  Copyright (c) [2018] [Yazilimperver <yazilimpervergs@gmail.com>]
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/
