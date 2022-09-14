build:
	g++ -Wall walsh.cpp -o walsh
	g++ -Wall statistics.cpp -o statistics
	g++ -Wall prinel.cpp -o prinel
	g++ -Wall crypto.cpp -o crypto

run-p1:      
	./walsh

run-p2:     
	./statistics

run-p3:     
	./prinel

run-p4:     
	./crypto

clean:		
	rm -rf walsh
	rm -rf statistics 
	rm -rf prinel 
	rm -rf crypto 
