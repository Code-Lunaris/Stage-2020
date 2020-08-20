CC = nvcc

PCL_PATH = /usr/include/pcl-1.8
EIGEN_PATH = /usr/include/eigen3

LIB_FLAG += -I ${PCL_PATH}
LIB_FLAG += -I ${EIGEN_PATH}

LIBS = -lboost_system
LIBS += -lpcl_apps -lpcl_common -lpcl_features -lpcl_filters -lpcl_io -lpcl_kdtree -lpcl_keypoints -lpcl_octree \
-lpcl_registration -lpcl_sample_consensus \
-lpcl_search -lpcl_segmentation -lpcl_surface -lpcl_visualization




all: mon_programme

mon_programme.o : mon_programme.cu
	${CC} ${LIB_FLAG} -c $<

mon_programme : mon_programme.o 
	${CC} -o $@ $^ ${LIBS}

clean:
	rm -rf *.o