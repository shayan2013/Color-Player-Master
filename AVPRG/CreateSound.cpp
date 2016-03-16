#include "CreateSound.h"

CreateSound::CreateSound(int freq, int delay) {

	setFreq(freq);
	setDelay(delay);

	Beep(getFreq(), getDelay());

}

int CreateSound::getFreq() {
	return CreateSound::freq;
}

int CreateSound::getDelay() {
	return CreateSound::delay;
}

void CreateSound::setFreq(int freq) {
	CreateSound::freq = freq;
}

void CreateSound::setDelay(int delay) {
	CreateSound::delay = delay;
}