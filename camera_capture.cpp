#include <iostream>
#include <cv.h>
#include <highgui.h>

using namespace cv;
using namespace std;

int main ()
{
	execlp("raspistill", "raspistill", "-n", "-w", "640", "-h", "480", "-o", ".home/pi/camera/capture.jpg", "-t", "1", NULL);
}