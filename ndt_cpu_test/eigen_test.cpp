#include <eigen3/Eigen/Geometry>
#include <eigen3/Eigen/Dense>
#include <iostream>


int main(){

    double roll, pitch, yaw, x, y, z;
    
    roll = 0.25*M_PI;
    pitch = 0.5*M_PI;
    yaw = 0.33*M_PI;

    x =1.2;
    y = 3.4;
    z = 5.5;

    Eigen::AngleAxisf init_rotation_x(roll, Eigen::Vector3f::UnitX());
    Eigen::AngleAxisf init_rotation_y(pitch, Eigen::Vector3f::UnitY());
    Eigen::AngleAxisf init_rotation_z(yaw, Eigen::Vector3f::UnitZ());

    Eigen::Translation3f init_translation(x, y, z);

    Eigen::Matrix4f m = (init_translation*init_rotation_z*init_rotation_y*init_rotation_x).matrix();

    std::cout << m << std::endl;

    return 0;
}