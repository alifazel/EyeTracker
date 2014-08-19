print __doc__
from SimpleCV import *

# Initialize the camera from a video file as variable 'cam' 
cam = VirtualCamera("/home/parallels/Videos/example.mov", "video")
display = Display()

normaldisplay = True			# Boolean to switch between normal display and threshold

while True:									# Creates a Loop
	img = cam.getImage()					# Extracts frame from video as variable 'img'
	dist = img.colorDistance(SimpleCV.Color.BLACK).dilate(2) # Finds Colour Distance from White (Grayscale)
	segmented - dist.stretch(250,300)		# Applies Threshold between 200-300

	blobs = segmented.findBlobs()			# Searches for blobs

	if blobs:								# If Blobs are found...
		radius = blobs[-1],radius()
		img.drawCircle((blobs[-1].x, blobs[-1].y, blobs[-1].radius(), SimpleCV.Color.RED, radius))
											# Draws Cricle around the blobs using the array blobs
	if normaldisplay:			# If normalDisplay is true, then show the normal view
		img.show()
	else:						# Else if false show the threshold for debugging purposes
		segmented.show()