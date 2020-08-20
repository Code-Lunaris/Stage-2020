CC = g++

NDT_LIB_PATH = ./ndt_cpu/include
PCL_PATH = /usr/include/pcl-1.8
EIGEN_PATH = /usr/include/eigen3

LIB_FLAG = -I ${NDT_LIB_PATH}
LIB_FLAG += -I ${PCL_PATH}
LIB_FLAG += -I ${EIGEN_PATH}

LIBS = -L .
LIBS += -lndt_cpu
LIBS += -lboost_system
LIBS += -lpcl_apps -lpcl_common -lpcl_features -lpcl_filters -lpcl_io -lpcl_kdtree -lpcl_keypoints -lpcl_octree \
-lpcl_registration -lpcl_sample_consensus \
-lpcl_search -lpcl_segmentation -lpcl_surface -lpcl_visualization

LD = LD_LIBRARY_PATH=./ndt_cpu/include


all: eigen_test ndt_cpu_main

ndt_cpu_main.o : ndt_cpu_main.cpp
	${CC} ${LIB_FLAG} -c $<
	#${CC} -I ${LIB_PATH} -I ${PATSK_PATH} -c $^

ndt_cpu_main : ndt_cpu_main.o 
	${CC} -Wl,-rpath=./ndt_cpu -o $@ $^ ${LIBS}
	#LD_LIBRARY_PATH=./inc ${CC} -o $@ $^ ${LIBS} 

clean:
	rm -rf *.o