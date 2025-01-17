# Video Frame Extraction and Face Detection

This repository contains two parts:

1. **GStreamer Pipeline** (Part 1) — A shell script that extracts and saves frames from a video using GStreamer.
2. **Face Detection in C++** (Part 2) — A C++ program that detects and crops faces from the frames using OpenCV's Haar Cascade classifier.

---

## Prerequisites

Before running the code, make sure you have the following installed on your system:

- **GStreamer** (for Part 1)
- **OpenCV** (for Part 2)
- **g++** or any other C++ compiler

# Part 1: GStreamer Pipeline

This part uses GStreamer to extract frames from a video and save them as JPEG images.

## Steps:

# Run the provided shell script:

./part1_pipeline.sh

# The script part1_pipeline.sh uses GStreamer’s gst-launch command to:
# - Read the input MP4 video.
# - Scale the video frames to a resolution of 640x640 pixels.
# - Encode each frame as a JPEG image.

# Example GStreamer pipeline used by the script:

gst-launch-1.0 filesrc location=video.mp4 ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=640,height=640 ! jpegenc ! multifilesink location="frame_%05d.jpg"

# Output:

# The frames will be saved as sequentially numbered JPEG files (e.g., frame_00001.jpg, frame_00002.jpg, etc.) in the Part_1_Output/frames/ directory.

# Part 2: Face Detection with OpenCV

# This part is a C++ application that processes the JPEG frames from Part 1 and detects faces in them using OpenCV’s pre-trained Haar Cascade classifier. It then crops the detected faces and saves them in a structured output directory.

## Steps:

# 1. Using g++, compile the program manually.

# Ensure that face_detection.cpp includes the OpenCV headers, and the Haar Cascade XML file is available in the same directory or the proper path is set.

# 2. Run the face detection program:

# After compiling the code, run the program:

./face_detection

# The program takes two arguments: the input directory (which contains the frames) and the output directory (where the cropped faces will be saved).

# The application will loop through each frame, detect faces using OpenCV, crop the faces, and save them to the Part2_Output/ directory.

# Output:

# Each frame’s detected faces will be saved in a corresponding subdirectory within Part_2_Output/ (e.g., Part_2_Output/frame_1/, Part_2_Output/frame_2/).

# If multiple faces are detected in a frame, they will be saved as separate files (e.g., face_1.jpg, face_2.jpg).

# Notes:

# - You can modify the shell script or C++ program to adjust the input/output paths or the parameters such as frame resolution or face detection sensitivity.
# - Ensure that the Haar Cascade XML file for face detection (e.g., haarcascade_frontalface_default.xml) is present in the correct location or specify the correct path in the C++ code.

# License

# This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.