#include <iostream>
#include <cv.h>
#include <highgui.h>
#include <time.h>

using namespace cv;
using namespace std;

int main()
{
	// Create an array to store the output vectors
	vector<Vec3f> output_array;

	// Initialise a video file and Error Handling
	VideoCapture video("/home/pi/pupilDetect/vidtest.mp4");
	if (!video.isOpened());
	{
		printf("Error Opening Video File \n");
		return -1;
	} 
	else printf("The Video File has been opened correctly \n");

	// Extract a frame and Analyse
	Mat gray_frame, thres_frame, frame;
	int radius, cycle=0;
	clock_t clk1;

	for(::)
	{	
		// Initalize Clock
		cycle++;
		clk1 = clock();

		// Extract Frame
		video >> frame;

		// Image Processing on Frame
		cvtColor(frame, gray_frame, CV_BGR2GRAY);	
		threshold(gray_frame, thres_frame, threshold_variable, 255, 0);

		// Analyses for Circles
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

		// Find out time taken to process
		clk1 = clock() - clk1;
		printf("Cycle: %d - This took %f seconds to perform. \n", cycle, ((float)clk1)/CLOCKS_PER_SEC)

		// Show Frame
		imshow("frame", frame);
		if (waitKey(30) >= 0) break;
	}

	return 0;	
}