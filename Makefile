CC = clang++
SOURCEDIR = src
BUILDDIR = build

# Includes util files AND OpenCL framework
COMMON = $(SOURCEDIR)/Common/Image.cpp $(SOURCEDIR)/Common/utils.cpp -framework OpenCL

SEQ_DIR = $(SOURCEDIR)/SequentialFiltering
PAR_DIR = $(SOURCEDIR)/ParallelFiltering

sequential:
	$(CC) -o $(BUILDDIR)/SequentialFiltering.out $(SEQ_DIR)/main.cpp $(COMMON)

parallel:
	$(CC) -o $(BUILDDIR)/ParallelFiltering.out $(PAR_DIR)/main.cpp $(PAR_DIR)/AccessCL.cpp $(PAR_DIR)/ImageFiltering.cpp $(COMMON)

sequential_opt:
	$(CC) -o $(BUILDDIR)/SequentialFilteringOpt.out $(SEQ_DIR)/main.cpp $(COMMON) -O1

parallel_opt:
	$(CC) -o $(BUILDDIR)/ParallelFilteringOpt.out $(PAR_DIR)/main.cpp $(PAR_DIR)/AccessCL.cpp $(PAR_DIR)/ImageFiltering.cpp $(COMMON) -O1

clean:
	rm -f $(BUILDDIR)/*.o $(BUILDDIR)/*.out $(BUILDDIR)/*.gch