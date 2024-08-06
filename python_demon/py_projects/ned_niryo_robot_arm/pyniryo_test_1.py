from pyniryo import *
robot_ip_address = "10.10.10.10"
# Connect to robot & calibrate
robot = NiryoRobot(robot_ip_address)
robot.calibrate_auto()
# Move joints
robot.set_arm_max_velocity(100)
robot.move_joints(0.0, 0.0, 0.0, 0.0, 0.0, 0.0)
for i in range(0,3):
    robot.move_joints(0.5, 0.0, 0.0, 0.0, 0.0, 0.0)
    robot.move_joints(0.0, 0.5, 0.0, 0.0, 0.0, 0.0)
    robot.move_joints(-0.5, 0.0, 0.0, 0.0, 0.0, 0.0)
#robot.move_pose(0.21, 0, 0.4, 0, 1.57, 0) #vị trí quan sát bàn gắp
robot.move_joints(-0.002, 0.493, -1.327, 0.011, -0.089, -0.007) #vị trí nghỉ đẹp
robot.wait(3)

# Turn learning mode ON
robot.set_learning_mode(True)
# Stop TCP connection
robot.close_connection()

