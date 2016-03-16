#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <Windows.h>
#include <MMSystem.h>

using namespace cv;
using namespace std;

class Color
{
public:
	//Color();
	Color(string name);
	
	Scalar getHSVmin();
	Scalar getHSVmax();
	
	
	void setHSVmin(Scalar min);
	void setHSVmax(Scalar max);
	
private:
	Scalar HSVmin, HSVmax;

};