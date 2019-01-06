/**
 * @fileMidiPlayer.h
 * @date2018/12/10
 * @authoryazilimperver
 * @brief The midi playing code copied from http://blog.fourthwoods.com/2012/02/24/playing-midi-files-in-windows-part-5/
 *
 * Copyright © 2018, Check Bottom For Copyright Notice <yazilimpervergs@gmail.com>
 */
#ifndef MIDIPLAYER_H__
#define MIDIPLAYER_H__

#include <string>
#include <memory>
#include <thread>
#include <condition_variable>
#include <atomic>

/// The player thread wait for next play request where it will play the music with given parameters
class MidiPlayer
{
public:
	// Initialize this class
	void initialize();

	// Stop all threads
	void finalize();

	// Enqueue a music play command
	bool playMusic(const std::string& fileName, bool isContinuous = true);

	// Stop currently active music if any
	void stopMusic();
protected:
	void playWin32Music(const char* fileName);
	void playMusicThreadFunc();

	// Is application active
	bool mIsAppActive{ true };

	// Is music still playing
	std::atomic<bool> mIsMusicPlayActive{ false };

	// Is stop command initiated
	std::atomic<bool> mIsStopInitiated{ false };

	// Is continuous play initiated
	bool mIsContinousPlayActive{ true };

	// Last music play count
	int mPlayCount{ 0 };

	// Currently active music to be played
	std::string mMusicFile;

	// Currently active thread
	std::unique_ptr<std::thread> mMusicPlayThread;

	// Condition variable to trigger thread
	std::condition_variable mPlayTriggerCondVariabl;

	// Mutex for condition variable
	std::mutex mMutex;
};

#endif // MIDIPLAYER_H__

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
