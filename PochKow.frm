#define rzadpoch "2"

Function sigm,sigma,R,W;
CTensor siig ,RR,g;
Autodeclare Index L,U,a,b,w;
Symbol n;

Set Fun: R,sigma,sigm;
Set sig: sigm,sigma;


*rownanie na sigme 
Global EquationFromForm=1/2*sigma(Lx)*sigma(Lx);


*dzialamy pochodna kowariantna na powyzsze (dziala w lewa strone)
Multiply right W(L1,...,L'rzadpoch');

*wykonujemy jawnie pochodna 
repeat;
id W=1;
id R?Fun(?a)*W(a1?,?c)=(R(?a,a1)+W(a1)*R(?a))*W(?c);
endrepeat;
id W(?a)=0;


*id sigma(?aa) = siig(?aa);


print;

.store
save EquationFromForm.sav EquationFromForm;

.end
