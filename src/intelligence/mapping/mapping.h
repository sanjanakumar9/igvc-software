#ifndef MAPPING_H
#define MAPPING_H

#include "hardware/sensors/lidar/Lidar.h"
#include "common/events/Event.hpp"
#include <pcl/point_types.h>
#include <pcl/io/file_io.h>

class Mapping
{
public:
    Mapping(IGVC::Sensors::Lidar *lidar);
    ~Mapping();
    pcl::PointCloud<pcl::PointXYZ>::Ptr getCloud();
    //void saveCloud(std::string path);
    //bool readCloud(std::string path);
    Event<pcl::PointCloud<pcl::PointXYZ>::Ptr> onNewMap;
private:
    IGVC::Sensors::Lidar *_lidar;
    void OnLidarData(IGVC::Sensors::LidarState state);
    LISTENER(Mapping, OnLidarData, IGVC::Sensors::LidarState)
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
};

#endif // MAPPING_H