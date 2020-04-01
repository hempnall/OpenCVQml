#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cstring>

int mainSharpen( int argc , char** argv )
{
    help(argv[0]);
     const char* filename = argc >=2 ? argv[1] : "../data/lena.jpg";
     Mat src, dst0, dst1;
     if (argc >= 3 && !strcmp("G", argv[2]))
         src = imread( filename, IMREAD_GRAYSCALE);
     else
         src = imread( filename, IMREAD_COLOR);
     if (src.empty())
     {
         cerr << "Can't open image ["  << filename << "]" << endl;
         return -1;
     }
     namedWindow("Input", WINDOW_AUTOSIZE);
     namedWindow("Output", WINDOW_AUTOSIZE);
     imshow( "Input", src );
     double t = (double)getTickCount();
     Sharpen( src, dst0 );
     t = ((double)getTickCount() - t)/getTickFrequency();
     cout << "Hand written function time passed in seconds: " << t << endl;
     imshow( "Output", dst0 );
     waitKey();
     Mat kernel = (Mat_<char>(3,3) <<  0, -1,  0,
                                    -1,  5, -1,
                                     0, -1,  0);
     t = (double)getTickCount();
     filter2D( src, dst1, src.depth(), kernel );
     t = ((double)getTickCount() - t)/getTickFrequency();
     cout << "Built-in filter2D time passed in seconds:     " << t << endl;
     imshow( "Output", dst1 );
     waitKey();
     return 0;
 }


