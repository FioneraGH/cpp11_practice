CARCH=
CXX=g++ $(CARCH)
OBJECT=main.o test.o TypeClass.o

main : $(OBJECT)
	@echo Starting Generation ...
	$(CXX) -o main $(OBJECT)
	@echo End.

main.o : test.h TypeClass.h

include test.mk

include TypeClass.mk

.PHONY : clean
clean :
	-rm -f $(OBJECT) main
