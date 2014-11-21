#include <iostream>
#include <cv.h>
#include <highgui.h>
 
using namespace cv;
using namespace std;


int main()
{
	system("raspivid -w 320 -h 240 -fps 30 - o - -t -l -n | cvlc -vvv stream://dev/stdin --sout'#transcode{fps=30,width=320,height=240} :standard{access:http,mux=ts,dst=:8554}; :demux=h264");
	return 0;
}

