.SUFFIXES:
.SUFFIXES: .cpp

GCC = g++
CFLAGS = -Wall -Wunused -std=c++11 -O2

# Diretório onde estão os arquivos .cpp
SRCDIR = src
BUILDDIR = build

# Obter a lista de arquivos .cpp no diretório SRCDIR
SOURCES = $(wildcard $(SRCDIR)/*.cpp)

# Obter a lista de objetos compilados (na pasta build)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Nome do executável
EXEC = my_program

$(EXEC): $(OBJS)
	$(GCC) $(CFLAGS) -o $@ $(OBJS) `pkg-config --cflags --libs opencv4`

# Regra para compilar um objeto a partir de um arquivo fonte
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(BUILDDIR)
	$(GCC) $(CFLAGS) -c $< -o $@ `pkg-config --cflags --libs opencv4`

clean:
	rm -f $(OBJS) $(EXEC)
