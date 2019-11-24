// Includes
#include <iostream>

// OpenCV Includes
#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>

// Definitions
#define OD_GRAYSCALE 1
#define OD_GRAYSCALE_V2 2
#define OD_GRAYSCALE_V3 3
#define OD_THRESH_MUTLI 1
#define OD_THRESH_SINGLE 2
#define OD_THRESH_CUSTOM 3
#define OD_BLUR_REG 1
#define OD_BLUE_GAUS 2
#define OD_BLUR_MEDIAN 3
#define OD_MAX_SMOOTH 3
#define OD_MAX_GSCALE 3
#define OD_MAX_THRESH 3

// Namespaces
using namespace std;
using namespace cv;

class VideoFeed {
  public:
    VideoFeed(void);
    bool isLive();
    CvCapture* get();
    CvSize getSize()'
    IplImage* getAsIplImage();
    IplImage* getSmoothedImage(int smoothingType);
    IplImage* getImageMask(int smoothingType, int grayScaleType, int threshType);
    
  private:
    // declarations
    CvCapture* feed;
    // (videofeed) obj.live == ?;
    bool live = false;
};
