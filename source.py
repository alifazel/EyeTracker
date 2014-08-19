print __doc__
from SimpleCV import *

# Initialize the camera from a video file as variable 'cam' 
cam = VirtualCamera("/home/parallels/Videos/example.mov", "video")

while True:									#Creates a Loop
	img = cam.getImage()					#Extracts frame from video as variable 'img'
	eye = img.findHaarFeatures("eye.xml")	#Find the Haar Features

	if eye is not None:				#Checks to see if the array is not Null
		eyes = eyes.sortArea()		
		myFace = eyes[-1]			#Checks the previous entry
		myFace.draw(width=3, color=Color.RED)	#Draws a square around the detected eye
		
	img.show()