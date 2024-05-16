CC = g++ # Le compilateur
CFLAGS = -std=c++11 -Wall # Options du compilateur
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

# Les fichiers source
SRC =  fou.cpp pion.cpp cavalier.cpp reine.cpp cell.cpp playboard.cpp sfml_renderer.cpp jeu.cpp piece.cpp main.cpp

# Les fichiers objets
OBJ = $(SRC:.cpp=.o)

# Le nom de l'exécutable
EXEC = proj

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)