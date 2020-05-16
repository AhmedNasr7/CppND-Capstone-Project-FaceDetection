#include "facedetector.h"


FaceDetector::FaceDetector(const std::string cascade)
{
    _cascade_name = cascade;

    if(!_face_cascade.load(_cascade_name)){ std::cout << "--(!)Error loading\n";}

    /*8 colors collection*/
    /*
    colorsCol   << cvScalar(0.0,0.0,255.0)   << cvScalar(0.0,128.0,255.0)
                << cvScalar(0.0,255.0,255.0) << cvScalar(0.0,255.0,0.0)
                << cvScalar(255.0,128.0,0.0) << cvScalar(255.0,255.0,0.0)
                << cvScalar(255.0,0.0,0.0)   << cvScalar(255.0,0.0,255.0);
    */

}


