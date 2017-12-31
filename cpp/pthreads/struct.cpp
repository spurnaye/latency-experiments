#include <string>
#include <iostream>
struct Books {
 int x {0};
 char y {'y'};
};

int main(int argc, char * argv []){
   struct Books b1;
   std::cout << b1.x << std::endl;	
	return 0;
}
