// Include Header File
#include <VideoFeed.h>

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

// check if feed is live
bool isLive() {
  return live;
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
    img = cvQueryFrame(feed);
    return img;
  } else {
    throw "NoFeedException (videofeed.cpp | IplImage* getAsIplImage())";
    return NULL;
  }
}

IplImage* getSmoothedImage(int smoothingType) {
  // Make sure feed is available, else throw exception
  if (feed != NULL) {
    // check if smoothing type is valid
    if (smoothingType > OD_MAX_SMOOTH) {
      throw "NullSmoothingType (videofeed.cpp | IplImage* getSmoothedImage())";
      return NULL;
    }
    
  } else {
    throw "NoFeedException (videofeed.cpp | IplImage* getSmoothedImage())";
    return NULL;
  }
}

IplImage* getImageMask(int smoothingType, int grayScaleType, int threshType) {
    // Make sure feed is available, else throw exception
    if (feed != NULL) {
      // check if types inputed are valid
      if (smoothingType > OD_MAX_SMOOTH || grayScaleType > OD_MAX_GSCALE || threshType > OD_MAX_THRESH) {
        throw "NullTypeException (videofeed.cpp | IplImage* getImageMask())";
        return NULL;
      }
    
    } else {
      throw "NoFeedException (videofeed.cpp | IplImage* getImageMask())";
      return NULL;
    }
}
