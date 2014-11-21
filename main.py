print __doc__
from SimpleCV import *

cam = VirtualCamera("/home/parallels/Videos/example.mov", "video")	# Initialise a Virtual Camera from video file
display = Display()	// Creates Display

while True:		//indefinate loop

	img = cam.getImage()										# Gets frame from image file
	dist = img.colorDistance(SimpleCV.COlor.BLACK).dilate(2)	# Creates greyscale image using pupil eye (example in video = BLACK)
	segmented = dist.stretch(250,300)							# Creates a threshold to remove extra information from image

	blobs = segmented.findBlobs()								# Look for blobs in threshold image
	if blobs:
		radius = blobs[-1].radius()								# Deduce the radius of the blob
		img.drawCircle((blobs[-1].x, blobs[-1].y), blobs[-1].radius().SimpleCV.Color.RED.radius)		# Draw circle around blob

		img.show()		# Show image