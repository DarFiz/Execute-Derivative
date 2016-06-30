Execute Derivative
================================

1. Opis 
******************************** 

Projekt "Execute Derivative" jest obliczenie w sposób symboliczny
pochodnych bardzo wysokiego rzędu iloczynów funkcji np. 

Poch(x)*Poch(x)*f()*f() = Poch(x)*(f(x)*f() + f()*f(x)) = 
f(x,x)*f() + 2*f(x)*f(x) + f()*f(x,x);

gdzie Poch(x) oznacza pochodną po "x", a f(x,x) oznacza 2-gą pochodną 
funkcji "f" po "x".

Celem projektu jest konfrontacja szybkosci obliczeń symbolicznych z 
analogicznymi obliczeniami w języku FORM (http://www.nikhef.nl/~form/)


2. Kompilacja 
******************************** 

Aby uruchomić wszystkie testy należy posiadać lokalnie wspomniany język
FORM opis instalacji http://www.nikhef.nl/~form/ .

