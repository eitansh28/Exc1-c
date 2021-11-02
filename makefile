#make all:all
all:libclassrec.a libclassrec.so libclassloops.so libclassloops.a mains maindloop maindrec

basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -c basicClassification.c

advancedClassificationLoop.o: NumClass.h advancedClassificationLoop.c
	gcc -Wall -g -c advancedClassificationLoop.c

advancedClassificationRecursion.o : NumClass.h advancedClassificationRecursion.c
	gcc -Wall -g -c advancedClassificationRecursion.c

main.o: main.c NumClass.h
	gcc -Wall -g -c main.c

loops: libclassloops.a
libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

recursives:libclassrec.a
libclassrec.a:  basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a  basicClassification.o advancedClassificationRecursion.o

recursived:libclassrec.so
libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	gcc -shared -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

loopd:libclassloops.so
libclassloops.so: basicClassification.o advancedClassificationLoop.o
		gcc -shared -o libclassloops.so basicClassification.o advancedClassificationLoop.o

#mains: mains
mains: main.o libclassrec.a
		gcc -Wall -o mains main.o libclassrec.a

#maindloop: maindloop
maindloop: main.o libclassloops.so
		gcc -Wall -o maindloop main.o ./libclassloops.so

#maindrec: maindrec
maindrec: main.o libclassrec.so
	gcc -Wall -o maindrec main.o ./libclassrec.so

.PHONY: clean all loops loopd recursived loopd recursives make mains make maindloop make maindrec

#make clean: clean
clean:
	rm -f *.o *.a *.so mains maindloop maindrec
