可能存在的问题
一、linux上运行程序问题，提示：./tests: error while loading shared libraries: xxx.so.0:cannot open shared object file: No such file or directory

问题原因：没有找到动态连接库的路径

解决办法：

1. 找到so的路径，将路径添加到/etc/ld.so.conf文件最后一行，如/usr/local/lib，保存之后，再运行：/sbin/ldconfig –v更新一下配置即可。

2. export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH 



二、-pthread或者-lpthread的问题
