//
//  main.cpp
//  Start Stream
//
//  Created by Ali Fazel on 24/03/2014.
//  Copyright (c) 2014 Ali Fazel. All rights reserved.
//

#include <iostream>

int main()
{

    //Create remote connection to RPi using SSH to enable stream
    printf("This will create a remote connection to the RPi and start streaming\nPlease enter the password as 'raspberry'\n\n");
    std::string command_line1 = "ssh pi@ 192.168.0.105 ./startStream";
    system(command_line1.c_str());
    return 0;
}