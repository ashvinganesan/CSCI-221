all: Problem_One Problem_Two Problem_Three Problem_Four

Problem_One:
	gcc Problem_One.c -o Problem_One

Problem_Two:
	gcc Problem_Two.c -o Problem_Two

Problem_Three:
	gcc Problem_Three.c -o Problem_Three

Problem_Four: Problem_Four.c 

clean:
	rm -f Problem_One Problem_Two Problem_Three Problem_Four
