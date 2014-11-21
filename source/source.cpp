#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main()
{
	vector<Vec3f> output_array;

	Mat frame;
	frame = imread("/home/pi/pupilDetect/sample.jpg")

	// Image Processing
	Mat gray_frame, thres_frame; 				// Creates two Mat variables to store transformations
	int threshold_variable = 60;				// Threshold Variable that can be adjusted.

	cvtColor(frame, gray_frame, CV_BGR2GRAY);	// Converts image to grayscale
	threshold(gray_frame, thres_frame, threshold_variable, 255, 0);

	// Analyses Image
	HoughCircles(thres_frame, output_array, CV_HOUGH_GRADIENT, 2, thres_frame.rows/4, 70, 65);

	// Draw Circle on result
	for(int i=0; i<output_array.size(); i=++) {

		// Defines the points and radius for the circle
		Point center(cvRound(output_array[i][0]),cvRound(output_array[i][1]));
		int radius = cvRound(output_array[i][2]);

		// Draws the Circles
		circle(gray_frame, center, 5, (255,0,255), -1, 8, 0); 		// Circle on Pupil
		circle(gray_frame, center, radius, (255,0,255), 3, 8, 0);	// Circle on Center
	}

	imwrite("/home/pi/camera/output.jpg", gray_frame);	// Writes Output

	return 0;
	
}