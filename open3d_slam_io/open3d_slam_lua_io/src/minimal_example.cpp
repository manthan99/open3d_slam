/*
 * minimal_example.cpp
 *
 *  Created on: Nov 11, 2022
 *      Author: jelavice
 */



#include <ros/package.h>
#include <iostream>
#include <memory>
#include "open3d_slam_lua_io/parameter_loaders.hpp"
#define watch(x) std::cout << "variable: \033[1;31m" << (#x) << "\033[0m is " << (x) << std::endl


int main(int argc, char** argv) {
  using namespace o3d_slam;
  const std::string folderPath = ros::package::getPath("open3d_slam_lua_io") + "/example_param/";
  SlamParameters param;
  io_lua::loadParameters(folderPath, "configuration.lua", &param);


  watch(param.odometry_.scanProcessing_.voxelSize_);
  watch(param.odometry_.scanProcessing_.downSamplingRatio_);
  watch(param.odometry_.scanProcessing_.cropper_.cropperName_);
  watch(param.odometry_.scanProcessing_.cropper_.croppingMaxRadius_);

//  watch(param.saving_.isSaveAtMissionEnd_);
//  watch(param.saving_.isSaveMap_);
//  watch(param.saving_.isSaveSubmaps_);
//
//  watch(param.motionCompensation_.isSpinningClockwise_);
//  watch(param.motionCompensation_.isUndistortInputCloud_);
//	watch(param.motionCompensation_.numPosesVelocityEstimation_);
//	watch(param.motionCompensation_.scanDuration_);

  std::cout << "All done" << std::endl;
  return 0;
}


