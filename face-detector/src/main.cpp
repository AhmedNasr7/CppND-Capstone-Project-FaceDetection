#include "facedetector.h"


// cascade: "./haarcascade_frontalface_alt2.xml"

int main()
{
  
  //std::cout << "main";
  std::string cascade_path = "../src/haarcascade_frontalface_alt2.xml";
  std::string img_path = "../images/faces.jpg";
  
  FaceDetector detector = FaceDetector(img_path, cascade_path);
  detector.detect();
  std::cout << "Number of detected faces in the images is: " << detector.get_number_of_faces() << std::endl;

  detector.show_img();
  
  
}
