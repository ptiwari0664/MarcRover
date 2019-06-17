#include "nasa_rover/NasaRover.h"
#include "nasa_rover/FileHandler.h"
#include <iostream>
#include <string>
#include <gtest/gtest.h>

struct RobotTestPose
{
  int x;
  int y;
  char orientation;
  std::string command;
};

class NasaRoverTestClass{

public:
  NasaRoverTestClass() {}

  NasaRover *nr_;

  FileHandler *fh_;

  std::vector<RobotTestPose> rover_test_poses_;

  RobotTestPose test_function()
  {
    RobotTestPose test_rover;

    test_rover.x = nr_->nasa_rover_x_;
    test_rover.y = nr_->nasa_rover_y_;
    test_rover.orientation = nr_->nasa_rover_orientation_;
    test_rover.command = nr_->nasa_rover_commands_;

    return test_rover;
  }

  std::vector<RobotTestPose> test_filereader()
  {
    RobotTestPose test_rfp;

    for(size_t size=0; size<fh_->rover_file_poses_.size();size++)
      {
        test_rfp.x = fh_->rover_file_poses_.at(size).x;
        test_rfp.y = fh_->rover_file_poses_.at(size).y;
        test_rfp.orientation = fh_->rover_file_poses_.at(size).orientation;
        test_rfp.command = fh_->rover_file_poses_.at(size).command;

        rover_test_poses_.push_back(test_rfp);
      }

    return rover_test_poses_;
  }

};






