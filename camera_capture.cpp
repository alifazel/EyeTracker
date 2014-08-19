#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main ()
{
	// Initializes camera using start-up stream script
	system("/home/pi/raspifastcam/start_camd.sh")
	// Manually captures a frame when the program is called.
	system("/home/pi/raspifastcam/do_capture.sh")
	// Deinitializes camera using stop script
	system("/home/pi/raspifastcam/stop_camd.sh")
}