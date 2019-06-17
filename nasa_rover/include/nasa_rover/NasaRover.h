#ifndef NASA_ROVER_H_
#define NASA_ROVER_H_

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <gtest/gtest.h>

/**
 * @brief The NasaRover class
 */
class  NasaRover{

  friend class NasaRoverTestClass;

public:

  int nasa_rover_x_;
  int nasa_rover_y_;
  char nasa_rover_orientation_;
  std::string nasa_rover_commands_;

  bool show_rover_trail_;

  enum rover_direction_
  {
    NORTH = 'N',
    WEST = 'W',
    SOUTH = 'S',
    EAST = 'E'
  };

  NasaRover(int position_x, int position_y, char Orientation, std::string Command);
  ~NasaRover();

  void rotateLeft();
  void rotateRight();
  void moveForward();
  void Initialize_params(int position_y, int position_x, std::string Command, char Orientation);
}; //end of class
#endif

