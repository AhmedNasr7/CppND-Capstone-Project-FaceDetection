#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

//opencv inculdes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"

// C++ includes
#include <iostream>
#include <vector>
#include <thread>

using namespace cv;

class FaceDetector
{
public:
    FaceDetector(const &std::string cascade);
    Detect(Mat img);




private:
    String _cascade_name;
    CascadeClassifier  _face_cascade;
    std::vector<Rect>  _foundFaces;
    std::vector<CvScalar> _colorsCol;
};

#endif // FACEDETECTOR_H
