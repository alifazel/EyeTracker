//
//  LoadStreamServer.cpp
//  Pupil Detection
//
//  Created by Ali Fazel on 28/12/2013.
//  Copyright (c) 2014 Ali Fazel. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include </usr/local/include/opencv/cv.h>
#include </usr/local/include/opencv/highgui.h>
#include </usr/local/include/opencv2/gpu/gpu.hpp>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <fstream>

using namespace cv;
using namespace std;


int main()
{
     //Creates vector array for HoughCircles
     vector<Vec3f> output_array;
     
     //Captures IP Address manually of Raspberry Pi
     string server_ip;
     string server_address;
     
     printf("Please enter the IP address for the Raspberry Pi:\n");
     getline(cin, server_ip);
     server_address = "rtsp://" + server_ip + ':' + "8554" +'/';
     
     //Initialize frame and capture.
     Mat frame;
     VideoCapture video;
     
     //Open Network Stream
     printf("Connecting to %s ...\n", server_address.c_str());
     video.open(server_address);
     
     
     //Checks to see if the file has been correctly opened
     if(!video.isOpened())
     {
          printf("Error opening Stream\n");
          return -1;
     }
     else
          printf("The Stream has been opened correctly.\n");

     //Initialises variables
     std::ofstream output_file;
     Mat gray_frame, thres_frame, blur_frame;
     int radius, cycle=0;
     clock_t clk1;
     string output_string;
     
     //Opens text file to output data to (In append mode)
     output_file.open("output.txt", std::ios_base::app);
     
     //Infinite Loop to Extract frame from video and display on screen
     for(;;)
     {
          cycle++;
          clk1 = clock();
          video >> frame;
          if(frame.empty())
               break;    // Break loop if EOF on stream
          
          
          //Applies Transformations
          cvtColor(frame, gray_frame, CV_BGR2GRAY);
          threshold(gray_frame,thres_frame, 60, 255, 0);
          HoughCircles(gray_frame, output_array, CV_HOUGH_GRADIENT, 2, thres_frame.rows, 150, 100);

          
          //Draw Circle on Frame
          for (int i=0; i<output_array.size(); i++)
          {
               Point center(cvRound(output_array[i][0]), cvRound(output_array[i][1]));
               radius =cvRound(output_array[i][2]);
               
               circle(frame, center, 5, (255,255,255), -1, 8, 0);
               circle(frame, center, radius, (255,0,255), 3, 8, 0);
               output_string = cvRound(output_array[i][0]) + ',' + cvRound(output_array[i][1]) + ',' + cvRound(output_array[i][2]);
               output_file << output_string;
          }
          
          //Calculates time taken to perform operation
          clk1 = clock() - clk1;
          printf("Cycle: %d This took %f seconds to perform.\n", cycle,((float)clk1)/CLOCKS_PER_SEC);
          
          //Shows image till ESC pressed
          imshow("frame", frame);
          if (waitKey(30) >= 0) break;
     }
     
     return 0;
}

