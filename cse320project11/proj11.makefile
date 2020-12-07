proj10: /user/cse320/Projects/project11.driver.o proj11.support.o
	gcc /user/cse320/Projects/project11.driver.o proj11.support.o -o proj11

proj11.support.o: proj11.support.s
	gcc -c proj11.support.s
