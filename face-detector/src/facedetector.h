#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

//opencv inculdes
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/imgproc/imgproc_c.h"

// C++ includes
#include <iostream>
#include <thread>
#include <string>

using namespace cv;

class FaceDetector
{
public:
    FaceDetector(const std::string img_path, const std::string cascade);
    void detect();
    void show_img(Mat img);




private:
    std::string _cascade_name;
    Mat frame;
    CascadeClassifier  _face_cascade;
    std::vector<Rect>  _foundFaces;
    std::vector<CvScalar> _colorsCol;
};

#endif // FACEDETECTOR_H
