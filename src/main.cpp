#include <iostream>
#include <ncurses.h>

#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

//Laptop webcam size: 320x240

using namespace cv;

int main()
{
    //initscr();

    std::string letters = " .'`^\",:;Il!i><~+_-?][}{1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

    VideoCapture cap(-1);     // get 'any' cam
    while( cap.isOpened() )   // check if we succeeded
    {
        Mat frame(640, 480, CV_8UC3, Scalar(0, 0, 255));
        cap.read(frame);

        //flip(frame, frame, 1);
        //imshow("Float",frame);
        //std::cout << (int)frame.at<char>(0, 0) << ", " << (int)frame.at<char>(0, 1) << ", " << (int)frame.at<char>(0, 2) << "\n";

        //for (int y = 0; y < )
        //std::cout << "Width: " << frame.cols << ", Height: " << frame.rows << "\n";

        int terminalWidth = 140;
        int terminalHeight = (terminalWidth * frame.rows) / frame.cols * 0.53;
        int scrToTermRation = frame.cols / terminalWidth;
       //std::cout << terminalHeight << "\n";

        for (int y = 0; y < terminalHeight; y++)
        {
            for (int x = 0; x < terminalWidth; x++)
            {
                //int R = frame.at<char>()
                Vec3b pixel = frame.at<Vec3b>(y * scrToTermRation * 2, x * scrToTermRation);
                int r = pixel.val[2];
                int g = pixel.val[1];
                int b = pixel.val[0];

                //std::cout << letters.at(((r+g+b) / 768.0) * letters.length());
                //std::cout << x << "," << y << "\n";
                //std::cout << ((r+g+b) / 768.0) * letters.length() << "\n";
                std::cout << r + g + b << ", " << (r+g+b) / 768.0 <<  "\n";
                int index = (int)(((r+g+b) / 768.0) * letters.length());
                char letter = (char)(letters.at(index));
                //printw(&letter);
                //mvaddch(y, x, letter);
                //refresh();
            }
            //mvaddch(y, terminalWidth + 1, '\n');
            //refresh();
            //std::cout << "\n";
        }

        //int k = waitKey(33);
        //if ( k==27 )
        //    break;
    }

    //endwin();

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

