#include "facedetector.h"


#include <string>
#include <fstream>


using namespace cv;


FaceDetector::FaceDetector(const std::string &img_path, const std::string &cascade)
{
    _cascade_name = cascade; 

    if(!_face_cascade.load(_cascade_name)){ std::cout << "Error loading\n"; } // loading file
  
  	
  	frame = imread(img_path, IMREAD_COLOR);   // read img
  
  	if (frame.empty()) // check if failed to read
	{
    std::cout << "method imread() failed, image not found" << std::endl;
    return;
	}
  
 
    /*vector of 8 colors collection*/
    
    _colorsCol = {cvScalar(0.0,0.0,255.0), cvScalar(0.0,128.0,255.0),
                  cvScalar(0.0,255.0,255.0), cvScalar(0.0,255.0,0.0),
                  cvScalar(255.0,128.0,0.0), cvScalar(255.0,255.0,0.0),
                  cvScalar(255.0,0.0,0.0), cvScalar(255.0,0.0,255.0)
                  };
    
  

}


void FaceDetector::detect()
{
    Mat img_gray;
    cvtColor(frame, img_gray, COLOR_BGR2GRAY); // convert to gray for faster detection
  
	_result_img = frame.clone(); // copy input image to draw on the result image
  
    //Detection, the hyperparameters obtained by experimenting
    _face_cascade.detectMultiScale(img_gray,
                                  _foundFaces,
                                   1.2, 3, 0 | CASCADE_SCALE_IMAGE, Size(10, 10));
	
    int n = _foundFaces.size();
  	_faces_num = n; 
  
    //Draw rectangles around faces
    CvRect rect;
    for(int i = 0; i < n ; i++)
    {
        rect = _foundFaces[i];
        rectangle(_result_img, cvPoint(rect.x, rect.y),
                    cvPoint((rect.x + rect.width), (rect.y + rect.height)),
                    _colorsCol[i%8], 2);
    }
                                       
}

void FaceDetector::show_img()
{
  	
  	namedWindow( "image window", WINDOW_AUTOSIZE);// Create a window for display.
   	imshow( "image window", _result_img);   
  	waitKey(); 
}


int FaceDetector::get_number_of_faces()
{
  return _faces_num;
  
}