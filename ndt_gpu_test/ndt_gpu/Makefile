CC = nvcc

PCL_PATH = /usr/include/pcl-1.8
EIGEN_PATH = /usr/include/eigen3

LIB_FLAG += -I ${PCL_PATH}
LIB_FLAG += -I ${EIGEN_PATH}

LIBS += -lboost_system
LIBS += -lpcl_apps -lpcl_common -lpcl_features -lpcl_filters -lpcl_io -lpcl_kdtree -lpcl_keypoints -lpcl_octree \
-lpcl_registration -lpcl_sample_consensus \
-lpcl_search -lpcl_segmentation -lpcl_surface -lpcl_visualization

SRC_PATH = ./src
INC_PATH = ./include

NDT_GPU_LIB = libndt_gpu.a

OBJECTS = MatrixDevice.o
OBJECTS += MatrixHost.o
OBJECTS += NormalDistributionsTransform.o
OBJECTS += Registration.o
OBJECTS += SymmetricEigenSolver.o
OBJECTS += VoxelGrid.o

all: ${NDT_GPU_LIB}

%.o : ./src/%.cu
	${CC} ${LIB_FLAG}  -I ${INC_PATH} -c $<

${NDT_GPU_LIB}: ${OBJECTS}
	ar rs ${NDT_GPU_LIB} ${OBJECTS}

clean:
	rm -r *.o