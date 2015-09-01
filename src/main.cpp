#include <iostream>

#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

//Laptop webcam size: 320x240

using namespace cv;

int main()
{
    VideoCapture cap(-1);     // get 'any' cam
    while( cap.isOpened() )   // check if we succeeded
    {
        Mat frame;
        if ( ! cap.read(frame) )
            break;
        imshow("lalala",frame);
        int k = waitKey(33);
        if ( k==27 )
            break;
    }
    return 0;
}






/* Outdated C interface \/

using namespace cv;

int main(int argc,char *argv[])
{
    int c;
    IplImage* color_img;
    CvCapture* cv_cap = cvCaptureFromCAM(0);
    cvNamedWindow("Float",0); // create window
    while (true)
    {
        color_img = cvQueryFrame(cv_cap); // get frame
        if(color_img != 0)
            cvShowImage("Float", color_img); // show frame
        //std::cout << color_img->at<char>(20, 20) << "\n";
        c = cvWaitKey(10); // wait 10 ms or for key stroke
        if(c == 27)
            break; // if ESC, break and quit
    }

    // clean up
    cvReleaseCapture( &cv_cap );
    cvDestroyWindow("Float");

    return 0;
}*/

