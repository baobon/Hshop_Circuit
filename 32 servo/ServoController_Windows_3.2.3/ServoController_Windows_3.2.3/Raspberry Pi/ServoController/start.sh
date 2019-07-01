#!/bin/bash
cur_dir=$(cd "$(dirname "$0")"; pwd)
export LD_LIBRARY_PATH=$cur_dir/lib
export QT_QPA_PLATFORM_PLUGIN_PATH=$cur_dir/lib
exec $cur_dir/share/ServoController
