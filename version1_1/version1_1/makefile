all:
	latex main.tex
	bibtex main
	latex main.tex
	latex main.tex
	dvips -o main.ps main.dvi
	ps2pdf -sPAPERSIZE=letter -DMaxSubsetPct=100 -dCompatibilityLevel=1.4 -dPDFSETTINGS=/prepress -dSubsetFonts=true -dEmbedAllFonts=true main.ps main.pdf
clean:
	rm -f *.log *.dvi *.aux *.bbl *.blg *~
	
cleanall:
	rm -f *.log *.dvi *.aux *.bbl *.blg *~ main.pdf *.ps 
