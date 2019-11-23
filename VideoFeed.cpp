#include <iostream>

// OpenCV Includes
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

// Use namespaces
using namespace std;
using namespace cv;

// declarations
CvCapture* feed;
// (videofeed) obj.live == ?;
bool live = false;

// constructor 1
void VideoFeed(int camNumber) {
  // Initialize feed
   feed = cvCaptureCAM(camNumber);
  // Make sure feed is live, else throw exception
   if (!cvQueryFrame(feed))
     live = true;
  else 
    throw "CamFeedException (videofeed.cpp | constructor(int))";
}

// Return feed
CvCapture* get() {
  // Make sure feed is available, else throw exception
  if (feed != NULL) 
    return feed;
  else {
    throw "NoFeedException (videofeed.cpp | CvCapture* get())";
    return NULL;
  }
}

// Get size of feed
CvSize getSize() {
  // Make sure feed is available, else throw exception
  if (feed != NULL) 
    return cvGetSize(cvQueryFrame(feed));
  else {
    throw "NoFeedException (videofeed.cpp | CvSize getSize())";
    return NULL;
  }
}

IplImage* getAsIplImage() {
  // Make sure feed is available, else throw exception
  if (feed != NULL) {
    CvSize sz = getSize();
    // Default 3 channels // depth 8
    IplImage* img = cvCreateImage(sz, 8, 3);
    return img;
  } else {
    throw "NoFeedException (videofeed.cpp | IplImage* getAsIplImage())";
    return NULL;
  }
}
