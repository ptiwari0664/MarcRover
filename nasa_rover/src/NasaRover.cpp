#include "nasa_rover/NasaRover.h"

/**
 * @brief NasaRover::NasaRover
 * @param position_x
 * @param position_y
 * @param Orientation
 * @param Command
 * @abstract Command dependent rover movement
 */
NasaRover::NasaRover(int position_x, int position_y,
                     char Orientation, std::string Command){

  Initialize_params(position_y, position_x, Command, Orientation);

  std::cout << "Initial Rover Position: " << nasa_rover_x_
            << " " <<nasa_rover_y_
            << " " <<nasa_rover_orientation_
            << " " <<nasa_rover_commands_ <<std::endl;

  //Execute all the commands
  for(size_t cmd_count = 0 ; cmd_count < nasa_rover_commands_.size() ; cmd_count++ )
    {
      if(nasa_rover_commands_.at(cmd_count) =='L')
        rotateLeft();

      else if(nasa_rover_commands_.at(cmd_count) =='R')
        rotateRight();

      else if (nasa_rover_commands_.at(cmd_count) == 'M')
        moveForward();

      else
        {
          if(show_rover_trail_)
            std::cout<<"Invalid command" <<std::endl;
          continue;
        }
    }
}

/**
 * @brief NasaRover::~NasaRover
 * @abstract brief destructor
 */
NasaRover::~NasaRover(){}

/**
 * @brief NasaRover::Initialize_params
 * @param position_y
 * @param position_x
 * @param Command
 * @param Orientation
 * @abstract initialize parameters
 */
void NasaRover::Initialize_params(int position_y, int position_x,
                                  std::string Command, char Orientation)
{
  nasa_rover_x_ = position_x;
  nasa_rover_y_ = position_y;
  nasa_rover_orientation_ = Orientation;
  nasa_rover_commands_ = Command;

  show_rover_trail_ = false;
}

/**
 * @brief NasaRover::rotateLeft
 * @abstract rover rotation towards left
 */
void NasaRover::rotateLeft()
{
  switch (nasa_rover_orientation_) {
    case NORTH:
      nasa_rover_orientation_ = WEST;
      break;
    case WEST:
      nasa_rover_orientation_ = SOUTH;
      break;
    case SOUTH:
      nasa_rover_orientation_ = EAST;
      break;
    case EAST:
      nasa_rover_orientation_ = NORTH;
      break;
    default:
      break;
    }

  if(show_rover_trail_)
    std::cout << "Rotate Left : " << nasa_rover_x_
              << " " <<nasa_rover_y_
              << " " <<nasa_rover_orientation_ <<std::endl;
}

/**
 * @brief NasaRover::rotateRight
 * @abstract rover rotation towards right
 */
void NasaRover::rotateRight(){

  switch (nasa_rover_orientation_) {
    case NORTH:
      nasa_rover_orientation_ = EAST;
      break;
    case EAST:
      nasa_rover_orientation_ = SOUTH;
      break;
    case SOUTH:
      nasa_rover_orientation_ = WEST;
      break;
    case WEST:
      nasa_rover_orientation_ = NORTH;
      break;
    default:
      break;
    }

  if(show_rover_trail_)
    std::cout << "Rotate Right: " << nasa_rover_x_
              << " " <<nasa_rover_y_
              << " " <<nasa_rover_orientation_ <<std::endl;
}

/**
 * @brief NasaRover::moveForward
 * @abstract rover forward movement function
 */
void NasaRover::moveForward(){

  switch (nasa_rover_orientation_) {
    case NORTH:
      nasa_rover_y_++;
      break;
    case EAST:
      nasa_rover_x_++;
      break;
    case SOUTH:
      nasa_rover_y_--;
      break;
    case WEST:
      nasa_rover_x_--;
      break;
    default:
      break;
    }

  if(show_rover_trail_)
    std::cout << "Move Forward: " << nasa_rover_x_
              << " " <<nasa_rover_y_
              << " " <<nasa_rover_orientation_ <<std::endl;
}
