#include <nasa_rover/NasaRover.h>
#include <nasa_rover/FileHandler.h>

/**
 * @brief main function for handling rover and file
 * @param argc
 * @param argv
 */
int main(int argc, char** argv)
{
  //Input file path and name
  std::string input_filepath = std::getenv("HOME");
  std::string input_file_name = "/rover_input.txt";

  //Output file path and name
  std::string output_filepath = std::getenv("HOME");
  std::string output_file_name = "/rover_output.txt";

  FileHandler rover_inputfile_;
  rover_inputfile_.file_reader(input_filepath.append(input_file_name).c_str());

  std::ofstream file;
  file.open(output_filepath.append(output_file_name).c_str());

  for (size_t count = 0; count < rover_inputfile_.rover_file_poses_.size(); count++)
    {
      NasaRover nasa_rover_obj(rover_inputfile_.rover_file_poses_.at(count).x,
                               rover_inputfile_.rover_file_poses_.at(count).y,
                               rover_inputfile_.rover_file_poses_.at(count).orientation,
                               rover_inputfile_.rover_file_poses_.at(count).command);

      //write the output file
      file << nasa_rover_obj.nasa_rover_x_ << " ";
      file << nasa_rover_obj.nasa_rover_y_ << " ";
      file << nasa_rover_obj.nasa_rover_orientation_;
      file << "\n";

      std::cout << "  Final Rover Position: " << nasa_rover_obj.nasa_rover_x_
                << " " << nasa_rover_obj.nasa_rover_y_
                << " " << nasa_rover_obj.nasa_rover_orientation_ <<std::endl;

      std::cout<<"............. All Commands Executed.............."<<std::endl;
    }

  file.close();

  return 0;
}
