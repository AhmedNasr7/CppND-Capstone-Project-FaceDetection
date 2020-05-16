#include "facedetector.h"


using namespace cv;


FaceDetector::FaceDetector(const std::string img_path, const std::string cascade)
{
    _cascade_name = cascade;

    if(!_face_cascade.load(_cascade_name)){ std::cout << "Error loading\n";}
  
    frame = imread(img_path, IMREAD_COLOR);   // Read the file
  
  
    /*8 colors collection*/
    /*
    colorsCol   << cvScalar(0.0,0.0,255.0)   << cvScalar(0.0,128.0,255.0)
                << cvScalar(0.0,255.0,255.0) << cvScalar(0.0,255.0,0.0)
                << cvScalar(255.0,128.0,0.0) << cvScalar(255.0,255.0,0.0)
                << cvScalar(255.0,0.0,0.0)   << cvScalar(255.0,0.0,255.0);
    */

}




void FaceDetector::detect()
{
    Mat img_gray;
    cvtColor(frame, img_gray, COLOR_BGR2GRAY);
    //equalizeHist(img_gray, img_gray);
/*
    //Detection
    _face_cascade.detectMultiScale(frame_gray,
                                  foundFaces,
                                   1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(100, 100));

    int n = foundFaces.size();
    //Draw rectangles around faces
    CvRect rect;
    for(int i = 0; i < n ; i++)
    {
        rect = foundFaces[i];
        rectangle(frame, cvPoint(rect.x, rect.y),
                    cvPoint((rect.x + rect.width), (rect.y + rect.height)),
                    colorsCol[i%8]);
    }

    // Convert Mat to QImage
    QImage result = QImage((const uchar *)frame.data,
                                          frame.cols,
                                          frame.rows,
                                          frame.step,
                                          QImage::Format_RGB888).rgbSwapped();


*/
  
}