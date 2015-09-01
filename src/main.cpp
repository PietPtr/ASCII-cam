#include <iostream>

#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace cv;

int main(int argc,char *argv[])
{
    int c;
    IplImage* color_img;
    CvCapture* cv_cap = cvCaptureFromCAM(0);
    cvNamedWindow("Float",0); // create window
    for(;;) {
        color_img = cvQueryFrame(cv_cap); // get frame
        if(color_img != 0)
            cvShowImage("Float", color_img); // show frame

        c = cvWaitKey(10); // wait 10 ms or for key stroke
        if(c == 27)
            break; // if ESC, break and quit
    }
    /* clean up */
    cvReleaseCapture( &cv_cap );
    cvDestroyWindow("Float");

    return 0;
}
