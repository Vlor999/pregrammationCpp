# Compiler et options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude 

# Dossiers
OUT = out
SRC = src

# Fichiers sources et exécutables
SOURCES = $(wildcard $(SRC)/*.cpp)
OUTFILES = $(patsubst $(SRC)/%.cpp, $(OUT)/%, $(SOURCES))

# Cibles
all: run

$(OUT)/%: $(SRC)/%.cpp # Pour chaque fichier $(OUT)/nom, il faut $(SRC)/nom.cpp.
	mkdir -p $(OUT)
	$(CXX) $(CXXFLAGS) $< -o $@

	# $< représente le premier élément à droite ($(SRC)/nom.cpp).
	# $@ représente l'élément à gauche ($(OUT)/nom)

compile: $(OUTFILES)

run: compile
	@if [ -z "$(ARGS)" ]; then \
		echo "Erreur : Veuillez définir ARGS (ex: make run ARGS=firstEx)"; \
		exit 1; \
	fi
	./$(OUT)/$(ARGS)

help:
	@echo "Commandes disponibles :"
	@echo "  make compile   - Compile tous les fichiers sources"
	@echo "  make run ARGS=<executable> - Exécute le fichier compilé"
	@echo "  make clean     - Supprime les fichiers compilés"

clean:
	rm -rf $(OUT)
