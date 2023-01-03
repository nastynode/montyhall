main:
	gcc main.c -o montyhall
run:
	echo "*** Running sim with 100 iterations ***"
	./montyhall 10000
clean:
	rm *.o montyhall