//
// Created by tr on 7/16/19.
//

#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace std;
int main()
{
    //请在下面添加代码
    Eigen::Quaterniond q (0.1, 0.35, 0.2 ,0.3);
    std::cout<<q.coeffs()<<endl;
    cout<<"Rotation_Matrix\n"<<q.toRotationMatrix()<<endl;
    Eigen::Quaterniond q_=q.normalized();//这一步很重要，只有单位四元数才表示旋转矩阵
    Eigen::Matrix3d R =q_.toRotationMatrix();
    cout<<"Rotation_matrix_transpose\n"<<R.transpose()<<endl;

    Eigen::Matrix3d R_inv=R.inverse();
    cout<<"Rotation_matrix_inverse\n"<<R_inv<<endl;

    cout<<"R*R_tran=I?\n"<<R*R.transpose()<<endl;




 return 0;
}