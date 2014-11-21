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
}