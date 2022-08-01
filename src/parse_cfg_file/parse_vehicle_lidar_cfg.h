//
// The MIT License (MIT)
//
// Copyright (c) 2019 Livox. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#ifndef LIVOX_ROS_DRIVER_PARSE_VEHICLE_LIDAR_CFG_H_
#define LIVOX_ROS_DRIVER_PARSE_VEHICLE_LIDAR_CFG_H_

#include "timesync.h"
#include "../comm/comm.h"
#include "livox_def_vehicle.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/stringbuffer.h"

#include <stdio.h>
#include <string>
#include <vector>
#include <string.h>


namespace livox_ros {

typedef struct {
  std::string local_addr;
  uint8_t product_type;
} VehicleLidarOption;

class ParseVehicleLidarCfgFile {
 public:
  explicit ParseVehicleLidarCfgFile(const std::string& path);
  ~ParseVehicleLidarCfgFile() {}
  
  
  bool Parse(VehicleLidarOption& vehicle_lidar_option,
             std::vector<UserVehicleConfig>& raw_vehicle_config,
             std::vector<LidarRegisterInfo>& lidars_register_info,
             std::vector<LidarExtrinsicParameters>& lidar_extrins_params);
 private:
  const std::string path_;
};

} // namespace

#endif // LIVOX_ROS_DRIVER_PARSE_VEHICLE_LIDAR_CFG_H_
