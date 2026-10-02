//
// Created by mizu on 2026/10/2.
//

#ifndef GET_BASE_LINK_GETBASELINK_H
#define GET_BASE_LINK_GETBASELINK_H

#include <rclcpp/rclcpp.hpp>
#include <tf2_ros/buffer.h>
#include <tf2/exceptions.h>
#include <tf2/time.h>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/transform_listener.h>

class GetBaseLink : public rclcpp::Node {
    std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
    std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

    rclcpp::TimerBase::SharedPtr timer_;

    public:
    GetBaseLink(): Node("GetBaseLink"),tf_buffer_(std::make_shared<tf2_ros::Buffer>(this->get_clock())),tf_listener_(std::make_shared<tf2_ros::TransformListener>(*tf_buffer_)) {
        timer_ = this->create_wall_timer(std::chrono::milliseconds(200),std::bind(&GetBaseLink::tryLookup, this));
    }

    void tryLookup();
};


#endif //GET_BASE_LINK_GETBASELINK_H
