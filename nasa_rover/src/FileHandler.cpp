#include "nasa_rover/FileHandler.h"

/**
 * @brief FileHandler::FileHandler Constructer
 */
FileHandler::FileHandler(){ debug_prints_ = false;
                            line_complete_ = false;}

/**
 * @brief FileHandler::file_reader
 * @param filename
 * @abstract to read the contents of the given file
 */
void FileHandler::file_reader(const char* filename) {

  // Create object from file
  std::ifstream ifile(filename);

  // Check if file is loadable
  if (!ifile) {
      std::printf("\nBad file name\n");
      exit(-1);
    }

  std::string line;

  int pos_x ;
  int pos_y;
  char ori;
  std::string cmd = "";

  // Read till you run out of lines
  while (std::getline(ifile, line))
    {
      // Read Line
      std::istringstream iss(line);
      std::string command_type;

      iss >> command_type;

      //P refers to rover pose
      //C refer to rover command
      //I refers to rover upperright
      //Rest is ignored if given
      if (command_type.compare("P") == 0)
        {
          iss>> pos_x;
          iss>> pos_y;
          iss>> ori;

          if(debug_prints_)
            std::cout <<"file read: "<< pos_x << "\t"
                     << pos_y << "\t"
                     << ori << "\t" << std::endl;

          line_complete_ = false;
        }
      else if (command_type.compare("C") == 0)
        {
          iss>>cmd;
          line_complete_ = true;
          if(debug_prints_)
            std::cout << "file read: " << cmd << std::endl;
        }
      else if (command_type.compare("I") == 0)
        {
          if(debug_prints_)
            std::cout << "Initial Position" <<std::endl;
          continue;
        }
      else {
          if(debug_prints_)
            std::cout << "Not a valid input" <<std::endl;
          continue;
        }

      if(line_complete_)
        {
          RoverPose_ roverposition;
          roverposition.x = pos_x;
          roverposition.y = pos_y;
          roverposition.orientation = ori;
          roverposition.command = cmd;
          rover_file_poses_.push_back(roverposition);
        }
    }

  std::cout << "Total "<< rover_file_poses_.size() << " rovers detected !!!" <<std::endl;

}
