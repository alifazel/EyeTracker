//
//  main.cpp
//  LoadStream
//
//  Created by Ali Fazel on 24/03/2014.
//  Copyright (c) 2014 Ali Fazel. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[])
{
    std::string command_line2 = "/Applications/VLC.app/Contents/MacOS/VLC -I dummy -vvv http://192.168.0.105:8554/ --sout=file/ps:/Users/alifazel/Documents/PupilDetect/cache.h264";
    system(command_line2.c_str());
}

