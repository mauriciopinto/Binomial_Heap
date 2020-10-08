CC=g++
CFLAGS=-g
ALLOBJ=main.o
DEPS=BNode.h BinomialHeap.h

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

BinomialHeap: $(ALLOBJ)
	$(CC) -o $@ $^ $(CFLAGS)
.PHONY: clean

clean:
	rm -f BinomialHeap
	rm -f $(ALLOBJ)
	rm -f bhgraph.jpeg
	rm -f graph.gv
