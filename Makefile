CC = g++ # Le compilateur
CFLAGS = -std=c++11 -Wall # Options du compilateur
INCLUDE_DIRS = -I/opt/homebrew/Cellar/sfml/2.6.1/include # Chemin des fichiers d'en-tête
LIB_DIRS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib # Chemin des bibliothèques
LIBS=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio

# Les fichiers source
SRC =  fou.cpp pion.cpp cavalier.cpp reine.cpp tour.cpp cell.cpp playboard.cpp sfml_renderer.cpp jeu.cpp piece.cpp main.cpp

# Les fichiers objets
OBJ = $(SRC:.cpp=.o)

# Le nom de l'exécutable
EXEC = proj

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) $(LIB_DIRS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)