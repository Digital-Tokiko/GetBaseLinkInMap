//
// Created by mizu on 2026/10/2.
//

#include "GetBaseLink.h"

void GetBaseLink::tryLookup()
{
    try {
        auto tf_msg = tf_buffer_->lookupTransform(
            "map", "base_link", tf2::TimePointZero, tf2::durationFromSec(0.1));
        RCLCPP_INFO(this->get_logger(),
            "base_link in map: pos(%.4f, %.4f, %.4f)",
            tf_msg.transform.translation.x,
            tf_msg.transform.translation.y,
            tf_msg.transform.translation.z);
    } catch (const tf2::TransformException &ex) {
        RCLCPP_WARN(this->get_logger(),"lookup failed: %s", ex.what());
    }
}
