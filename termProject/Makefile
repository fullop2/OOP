CXX = g++

POLYOMINOS = Polyomino.o PolyominoSpecific.o  PolyominoFactory.o 
SYSTEMS = sys.o time.o Input.o View.o
BLOCKS = Block.o ColorSet.o BlockManager.o
GAME = Game.o stdafx.o ScoreManager.o
GAMESRC = Game.cpp stdafx.cpp ScoreManager.cpp
TEST = testcase.o

POLYDIR = ./Polyomino/
BLKDIR = ./Block/
SYSDIR = ./System/
TESTDIR = ./test/
DIRS = $(POLYDIR) $(BLKDIR) $(SYSDIR) $(TESTDIR)

MAIN = main.o $(GAME) $(addprefix $(BLKDIR), $(BLOCKS)) $(addprefix $(SYSDIR), $(SYSTEMS)) $(addprefix $(POLYDIR), $(POLYOMINOS)) $(addprefix $(TESTDIR), $(TEST))
TARGET = puyo

$(TARGET) : $(MAIN)
	$(game) $(objects)
	$(CXX) -o $@ $^

game:
	g++ -c $(GAMESRC)
objects:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d; \
	done
clean:
	@for d in $(DIRS); \
	do \
		$(MAKE) -C $$d clean; \
	done
	\rm -rf $(TARGET) $(GAME) main.o

