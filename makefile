OBJS	= montador.o,analisador.o,erros.o,escritor.o,leitor.o,preprocessador.o,tabelas.o,simulador.o
OUT	= montador,simulador

OBJS0	= montador.o analisador.o erros.o escritor.o leitor.o preprocessador.o tabelas.o
SOURCE0	= montador.cpp analisador.cpp erros.cpp escritor.cpp leitor.cpp preprocessador.cpp tabelas.cpp
HEADER0	=
OUT0	= montador

OBJS1	= simulador.o preprocessador.o
SOURCE1	= simulador.cpp preprocessador.cpp
HEADER1	=
OUT1	= simulador

CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 =

all: montador simulador

montador: $(OBJS0) $(LFLAGS)
	$(CC) -g $(OBJS0) -o $(OUT0)

simulador: $(OBJS1) $(LFLAGS)
	$(CC) -g $(OBJS1) -o $(OUT1)

montador.o: montador.cpp
	$(CC) $(FLAGS) montador.cpp

analisador.o: analisador.cpp
	$(CC) $(FLAGS) analisador.cpp

erros.o: erros.cpp
	$(CC) $(FLAGS) erros.cpp

escritor.o: escritor.cpp
	$(CC) $(FLAGS) escritor.cpp

leitor.o: leitor.cpp
	$(CC) $(FLAGS) leitor.cpp

preprocessador.o: preprocessador.cpp
	$(CC) $(FLAGS) preprocessador.cpp

tabelas.o: tabelas.cpp
	$(CC) $(FLAGS) tabelas.cpp

simulador.o: simulador.cpp
	$(CC) $(FLAGS) simulador.cpp


clean:
	rm -f $(OBJS) $(OUT)