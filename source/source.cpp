#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main()
{
	// Initialize the Camera Stream with Camera PID 0
	VideoCapture noir(0) 

	// Error Catching
	if(!noir.isOpened())
	{
		cout << "Camera failed to initalize";
		return -1;
	}

	// Read Frame
	Mat frame;
	noir.read(frame);

	// Image Processing
	Mat gray_frame, thres_frame; 				// Creates two Mat variables to store transformations
	int threshold_variable = 150;				// Threshold Variable that can be adjusted.
	
	cvtColor(frame, gray_frame, CV_BGR2GRAY);	// Converts image to grayscale
	threshold(gray_frame, thres_frame, threshold_variable, 255, 0);	// Creates threshold on image

	// Write Frame
	imwrite("/home/pi/media/savefile.jpg")
}