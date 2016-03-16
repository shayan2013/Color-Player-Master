#include "Color.h"

Color::Color(string name){
	
	//set Colorrange for Red
	if(name =="red"){
		setHSVmin(Scalar(131, 113, 40));
		setHSVmax(Scalar(190, 255, 255));
	}
	
	//set Colorrange for Blue
	if(name =="blue"){
		setHSVmin(Scalar(87, 116, 0));
		setHSVmax(Scalar(145, 255, 255));
	}

	//set Colorrange for Green
	if(name =="green"){
		setHSVmin(Scalar(38, 88, 0));
		setHSVmax(Scalar(97, 198, 255));
	}

	//set Colorrange for Yellow
	if(name =="yellow"){
		setHSVmin(Scalar(0, 43, 255));
		setHSVmax(Scalar(37, 165, 255));
	}
	
}

Scalar Color::getHSVmin(){
	return Color::HSVmin;
}

Scalar Color::getHSVmax(){
	return Color::HSVmax;
}

void Color::setHSVmin(Scalar min){
	Color::HSVmin = min;
}

void Color::setHSVmax(Scalar max){
	Color::HSVmax = max;
}