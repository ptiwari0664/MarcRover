#ifndef FILE_HANDLER_H_
#define FILE_HANDLER_H_

#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdio.h>

struct RoverPose_
{
  int x;
  int y;
  char orientation;
  std::string command;
}; //end of structure

/**
 * @brief The FileHandler class
 * @abstract To handle the file reading
 */
class FileHandler {

  friend class NasaRoverTestClass;

public:

  bool line_complete_;

  bool debug_prints_;

  std::vector<RoverPose_> rover_file_poses_;

  FileHandler();

  void file_reader(const char* filename);

}; //end of class

#endif 
