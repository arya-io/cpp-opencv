#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/utils/logger.hpp>
#include <filesystem>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;
namespace fs = std::filesystem;

int main() {
    utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);

    string inputFolder = "Part1_Output/frames";
    string outputFolder = "Part2_Output/";

    // Loading HaarCascade Classifier
    CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_default.xml");

    if (faceCascade.empty()) {
        cerr << "Error: Could not load Haar Cascade XML file." << endl;
        return -1;
    }

    // Iterating through JPEG files
    int frameIndex = 1;
    for (const auto& entry : fs::directory_iterator(inputFolder)) {
        if (entry.path().extension() == ".jpg") {
            
            Mat img = imread(entry.path().string());
            if (img.empty()) {
                cerr << "Error: Could not load image: " << entry.path() << endl;
                continue;
            }

            // Detecting faces
            vector<Rect> faces;
            faceCascade.detectMultiScale(img, faces, 1.1, 10);

            // Creating output folder for the faces from every frame
            string frameFolder = outputFolder + "frame_" + to_string(frameIndex);
            fs::create_directories(frameFolder);

            // Cropping and saving the detected faces
            int faceIndex = 1;
            for (const auto& face : faces) {
                Mat faceROI = img(face);
                string faceFile = frameFolder + "/face_" + to_string(faceIndex) + ".jpg";
                imwrite(faceFile, faceROI);
                faceIndex++;
            }

            frameIndex++;
        }
    }

    cout << "Face detection and cropping completed!" << endl;
    return 0;
}