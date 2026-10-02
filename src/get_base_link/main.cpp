//
// Created by mizu on 2026/10/2.
//

#include "GetBaseLink.h"

int main() {
    rclcpp::init(0, nullptr);

    auto receiver_node = std::make_shared<GetBaseLink>();

    rclcpp::spin(receiver_node);

    rclcpp::shutdown();
    return 0;
}