#define rzadpoch "19"

Function sigm,sigma,R,W;
CTensor siig ,RR,g;
Autodeclare Index L,U,a,b,w;
Symbol n;

Set Fun: R,sigma,sigm;
Set sig: sigm,sigma;


*rownanie na sigme 
Global F'rzadpoch'=2*sigma(Lx)*sigma(Lx);

*dzialamy pochodna kowariantna na powyzsze (dziala w lewa strone)
Multiply right W(L1,...,L8);

*wykonujemy jawnie pochodna 
repeat;
id W=1;
id R?Fun(?a)*W(a1?,?c)=(R(?a,a1)+W(a1)*R(?a))*W(?c);
endrepeat;
id W(?a)=0;
.sort


*dzialamy pochodna kowariantna na powyzsze (dziala w lewa strone)
Multiply right W(L9,...,L12);

*wykonujemy jawnie pochodna 
repeat;
id W=1;
id R?Fun(?a)*W(a1?,?c)=(R(?a,a1)+W(a1)*R(?a))*W(?c);
endrepeat;
id W(?a)=0;

.sort




*dzialamy pochodna kowariantna na powyzsze (dziala w lewa strone)
Multiply right W(L13,...,L15);

*wykonujemy jawnie pochodna 
repeat;
id W=1;
id R?Fun(?a)*W(a1?,?c)=(R(?a,a1)+W(a1)*R(?a))*W(?c);
endrepeat;
id W(?a)=0;

.sort


*dzialamy pochodna kowariantna na powyzsze (dziala w lewa strone)
Multiply right W(L16,...,L16);

*wykonujemy jawnie pochodna 
repeat;
id W=1;
id R?Fun(?a)*W(a1?,?c)=(R(?a,a1)+W(a1)*R(?a))*W(?c);
endrepeat;
id W(?a)=0;

.sort


*dzialamy pochodna kowariantna na powyzsze (dziala w lewa strone)
Multiply right W(L17,...,L17);

*wykonujemy jawnie pochodna 
repeat;
id W=1;
id R?Fun(?a)*W(a1?,?c)=(R(?a,a1)+W(a1)*R(?a))*W(?c);
endrepeat;
id W(?a)=0;

.sort


*dzialamy pochodna kowariantna na powyzsze (dziala w lewa strone)
Multiply right W(L18,...,L18);

*wykonujemy jawnie pochodna 
repeat;
id W=1;
id R?Fun(?a)*W(a1?,?c)=(R(?a,a1)+W(a1)*R(?a))*W(?c);
endrepeat;
id W(?a)=0;

.sort
*dzialamy pochodna kowariantna na powyzsze (dziala w lewa strone)
Multiply right W(L19,...,L'rzadpoch');

*wykonujemy jawnie pochodna 
repeat;
id W=1;
id R?Fun(?a)*W(a1?,?c)=(R(?a,a1)+W(a1)*R(?a))*W(?c);
endrepeat;
id W(?a)=0;




*id sigma(?aa) = siig(?aa);


*print;

.store

.end
