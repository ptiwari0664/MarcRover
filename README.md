# MarsRover
A squad of robotic rovers are to be landed by NASA on a different planets like Mars, Pluto etc. 

You are responsible to land and operate the rovers sent for Mars plateau. This plateau, which is curiously flat and rectangular, must be navigated by the rovers so that their on- board cameras can get a complete view of the surrounding terrain to send back to Earth.

A rover's position is represented by a combination of an x and y co-ordinates and a letter representing one of the four cardinal compass points. The plateau is divided up into a grid of cells to simplify navigation. An example position might be 0, 0, N, which means the rover is in the bottom left corner and facing North. 

In order to control a rover, NASA sends a simple string of letters. The possible letters are 'L', 'R' and 'M'. 'L' and 'R' makes the rover spin 90 degrees left or right respectively, without moving from its current spot. 'M' means move forward one grid cell, and maintain the same heading. Assume that the square directly North from (x, y) is (x, y+1).  Also assume that each cell size is 1 sq-cm and individual rover occupies the entire cell.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

The files rover_input.txt and rover_output.txt should be at home location. If this is not the case, then the program will not read the files
and will output a bad file name and terminates. 

### I/p and O/P File description

The rover_input.txt file contains 4 rover's pose and commands with the first line being the initial pose. In the input file the first element
represents the type of command e.g.
I : Initial Pose
P : Rover Pose (x, y, direction)
C : Rover Command (M or R or L)
If any other command is given, then it will be ignored by the program.
 
To enable debugging    : Go to the FileHandler class constructor and set debug_prints_ = true
To see the rover trail : Go to the NasaRover class function Initialize_params() and set show_rover_trail_ = true, which will show the rover
			 trail on the terminal.


### Prerequisites

To follow the first installation method, ros and catkin is required

### Installing

To install, there can be two ways:

#### First method 
1. mkdir -p catkin_ws/src
2. copy/move the nasa_rover in src folder
3. cd catkin_ws
4. catkin_make

#### Second method
1. cd nasa_rover
2. mkdir build
3. cd build
4. cmake ..
5. make

### Running the programs 

To run the executables, there are two methods which depends on the installation method
 
#### First Method
cd catkin_ws/devel/lib/nasa_rover
./nasa_rover_node

#### Second method
cd nasa_rover/build/devel/lib/nasa_rover
./nasa_rover_node 

### Running the tests

To run the tests, there are two methods which depends on the installation method. There are two tests and those are mentioned bewlow:
1. Checking the proper functionality of NasaRover class where the inputs can be given and the final output can be checked.
2. Checking the proper functionality of FileHandler class where it checks the correct reading of the rover_input.txt file.
Please be cautionous while doing the tests. Don't forget to change the desired output.

#### First Method
cd catkin_ws/devel/lib/nasa_rover
./nasa_rover_test

#### Second method
cd nasa_rover/build/devel/lib/nasa_rover
./nasa_rover_test

## Authors

* **Puneet Tiwari**
