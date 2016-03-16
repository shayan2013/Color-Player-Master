#include "Sound.h"


Sound::Sound (int number, int tone)

{
	setNumber(number);
	setTone(tone);
		if (number == 1) {
		switch (tone) {
		case(0) :
			PlaySound(TEXT("Sounds/horse1a.wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("Sounds/hen2.wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("Sounds/crow1a.wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("Sounds/lamb.wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}


	}
	else if (number == 2) {
		switch (tone) {
		case(0) :
			PlaySound(TEXT("Sounds\g (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("Sounds\g (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("Sounds\g (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("Sounds\g (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}


	}
	else if (number == 3) {
		switch (tone) {
		case(0) :
			PlaySound(TEXT("Sounds\gb (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("Sounds\gb (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("Sounds\gb (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("Sounds\gb (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}


	}
	else if (number == 4) {
		switch (tone) {
		case(0) :
			PlaySound(TEXT("Sounds\r (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("Sounds\r (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("Sounds\r (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("Sounds\r (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}
	}
	else if (number == 5) {
		switch (tone) {
		case(0) :
			PlaySound(TEXT("Sounds\h (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("Sounds\h (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("Sounds\h (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("Sounds\h (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}


	}
	else if (number == 6) {
		switch (tone) {
		case(0) :
			PlaySound(TEXT("Sounds\ich (1).wav"), NULL, SND_SYNC);
			break;
		case(1) :
			PlaySound(TEXT("Sounds\ich (2).wav"), NULL, SND_SYNC);
			break;
		case(2) :
			PlaySound(TEXT("Sounds\ich (3).wav"), NULL, SND_SYNC);
			break;
		case(3) :
			PlaySound(TEXT("Sounds\ich (4).wav"), NULL, SND_SYNC);
			break;
		default:
			break;
		}
	}

}





int Sound::getNumber(){
	return Sound::number;
}

int Sound::getTone(){
	return Sound::tone;
}


void Sound::setNumber(int number){
	Sound::number=number;
}

void Sound::setTone(int tone){
	Sound::tone=tone;
}
