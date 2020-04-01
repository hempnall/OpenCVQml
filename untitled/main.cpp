#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <cstring>

using namespace cv;
using namespace std;


int showImage( int argc , char** argv   )
{
    if( argc != 2)
    {
     cout <<" Usage: must specify a file" << endl;
     return -1;
    }

    Mat image;
    image = imread(argv[1], cv::IMREAD_COLOR);   // Read the file

    if(! image.data )                              // Check for invalid input
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", image );                   // Show our image inside it.

    waitKey(0);
}


int main( int argc, char** argv )
{
    showImage(argc,argv);
    return 0;
}
