#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <assert.h>


int main (int argc, char** argv){

   assert(argc>1); 

    pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_ndt_cloud (new pcl::PointCloud<pcl::PointXYZ>);

    pcl::PointCloud<pcl::PointXYZ>::Ptr autoware_ndt_cloud(new pcl::PointCloud<pcl::PointXYZ>);

    float *error_x;
    float *error_y;
    float *error_z;

    float average_error_x =0;
    float average_error_y =0;
    float average_error_z =0;

    float max_error_x =0;
    float max_error_y =0;
    float max_error_z =0;

    size_t pcl_cloud_size;
    size_t autoware_cloud_size;

    size_t array_size;

    if (pcl::io::loadPCDFile<pcl::PointXYZ> ("../ndt_pcl_cloud.pcd", *pcl_ndt_cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }

    if (pcl::io::loadPCDFile<pcl::PointXYZ> (argv[1], *autoware_ndt_cloud) == -1) //* load the file
    {
        PCL_ERROR ("Couldn't read file test_pcd.pcd \n");
        return (-1);
    }

    pcl_cloud_size = pcl_ndt_cloud->points.size();
    autoware_cloud_size = autoware_ndt_cloud->points.size();

    if(pcl_cloud_size != autoware_cloud_size)
        std::cout << "Cloud size are different" << std::endl << "pcl_cloud_size = " << pcl_cloud_size << std::endl << "autoware_cloud_size = " << autoware_cloud_size << std::endl;

    if(pcl_cloud_size>autoware_cloud_size)
        array_size = pcl_cloud_size;
    else 
        array_size = autoware_cloud_size;
     
    

    error_x = (float *) malloc(array_size*sizeof(pcl_ndt_cloud->points[0].x));
    error_y = (float *) malloc(array_size*sizeof(pcl_ndt_cloud->points[0].y));
    error_z = (float *) malloc(array_size*sizeof(pcl_ndt_cloud->points[0].z));
    assert(error_x != NULL && error_y != NULL && error_z != NULL);

    //calcul des erreurs
    //err = valeur_théorique-valeur_pratique/valeur_théorique
    for(int i=0; i< array_size; i++){
        error_x[i] = (pcl_ndt_cloud->points[i].x - autoware_ndt_cloud->points[i].x)/pcl_ndt_cloud->points[i].x;
        average_error_x += error_x[i];
        max_error_x = (max_error_x > error_x[i]) ? max_error_x : error_x[i];

        error_y[i] = (pcl_ndt_cloud->points[i].y - autoware_ndt_cloud->points[i].y)/pcl_ndt_cloud->points[i].y;
        average_error_y += error_y[i];
        max_error_y = (max_error_y > error_y[i]) ? max_error_y : error_y[i];

        error_z[i] = (pcl_ndt_cloud->points[i].z - autoware_ndt_cloud->points[i].z)/pcl_ndt_cloud->points[i].z;
        average_error_z += error_z[i];
        max_error_z = (max_error_z > error_z[i]) ? max_error_z : error_z[i];
    }

    average_error_x = average_error_x/array_size;
    average_error_y = average_error_y/array_size;
    average_error_z = average_error_z/array_size;

    std::cout << "average error x: " << average_error_x <<std::endl
    <<"average error y: " << average_error_y <<std::endl
    << "average error z: "<< average_error_z<<std::endl;

    std::cout << "max error x: " << max_error_x << std::endl
    << "max error y: " << max_error_y << std::endl
    << "max error z: " << max_error_z << std::endl;


  return 0;

}