MODEL_SPARSE_PATH = ./Model/SparseMatri
SERVICE_PATH = ./Service
CFG_PATH = ./Cfg
ENTITY_PATH = ./Entity

VPATH = $(MODEL_SPARSE_PATH):$(SERVICE_PATH):$(ENTITY_PATH)
OBJ = test.o Link.o Movies.o Rating.o SparseMatriOpt.o RatingReader.o Reader.o

test : $(OBJ)
	g++ $(OBJ) -o test

test.o : test.cpp
	g++ -c test.cpp

DateInput.o : SparseMatriOpt.h SparseMatriOpt.cpp DateInput.cpp DateInput.h
	g++ -c $(SERVICE_PATH)/DateInput.cpp

SparseMatriOpt.o : SparseMatriOpt.cpp SparseMatriOpt.h
	g++ -c $(MODEL_SPARSE_PATH)/SparseMatriOpt.cpp

RatingReader.o : RatingReader.cpp RatingReader.h
	g++ -c $(SERVICE_PATH)/RatingReader.cpp

Reader.o : Reader.cpp Reader.h
	g++ -c $(SERVICE_PATH)/Reader.cpp

Rating.o : Rating.cpp Rating.h
	g++ -c $(ENTITY_PATH)/Rating.cpp

Link.o : Link.cpp Link.h
	g++ -c $(ENTITY_PATH)/Link.cpp

Movies.o : Movies.cpp Movies.h
	g++ -c $(ENTITY_PATH)/Movies.cpp

.PHONY : clean
clean :
	-rm test $(OBJ) 2> /dev/null
