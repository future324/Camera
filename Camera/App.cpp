#include<opencv2\opencv.hpp>
#include <opencv2/highgui.hpp>
using namespace std;
using namespace cv;
#define deView(i) imshow(#i,i)
Mat frame=Mat::zeros(Size(320,240),CV_8UC3) ;
int Count = 0;
void onMouse(int event, int x, int y, int flags, void *userdate)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		Count++;
		cv::imwrite(std::to_string(45+Count)+".png", frame);
	}
}
int main()
{
	Mat img = imread("1.jpg", 1);
	VideoCapture cam(0);
	if (!cam.isOpened())  return -1;
	cam >> frame;
	for (;waitKey(10)!=27; cam>>frame)
	{
		namedWindow("frame");
		setMouseCallback("frame", onMouse, 0);
	    deView(frame);
	   // cout << frame.type() << endl;
	}
}