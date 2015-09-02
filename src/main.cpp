#include <iostream>
#include <ncurses.h>

#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/highgui/highgui.hpp>  // OpenCV window I/O

using namespace cv;

int main()
{
    initscr();

    std::string letters = " .'`^\",:;Il!i><~+_-?][}{1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

    VideoCapture cap(-1);
    while( cap.isOpened() )
    {
        Mat frame;
        cap.read(frame);

        //imshow("Float",frame);

        int terminalWidth = 140;
        int terminalHeight = (terminalWidth * frame.rows) / frame.cols * 0.53;
        int scrToTermRation = frame.cols / terminalWidth;

        for (int y = 0; y < terminalHeight; y++)
        {
            for (int x = 0; x < terminalWidth; x++)
            {
                //int R = frame.at<char>()
                Vec3b pixel = frame.at<Vec3b>(y * scrToTermRation * 2, x * scrToTermRation);
                int r = pixel.val[2];
                int g = pixel.val[1];
                int b = pixel.val[0];

                int index = (int)(((float)(r+g+b) / 768.0) * letters.length());
                char letter = (char)(letters.at(index));

                mvaddch(y, x, letter);
                refresh();
            }
            mvaddch(y, terminalWidth + 1, '\n');
            refresh();
        }
    }

    endwin();

    return 0;
}

