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
void videofeed(int camNumber) {
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
