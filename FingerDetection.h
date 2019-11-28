#include <iostream>
#include "cv.h"
#include "cvcore.h"

#define OD_FD_METHOD_REG 1
#define OD_FD_METHOD_CUSTOM 2

class FingerDetection {
  public:
    FingerDetection(void);
    int returhCount();
    int countFromImage(IplImage* img);
    IplImage* getMaskedImageFeed();
    IplImage* getMaskedImageFrame(IplImage* img);
    
  
  private:
  int c;
  int count;
  double threshold;
  IplImage* mask;
  IplImage* frame;
  CvCapture* feed;
  
};
