���ܴ��ڵ�����
һ��linux�����г������⣬��ʾ��./tests: error while loading shared libraries: xxx.so.0:cannot open shared object file: No such file or directory

����ԭ��û���ҵ���̬���ӿ��·��

����취��

1. �ҵ�so��·������·����ӵ�/etc/ld.so.conf�ļ����һ�У���/usr/local/lib������֮�������У�/sbin/ldconfig �Cv����һ�����ü��ɡ�

2. export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH 



����-pthread����-lpthread������
