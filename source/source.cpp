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
	int threshold_variable;						// Threshold Variable that can be adjusted.

	cvtColor(frame, gray_frame, CV_BGR2GRAY);	// Converts image to grayscale
	
	int i;
	for(i=0; i<255; i=+10) {

		threshold(gray_frame, thres_frame, i, 255, 0);	// Creates threshold on image

		// Creates Filename
		stringstream sstm;
		string filename = "/home/pi/media/savefile";
		string suffix = ".jpg"
		sstm << filename << i << suffix;
		// Write Frame
		imwrite(sstm.str(), thres_frame;
	}
	
}