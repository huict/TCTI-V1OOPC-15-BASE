class animal {  };
void sell( animal & a ){}

class duck : public animal {  };
void fly( duck & d ){}

int main(){
   duck d; 

   fly( d );  // OK: duck required, duck provided
   sell( d ); // OK: animal required, duck provided

   animal a;
   sell( a ); // OK: animal required, animal provided
   // fly( a );  // ERROR: duck required, animal provided
   
   duck    * dp;
   animal  * ap;

   ap = & a; // OK: animal pointer required, animal pointer provided
   ap = & d; // OK: animal pointer required, duck pointer provided

   dp = & d; // OK: duck pointer required, duck pointer provided
   // dp = & a; // ERROR: duck pointer required, animal pointer provided
   
   animal & ar1 = a; // OK: animal reference refers to an animal
   animal & ar2 = d; // OK: animal reference refers to a duck

   duck & dr1 = d; // OK: duck reference refers to a duck
   // duck & dr2 = a; // ERROR: rerence can’t refer to a plain animal
}

