proj10: /user/cse320/Projects/project10.driver.o proj10.support.o
	gcc /user/cse320/Projects/project10.driver.o proj10.support.o -o proj10

proj10.support.o: proj10.support.s
	gcc -c proj10.support.s
