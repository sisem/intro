#!/bin/bash

make clean
pdflatex Recap_SW8.tex
pdflatex Recap_SW8.tex
pdflatex Recap_SW8.tex
pdflatex Recap_SW8.tex

read -p "Press any key..." -t 10