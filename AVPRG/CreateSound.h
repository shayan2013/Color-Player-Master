#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <Windows.h>
#include <MMSystem.h>

using namespace cv;
using namespace std;

class CreateSound
{

public:
	CreateSound(int freq, int delay);

	int getFreq();
	int getDelay();

	void setFreq(int freq);
	void setDelay(int delay);

private:
	int freq;
	int delay;
};
