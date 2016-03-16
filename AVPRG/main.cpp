#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <Windows.h>
#include <MMSystem.h>
#include "Color.h"
#include "Sound.h"
#include "CreateSound.h"


using namespace cv;
using namespace std;

//names that will appear at the top of each window
const string Yellow = "Thresholded ImageYellow";
const string Green = "Thresholded ImageGreen";
const string Blue = "Thresholded ImageBlue";
const string Red = "Thresholded ImageRed";
const string Camera = "Original";

//Frequenz and Delay
int fR, dR, fB, dB, fG, dG, fY, dY;
//Tone and Octave
int tR, oR, tB, oB, tG, oG, tY, oY;
//Sample
int number = 0;
int sampleNumber;
//naming the colors
Color red("red"), blue("blue"), green("green"), yellow("yellow");

string freqMsg = "die Frequenz muss zwieschen 131 und 988 sein:";
string delayMsg = "die Delay muss zwieschen 100 und 2000 sein (Milisekunde) : ";
string delayMsg2 = "ganzer Ton = 1, halber Ton = 2, viertel Ton = 3, achtel Ton = 4, sechzentel Tone = 5 (nur Zahlen eingeben!)";
string tonMsg = "c=1 , c#=2 , d=3 , d#=4 , e=5 , f=6 , f#=7 , g=8 , g#=9 , a=10 , a#=11 , b=12 (nur Zahlen eingeben!)";
string octMsg = "Octave 1 = 1 , Octave 2 = 2 , Octave 3 = 3 (nur Zahlen eingeben!)";

//Test input from user
int inputTest(string msg, int number, int cond1, int cond2) {
	string input = "";
	do {
		cout << msg << endl;
		getline(cin, input);
		stringstream myStream(input);
		myStream >> number;
	} while ((number < cond1) || (number > cond2));
	return number;
}



//make Delay
int delayMaker(int delay) {
	int del;
	switch (delay) {
	case(1) :
		del = 3200;
		break;
	case(2) :
		del = 1600;
		break;
	case(3) :
		del = 800;
		break;
	case(4) :
		del = 400;
		break;
	case(5) :
		del = 200;
		break;
	default:
		break;
	}
	return del;
}
//Remove Noise from Image
void removeAndFill (Mat &thresh) {
		//remove small objects from the foreground
		erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		dilate(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));

		//fill small holes in the foreground
		dilate(thresh,thresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
		erode(thresh, thresh, getStructuringElement(MORPH_ELLIPSE, Size(5, 5)));
}

void msgCompile(string var, int num) {
	switch (num) {
	case(0) :
		cout << "gib die Frequenz der " + var + " Farbe an :" << endl;
		break;
	case(1) :
		cout << "gib die Delay der " + var + " Farbe an :" << endl;
		break;
	case(2) :
		cout << "gib den Ton der " + var + " Farbe an :" << endl;
		break;
	case(3) :
		cout << "gib die Octave der " + var + " Farbe an :" << endl;
		break;
	default:
		break;
	}
}

//make frequenz with tone and octave
int freqMaker(int tone, int octave) {
	int freq;
	switch (tone) {
	case(1) :
		if (octave == 1)
			freq = 131;
		else if (octave == 2)
			freq = 262;
		else if (octave == 3)
			freq = 523;
		break;
	case(2) :
		if (octave == 1)
			freq = 139;
		else if (octave == 2)
			freq = 277;
		else if (octave == 3)
			freq = 554;
		break;
	case(3) :
		if (octave == 1)
			freq = 147;
		else if (octave == 2)
			freq = 294;
		else if (octave == 3)
			freq = 587;
		break;
	case(4) :
		if (octave == 1)
			freq = 156;
		else if (octave == 2)
			freq = 311;
		else if (octave == 3)
			freq = 622;
		break;
	case(5) :
		if (octave == 1)
			freq = 165;
		else if (octave == 2)
			freq = 330;
		else if (octave == 3)
			freq = 659;
		break;
	case(6) :
		if (octave == 1)
			freq = 175;
		else if (octave == 2)
			freq = 349;
		else if (octave == 3)
			freq = 698;
		break;
	case(7) :
		if (octave == 1)
			freq = 185;
		else if (octave == 2)
			freq = 370;
		else if (octave == 3)
			freq = 740;
		break;
	case(8) :
		if (octave == 1)
			freq = 196;
		else if (octave == 2)
			freq = 392;
		else if (octave == 3)
			freq = 784;
		break;
	case(9) :
		if (octave == 1)
			freq = 208;
		else if (octave == 2)
			freq = 415;
		else if (octave == 3)
			freq = 830;
		break;
	case(10) :
		if (octave == 1)
			freq = 220;
		else if (octave == 2)
			freq = 440;
		else if (octave == 3)
			freq = 880;
		break;
	case(11) :
		if (octave == 1)
			freq = 233;
		else if (octave == 2)
			freq = 466;
		else if (octave == 3)
			freq = 932;
		break;
	case(12) :
		if (octave == 1)
			freq = 247;
		else if (octave == 2)
			freq = 494;
		else if (octave == 3)
			freq = 988;
		break;
	default:
		break;
	}
	return freq;
}

void setToOcDel() {
	msgCompile("roten", 2);
	tR = inputTest(tonMsg, tR, 1, 12);
	msgCompile("roten", 3);
	oR = inputTest(octMsg, oR, 1, 3);
	fR = freqMaker(tR, oR);
	msgCompile("roten", 1);
	dR = delayMaker(inputTest(delayMsg2, dR, 1, 5));

	msgCompile("blauen", 2);
	tB = inputTest(tonMsg, tB, 1, 12);
	msgCompile("blauen", 3);
	oB = inputTest(octMsg, oB, 1, 3);
	fB = freqMaker(tB, oB);
	msgCompile("blauen", 1);
	dB = delayMaker(inputTest(delayMsg2, dB, 1, 5));

	msgCompile("gr\201nen", 2);
	tG = inputTest(tonMsg, tG, 1, 12);
	msgCompile("gr\201nen", 3);
	oG = inputTest(octMsg, oG, 1, 3);
	fG = freqMaker(tG, oG);
	msgCompile("gr\201nen", 1);
	dG = delayMaker(inputTest(delayMsg2, dG, 1, 5));

	msgCompile("gelben", 2);
	tY = inputTest(tonMsg, tY, 1, 12);
	msgCompile("gelben", 3);
	oY = inputTest(octMsg, oY, 1, 3);
	fY = freqMaker(tY, oY);
	msgCompile("gelben", 1);
	dY = delayMaker(inputTest(delayMsg2, dY, 1, 5));
}

//Set Frequenz and Delay
void setFreqDelay() {
	msgCompile("roten", 0);
	fR = inputTest(freqMsg, fR, 131, 988);
	msgCompile("roten", 1);
	dR = inputTest(delayMsg, dR, 100, 2000);

	msgCompile("blauen", 0);
	fB = inputTest(freqMsg, fB, 131, 988);
	msgCompile("blauen", 1);
	dB = inputTest(delayMsg, dB, 100, 2000);

	msgCompile("gr\201nen", 0);
	fG = inputTest(freqMsg, fG, 131, 988);
	msgCompile("gr\201nen", 1);
	dG = inputTest(delayMsg, dG, 100, 2000);

	msgCompile("gelben", 0);
	fY = inputTest(freqMsg, fY, 131, 988);
	msgCompile("gelben", 1);
	dY = inputTest(delayMsg, dY, 100, 2000);
}
	


double momentsArea (Mat threshold){
	Moments oMoments = moments(threshold);
	double dArea = oMoments.m00;
	return dArea;
}

void beginMsg() {
	cout << "W\204hle ein Soundthema aus!" << endl;
	cout << "Tiere = 1 | Gitarre = 2 | Gitarre2 = 3, R\201lpser = 4" << endl;
	cout << "Hupe = 5 | Funny = 6 | Your Sample = 7" << endl;
}

int main()
{

	beginMsg();

	number = inputTest("Bitte gib die Nummer des gew\204hlten Themas an:", number, 1, 7);

	if (number == 7) {
		cout << "[Ton, Octave, Delay] = 1       [Frequenz, Delay] = 2" << endl;
		sampleNumber = inputTest("1 oder 2 eingeben!", number, 1, 2);
		if (sampleNumber == 1) {
			setToOcDel();
		}
		else {
			setFreqDelay();
		}
		
	}

	//capture the video from web cam
	VideoCapture cap(0); 

	// if not success, exit program
	if (!cap.isOpened())  
	{
		cout << "Cannot open the web cam" << endl;
		return -1;
	}

	int x = 0;

	while (true)
	{
		Mat imgOriginal, imgHSV;
		Mat thresholdR, thresholdB, thresholdG, thresholdY;

		// read a new frame from video
		bool bSuccess = cap.read(imgOriginal); 

		//if not success, break loop
		if (!bSuccess) 
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		

		//**** Color Detection ***//


		//Convert the captured frame from BGR to HSV
		cvtColor(imgOriginal, imgHSV, COLOR_BGR2HSV);
		
		//Red Color
		inRange(imgHSV, red.getHSVmin(), red.getHSVmax(), thresholdR);
		removeAndFill(thresholdR);

		//Blue Color
		inRange(imgHSV, blue.getHSVmin(), blue.getHSVmax(), thresholdB);
		removeAndFill(thresholdB);

		//Green Color
		inRange(imgHSV, green.getHSVmin(), green.getHSVmax(), thresholdG);
		removeAndFill(thresholdG);
		
		//Yellow Color
		inRange(imgHSV, yellow.getHSVmin(), yellow.getHSVmax(), thresholdY);
		removeAndFill(thresholdY);

	


		// if the darea <= 10000, consider that there are no object in the image and it's because of the noise, the area is not zero 
		if (momentsArea(thresholdR) > 1000000)
		{
			if (number == 7) {
				CreateSound red(fR, dR);
			}
			else {
				Sound red(number, 0);
			}
			
			
		}
	

		if (momentsArea(thresholdB) > 1000000)
		{
			if (number == 7) {
				CreateSound blue(fB, dB);
			}
			else {
				Sound blue(number, 1);
			}
		}


		if (momentsArea(thresholdG) > 1000000)
		{
			if (number == 7) {
				CreateSound green(fG, dG);
			}
			else {
				Sound green(number, 2);
			}
		}


		if (momentsArea(thresholdY) > 1000000)
		{
			if (number == 7) {
				CreateSound yellow(fY, dY);
			}
			else {
				Sound yellow(number, 3);
			}
		}



		//Show Windows
		//imshow(Yellow, tresholdY); 
		//imshow(Green, thresholdG);
		//imshow(Blue, thresholdB);
		//imshow(Red, thresholdR); 
		imshow(Camera, imgOriginal); 

		//wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
		if (waitKey(30) == 27) 
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}


	}


	return 0;

}