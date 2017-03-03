# Authors : Anmol Sood , Kartikay Garg , Rahul Rathore
# Makefile for Assignment 3 : COP290 2014-2015

all:
	(cd src; qmake; make;)

host: all
	(cd src/bin; ./lobby $(port);)		

player: all
	(cd src/bin; ./lobby $(myport) $(hostport) $(hostip) $(myip))

.PHONY: clean 

clean:
	@rm -f out *.o  *.aux *.blg  *.bbl *.log *.ps *.dvi *.toc *.idx *.ind *.ilg *.br *.db;	
	(cd src; make clean;)
	
