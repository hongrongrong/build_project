## Filename:      demo.makefile
## Author:        zbing.milesight
## Created at:    2016-04-22
##                
## Description:   临时测试demo
##               
## Copyright (C)  milesight
##                
######################################################################
#宏定义

#需要包含的目录
INCLUDE         := -D_GNU_SOURCE -D__USE_XOPEN\
					-I$(PUBLIC_INC_DIR)\
					-I$(PUBLIC_INC_DIR)/msdb \
                    -I$(PUBLIC_INC_DIR)/msstd


LDFLAGS         := -lstdc++ -lm -ldl -pthread \
                    -L$(PUBLIC_LIB_DIR)/ -lmsstd -lmsdb \
                    -L$(PUBLIC_STATIC_LIB_DIR)  \
                    -L$(STD_USRLIB_DIR) -lssl -lcrypto -lsqlite3


#目标类型("exe"-生成可执行文件 "so"-生成动态库 "a"-生成静态库)
TARGET_TYPE:="exe"

#导入通用mk文件
include $(BUILD_COMMON_MK)
