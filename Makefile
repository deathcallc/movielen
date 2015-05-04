MODEL_SPARSE_PATH = ./Model/SparseMatri
SERVICE_PATH = ./Service
CFG_PATH = ./Cfg
ENTITY_PATH = ./Entity

VPATH = $(MODEL_SPARSE_PATH):$(SERVICE_PATH):$(ENTITY_PATH)
OBJ = test.o Link.o Movie.o Rating.o SparseMatriOpt.o RatingReader.o Reader.o Pretreatment.o MovieReader.o

test : $(OBJ)
	g++ $(OBJ) -o test

test.o : test.cpp
	g++ -c test.cpp

Pretreatment.o : Pretreatment.cpp SparseMatriOpt.cpp
	g++ -c Pretreatment.cpp

DateInput.o : SparseMatriOpt.h SparseMatriOpt.cpp DateInput.cpp DateInput.h
	g++ -c $(SERVICE_PATH)/DateInput.cpp

SparseMatriOpt.o : SparseMatriOpt.cpp SparseMatriOpt.h
	g++ -c $(MODEL_SPARSE_PATH)/SparseMatriOpt.cpp

RatingReader.o : RatingReader.cpp RatingReader.h
	g++ -c $(SERVICE_PATH)/RatingReader.cpp

MovieReader.o : MovieReader.cpp MovieReader.h
	g++ -c $(SERVICE_PATH)/MovieReader.cpp

Reader.o : Reader.cpp Reader.h
	g++ -c $(SERVICE_PATH)/Reader.cpp

Rating.o : Rating.cpp Rating.h
	g++ -c $(ENTITY_PATH)/Rating.cpp

Link.o : Link.cpp Link.h
	g++ -c $(ENTITY_PATH)/Link.cpp

Movie.o : Movie.cpp Movie.h
	g++ -c $(ENTITY_PATH)/Movie.cpp

.PHONY : clean
clean :
	-rm test $(OBJ) 2> /dev/null