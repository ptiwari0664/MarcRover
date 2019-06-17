#include "test_nasa_rover.hpp"

/**
 * @brief The NasaRoverTestSuite class
 */
class NasaRoverTestSuite : public ::testing::Test{
public:
  NasaRoverTestSuite() {}
  ~NasaRoverTestSuite(){}

  NasaRoverTestClass test_roverclass_obj_;

protected:
  virtual void SetUp()
  {
    RobotTestPose test_rover;

    //Put the initial rover test poses here
    test_rover.x = 3;
    test_rover.y = 3;
    test_rover.orientation = 'E';
    test_rover.command = "MMRMMRMRRM";

    test_roverclass_obj_.nr_ = new NasaRover(test_rover.x,test_rover.y,
                                             test_rover.orientation, test_rover.command);

    std::string file_name = std::getenv("HOME");
    std::string add_file = "/rover_input.txt";

    test_roverclass_obj_.fh_ = new FileHandler();

    test_roverclass_obj_.fh_->file_reader(file_name.append(add_file).c_str());

  }

  virtual void TearDown()
  {
    delete test_roverclass_obj_.nr_;
  }
};

/**
 * @brief TEST_F
 * @abstract test function for NasaRover class test cases
 */
TEST_F(NasaRoverTestSuite, NasaRover_class_test)
{

  RobotTestPose test_rover_pose = test_roverclass_obj_.test_function();

  ASSERT_EQ(5,test_rover_pose.x);
  ASSERT_EQ(1,test_rover_pose.y);
  ASSERT_EQ('E',test_rover_pose.orientation);

}

/**
 * @brief TEST_F
 * @abstract test function for file reading function and class
 */
TEST_F(NasaRoverTestSuite, FileHandler_class_test)
{

  std::vector<RobotTestPose> test_file_rover_pose = test_roverclass_obj_.test_filereader();

  ASSERT_EQ(1,test_file_rover_pose.at(0).x);
  ASSERT_EQ(2,test_file_rover_pose.at(0).y);
  ASSERT_EQ('N',test_file_rover_pose.at(0).orientation);
  ASSERT_EQ("LMLMLMLMM",test_file_rover_pose.at(0).command);

  ASSERT_EQ(3,test_file_rover_pose.at(1).x);
  ASSERT_EQ(3,test_file_rover_pose.at(1).y);
  ASSERT_EQ('E',test_file_rover_pose.at(1).orientation);
  ASSERT_EQ("MMRMMRMRRM",test_file_rover_pose.at(1).command);

  ASSERT_EQ(2,test_file_rover_pose.at(2).x);
  ASSERT_EQ(2,test_file_rover_pose.at(2).y);
  ASSERT_EQ('W',test_file_rover_pose.at(2).orientation);
  ASSERT_EQ("MMRRMM",test_file_rover_pose.at(2).command);

  ASSERT_EQ(1,test_file_rover_pose.at(3).x);
  ASSERT_EQ(5,test_file_rover_pose.at(3).y);
  ASSERT_EQ('S',test_file_rover_pose.at(3).orientation);
  ASSERT_EQ("MMLMMR",test_file_rover_pose.at(3).command);
}

/**
 * @brief main
 * @param argc
 * @param argv
 * @return Pass / Fail
 */
int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
