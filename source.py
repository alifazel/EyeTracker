print __doc__
from SimpleCV import *

# Initialize the camera from a video file as variable 'cam' 
cam = VirtualCamera("/home/parallels/Videos/example.mov", "video")
# Initalizes a image to use as colour match for detecting eye colour
c_match = Image("/home/parallels/Videos/match.jpg")
match = c_match.getPixel(5,5)

while True:									# Creates a Loop
	img = cam.getImage()					# Extracts frame from video as variable 'img'
	grayscale = img.colorDistance(match) 	# Finds Colour Distance from image
	threshold - grayscale.threshold(80)		# Applies Threshold of 80

	blobs = threshold.findBlobs()			# Searches for blobs

	blobs.show()