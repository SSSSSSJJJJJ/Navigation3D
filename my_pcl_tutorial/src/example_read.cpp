#include <ros/ros.h>
// PCL specific includes
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <iostream>
using namespace::std;

int count_i=0;
void 
cloud_cb (const sensor_msgs::PointCloud2ConstPtr& output)
{
  // Create a container for the data.
  sensor_msgs::PointCloud2 output1;

  // Do data processing here...
  output1 = *output;

  // Publish the data.
  pcl::PointCloud<pcl::PointXYZ>::Ptr rabbit(new   pcl::PointCloud<pcl::PointXYZ>);
 
  pcl::fromROSMsg(*output,*rabbit);
  if(count_i==0)
  {
	  for(int i=0;i<rabbit->height*rabbit->width;i++)
		cout<<"     "<<rabbit->points[i].x<<" "
		<<rabbit->points[i].y<<" "
		<<rabbit->points[i].z<<" "<<endl;
  }
  count_i++;
}

int
main (int argc, char** argv)
{
  // Initialize ROS
  ros::init (argc, argv, "my_pcl_tutorial_read");
  ros::NodeHandle read_pcl;

  // Create a ROS subscriber for the input point cloud
  ros::Subscriber sub_read = read_pcl.subscribe ("output", 1, cloud_cb);

  // Spin
  ros::spin ();
}
