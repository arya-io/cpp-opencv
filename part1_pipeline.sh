#!/bin/bash
# Part 1: GStreamer pipeline to process the MP4 video
gst-launch-1.0 filesrc location=video.mp4 ! decodebin ! videoconvert ! videoscale ! video/x-raw,width=640,height=640 ! jpegenc ! multifilesink location="frame_%05d.jpg"