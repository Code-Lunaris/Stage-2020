CC = nvcc

#LIB_PATH = ./lib
#LIB_PATH += /usr/include/eigen3P
#PATSK_PATH += /home/aurelie/Documents/ptask/src
NDT_LIB_PATH = ./ndt_gpu/include
PCL_PATH = /usr/include/pcl-1.8
EIGEN_PATH = /usr/include/eigen3

LIB_FLAG = -I ${NDT_LIB_PATH}
LIB_FLAG += -I ${PCL_PATH}
LIB_FLAG += -I ${EIGEN_PATH}

# LIBS = -L . 
# LIBS +=-l basic
# LIBS += -l ptask
# LIBS += -lboost_system
LIBS = -L .
LIBS += -lndt_gpu
LIBS += -lboost_system
LIBS += -lpcl_apps -lpcl_common -lpcl_features -lpcl_filters -lpcl_io -lpcl_kdtree -lpcl_keypoints -lpcl_octree \
-lpcl_registration -lpcl_sample_consensus \
-lpcl_search -lpcl_segmentation -lpcl_surface -lpcl_visualization




all: ndt_gpu_main

ndt_gpu_main.o : ndt_gpu_main.cu
	${CC} ${LIB_FLAG} -c $<
	#${CC} -I ${LIB_PATH} -I ${PATSK_PATH} -c $^

ndt_gpu_main : ndt_gpu_main.o 
	${CC} -o $@ $^ ${LIBS}
	#LD_LIBRARY_PATH=./inc ${CC} -o $@ $^ ${LIBS} 

clean:
	rm -rf *.o